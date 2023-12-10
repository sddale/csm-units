#include <doctest/doctest.h>

#include <csm_units/concepts.hpp>
#include <source/csm_units/exponents.hpp>
// #include <csm_units/units.hpp>
#include <gcem.hpp>

#ifndef CSMUNITS_VALUE_TYPE
#define CSMUNITS_VALUE_TYPE double
#endif

namespace csm_units {

namespace concepts {

template <class T>
concept Ratio = requires {
  { T::num } -> std::convertible_to<int>;
  { T::den } -> std::convertible_to<int>;
};

template <class D>
concept Definition = requires {
  ExpType<typename D::dim>;
  Ratio<typename D::conv_len()>;
  Ratio<typename D::conv_mass>;
  Ratio<typename D::conv_time>;
  Ratio<typename D::conv_elec>;
  Ratio<typename D::conv_temper>;
  Ratio<typename D::conv_amount>;
  Ratio<typename D::conv_light>;
};

template <class T>
concept Unit = requires(T unit) {
  { unit.data } -> std::convertible_to<double>;
  { unit.Get() } -> std::convertible_to<double>;
  Definition<typename T::def>;
};

template <class T, class U>
concept SameDimAs = requires(T lhs, U rhs) {
  { std::same_as<typename T::def::dim, typename U::def::dim> };
};

}  // namespace concepts

namespace definition {

template <concepts::Definition Def, Arithmetic Data>
class Unit;

}

template <ExpType Dimension, concepts::Ratio ConvLen = std::ratio<1>,
          concepts::Ratio ConvMass = std::ratio<1>,
          concepts::Ratio ConvTime = std::ratio<1>,
          concepts::Ratio ConvElec = std::ratio<1>,
          concepts::Ratio ConvTemper = std::ratio<1>,
          concepts::Ratio ConvAmount = std::ratio<1>,
          concepts::Ratio ConvLight = std::ratio<1>>
class Definition {
 public:
  using dim = Dimension;
  using conv_len = ConvLen;
  using conv_mass = ConvMass;
  using conv_time = ConvTime;
  using conv_elec = ConvElec;
  using conv_temper = ConvTemper;
  using conv_amount = ConvAmount;
  using conv_light = ConvLight;

  constexpr static auto Get() {
    return Convert<conv_len, typename dim::L>().value *
           Convert<conv_mass, typename dim::M>().value *
           Convert<conv_time, typename dim::T>().value *
           Convert<conv_elec, typename dim::C>().value *
           Convert<conv_temper, typename dim::TP>().value *
           Convert<conv_amount, typename dim::A>().value *
           Convert<conv_light, typename dim::LM>().value;
  }
  constexpr static auto ToSI() {
    return InvConvert<conv_len, typename dim::L>().value *
           InvConvert<conv_mass, typename dim::M>().value *
           InvConvert<conv_time, typename dim::T>().value *
           InvConvert<conv_elec, typename dim::C>().value *
           InvConvert<conv_temper, typename dim::TP>().value *
           InvConvert<conv_amount, typename dim::A>().value *
           InvConvert<conv_light, typename dim::LM>().value;
  }

  constexpr friend auto operator*(Arithmetic auto lhs, Definition /*rhs*/) {
    return definition::Unit<Definition, decltype(lhs)>(lhs);
  }
  template <concepts::Definition D, Arithmetic Data>
  constexpr friend auto operator*(definition::Unit<D, Data> lhs,
                                  Definition /*rhs*/) {
    return definition::Unit<Multiply<D>, Data>(lhs.data);
  }
  constexpr friend auto operator/(Arithmetic auto lhs, Definition /*rhs*/) {
    return definition::Unit<InverseDef, decltype(lhs)>(lhs);
  }
  template <concepts::Definition D, Arithmetic Data>
  constexpr friend auto operator/(definition::Unit<D, Data> lhs,
                                  Definition /*rhs*/) {
    return definition::Unit<Divide<D>, Data>(lhs.data);
  }

  template <concepts::Ratio RL, concepts::Ratio RR>
  struct Selector {
    using val = RL;
  };

  template <concepts::Ratio RL>
  struct Selector<RL, std::ratio<1>> {
    using val = RL;
  };

  template <concepts::Ratio RR>
  struct Selector<std::ratio<1>, RR> {
    using val = RR;
  };

  template <>
  struct Selector<std::ratio<1>, std::ratio<1>> {
    using val = std::ratio<1>;
  };

  template <concepts::Definition A>
  using Multiply =
      Definition<ExponentsAdd<typename A::dim, dim>,
                 typename Selector<typename A::conv_len, conv_len>::val,
                 typename Selector<typename A::conv_mass, conv_mass>::val,
                 typename Selector<typename A::conv_time, conv_time>::val,
                 typename Selector<typename A::conv_elec, conv_elec>::val,
                 typename Selector<typename A::conv_temper, conv_temper>::val,
                 typename Selector<typename A::conv_amount, conv_amount>::val,
                 typename Selector<typename A::conv_light, conv_light>::val>;

  template <concepts::Definition A>
  using Divide =
      Definition<ExponentsSubtract<typename A::dim, dim>,
                 typename Selector<typename A::conv_len, conv_len>::val,
                 typename Selector<typename A::conv_mass, conv_mass>::val,
                 typename Selector<typename A::conv_time, conv_time>::val,
                 typename Selector<typename A::conv_elec, conv_elec>::val,
                 typename Selector<typename A::conv_temper, conv_temper>::val,
                 typename Selector<typename A::conv_amount, conv_amount>::val,
                 typename Selector<typename A::conv_light, conv_light>::val>;

  using InverseDef =
      Definition<ExponentsFlip<dim>, conv_len, conv_mass, conv_time, conv_elec,
                 conv_temper, conv_amount, conv_light>;

 private:
  template <concepts::Ratio R1, concepts::Ratio R2>
  struct Convert {
    constexpr static auto value =
        gcem::pow(static_cast<double>(R1::num) / R1::den,
                  static_cast<double>(R2::num) / R2::den);
  };

  template <concepts::Ratio R1, concepts::Ratio R2>
  using InvConvert = Convert<std::ratio<R1::den, R1::num>, R2>;
};

namespace definition {

template <concepts::Unit U, concepts::Ratio ZeroPoint>
class RelativeUnit : public U {
 public:
  constexpr explicit RelativeUnit(U::type data)
      : U(data + static_cast<U::type>(ZeroPoint::num) / ZeroPoint::den) {}

  [[nodiscard]] constexpr auto Get() const {
    return U::Get() - static_cast<U::type>(ZeroPoint::num) / ZeroPoint::den;
  }
  // [[nodiscard]] constexpr auto SI() const {
  //   return U::SI() + static_cast<U::type>(ZeroPoint::num) / ZeroPoint::den;
  // }
};

template <concepts::Definition Def, Arithmetic Data = CSMUNITS_VALUE_TYPE>
class Unit {
 public:
  using def = Def;
  using type = Data;

  constexpr explicit Unit(Data input) : data(input * def::ToSI()){};

  constexpr explicit(false) Unit(concepts::Unit auto input)
      : data(input.data) {}

  [[nodiscard]] constexpr auto Get() const { return data * Def::Get(); }
  [[nodiscard]] constexpr auto SI() const { return data; }

  Data data;  // magnitude in si

  template <concepts::SameDimAs<Unit> U>
  friend constexpr auto operator<=>(const Unit& lhs, const U& rhs) noexcept
      -> std::strong_ordering {
    return std::strong_order(lhs.data, rhs.data);
  }
  template <concepts::SameDimAs<Unit> U>
  friend constexpr auto operator==(const Unit& lhs, const U& rhs) noexcept
      -> bool {
    return lhs.data == rhs.data;
  }

  constexpr auto operator-=(const Unit& rhs) noexcept -> auto& {
    data -= rhs.data;
    return *this;
  }
  friend constexpr auto operator-(Unit lhs) noexcept {
    lhs.data = -1 * lhs.data;
    return lhs;
  }
  template <concepts::SameDimAs<Unit> U>
  friend constexpr auto operator-(U lhs, const U& rhs) noexcept {
    lhs -= rhs;
    return lhs;
  }

  constexpr auto operator+=(const Unit& rhs) noexcept -> auto& {
    data += rhs.data;
    return *this;
  }

  template <concepts::SameDimAs<Unit> U>
  friend constexpr auto operator+(U lhs, const U& rhs) noexcept {
    lhs += rhs;
    return lhs;
  }

  template <concepts::Ratio... Converters>
  friend constexpr auto operator*(
      Unit lhs,
      Unit<Definition<ExponentsFlip<typename def::dim>, Converters...>, Data>
          rhs) noexcept {
    return lhs.data * rhs.data;
  }
  template <concepts::Unit U>
  friend constexpr auto operator*(Unit lhs, const U& rhs) noexcept {
    return Unit<typename Unit::def::template Muliply<typename U::def>, Data>(
        lhs.data * rhs.data);
  }
  constexpr auto operator*=(Arithmetic auto rhs) noexcept -> auto& {
    data *= rhs;
    return *this;
  }
  friend constexpr auto operator*(Unit lhs, Arithmetic auto rhs) noexcept {
    lhs *= rhs;
    return lhs;
  }

  template <concepts::Ratio... Converters>
  friend constexpr auto operator/(
      Unit lhs,
      Unit<Definition<typename def::dim, Converters...>, Data> rhs) noexcept {
    return lhs.data / rhs.data;
  }
  template <concepts::Unit U>
  friend constexpr auto operator/(Unit lhs, const U& rhs) noexcept {
    return Unit<typename Unit::def::template Divide<typename U::def>, Data>(
        lhs.data / rhs.data);
  }
  constexpr auto operator/=(Arithmetic auto rhs) noexcept -> auto& {
    data /= rhs;
    return *this;
  }
  friend constexpr auto operator/(Unit lhs, Arithmetic auto rhs) noexcept {
    lhs /= rhs;
    return lhs;
  }
};

using Rankine =
    Definition<Exponents<0, 0, 0, 0, 1, 0, 0>, std::ratio<1>, std::ratio<1>,
               std::ratio<1>, std::ratio<1>, std::ratio<9, 5>>;

using SquareRankine =
    Definition<Exponents<0, 0, 0, 0, 2, 0, 0>, std::ratio<1>, std::ratio<1>,
               std::ratio<1>, std::ratio<1>, std::ratio<9, 5>>;

using Kelvin = Definition<Exponents<0, 0, 0, 0, 1, 0, 0>>;

}  // namespace definition

constexpr auto R =  // NOLINT(readability-identifier-length)
    definition::Rankine();

}  // namespace csm_units

namespace csm_units::test {

using Rankine = definition::Unit<definition::Rankine, double>;
using Kelvin = definition::Unit<definition::Kelvin, double>;
using Celsius = definition::RelativeUnit<Kelvin, std::ratio<5463, 20>>;
using Farenheit = definition::RelativeUnit<Rankine, std::ratio<45967, 100>>;

// NOLINTBEGIN(modernize-use-trailing-return-type, misc-use-anonymous-namespace)

TEST_SUITE("Conversion Operators") {
  TEST_CASE("Definition") {
    static_assert(std::is_same_v<definition::Unit<definition::Rankine, double>,
                                 decltype(1.0 * R)>);
    static_assert(
        std::is_same_v<definition::Unit<definition::SquareRankine, double>,
                       decltype(1.0 * R * R)>);
    static_assert(
        std::is_same_v<definition::Unit<definition::SquareRankine, double>,
                       decltype(Rankine(1.0) * R)>);
  }
}

TEST_SUITE("Unit") {
  TEST_CASE("Comparison") {
    static_assert(Rankine(100.) == Kelvin(100. * 5 / 9));
    static_assert(Rankine(100.) != Kelvin(101. * 5 / 9));
    static_assert(Rankine(100.) <= Kelvin(100. * 5 / 9));
    static_assert(not(Rankine(100.) <= Kelvin(99. * 5 / 9)));
    static_assert(Rankine(100.) < Kelvin(101. * 5 / 9));
    static_assert(not(Rankine(100.) < Kelvin(100. * 5 / 9)));
    static_assert(Rankine(100.) >= Kelvin(100. * 5 / 9));
    static_assert(Rankine(101.) >= Kelvin(100. * 5 / 9));
    static_assert(not(Rankine(99.) >= Kelvin(100. * 5 / 9)));
    static_assert(Rankine(101.) > Kelvin(100. * 5 / 9));
    static_assert(not(Rankine(100.) > Kelvin(100. * 5 / 9)));
  }
  TEST_CASE("Get() and .data") {
    static_assert(Rankine(100.).Get() == 100.);
    static_assert(Rankine(100.).data == Kelvin(100. * 5 / 9).data);
    static_assert(Rankine(100.).data == 100. * 5 / 9);
    static_assert(Kelvin(100.).Get() == Kelvin(100.).data);
  }
  TEST_CASE("Unary negative") {
    static_assert(-Rankine(100.) == -Kelvin(100. * 5 / 9));
  }
  TEST_CASE("Subtraction") {
    SUBCASE("Operator-=") {
      {
        auto val = Kelvin(100.);
        val -= Kelvin(99.);
        CHECK(val.Get() == Kelvin(1.).Get());
      }
      {
        auto val = Rankine(100.);
        val -= Rankine(99.);
        CHECK_EQ(val.data, doctest::Approx(1. * 5 / 9));
        CHECK(val.Get() == doctest::Approx(Kelvin(1.).Get()));
      }
    }
    SUBCASE("Binary operator-") {
      {
        const auto result = Kelvin(100.) - Kelvin(99);
        CHECK(result.Get() == Kelvin(1.).Get());
      }
      {
        const auto result = Rankine(100.) - Rankine(99);
        CHECK_EQ(result.data, doctest::Approx(1. * 5 / 9));
        CHECK(result.Get() == doctest::Approx(Kelvin(1.).Get()));
      }
    }
  }
  TEST_CASE("Addition") {
    SUBCASE("Operator+=") {
      {
        auto val = Kelvin(100.);
        val += Kelvin(99.);
        CHECK(val.Get() == Kelvin(199.).Get());
      }
      {
        auto val = Rankine(100.);
        val += Rankine(99.);
        CHECK_EQ(val.data, doctest::Approx(199. * 5 / 9));
        CHECK(val.Get() == doctest::Approx(Kelvin(199.).Get()));
      }
    }
    SUBCASE("Binary operator-") {
      {
        const auto result = Kelvin(100.) + Kelvin(99);
        CHECK(result.Get() == Kelvin(199.).Get());
      }
      {
        const auto result = Rankine(100.) + Rankine(99);
        CHECK_EQ(result.data, doctest::Approx(199. * 5 / 9));
        CHECK(result.Get() == doctest::Approx(Kelvin(199.).Get()));
      }
    }
  }
}
TEST_SUITE("Relative Unit") {
  TEST_CASE("Comparison") {
    static_assert(Farenheit(100.) == Rankine(100 + 459.67));
    static_assert(Farenheit(90.) != Rankine(100 + 459.67));
    static_assert(Farenheit(90.) < Rankine(100 + 459.67));
    static_assert(Farenheit(90.) <= Rankine(100 + 459.67));
    static_assert(Farenheit(101.) >= Rankine(100 + 459.67));
    static_assert(Farenheit(101.) > Rankine(100 + 459.67));
    CHECK_EQ(Farenheit(100).data, doctest::Approx(Celsius(37.7778).data));
    CHECK(Farenheit(101).data != doctest::Approx(Celsius(37.7778).data));
  }
  TEST_CASE("Get() and .data") {
    CHECK_EQ(Farenheit(100.).Get(), doctest::Approx(100));
    CHECK_EQ(Farenheit(100.).data, doctest::Approx(Celsius(37.7778).data));
    static_assert(Farenheit(100.).data == Rankine(100 + 459.67).data);
    CHECK_EQ(Farenheit(100.).data,
             doctest::Approx(Kelvin((100 - 32) * 5. / 9 + 273.15).Get()));
  }
  TEST_CASE("Unary operator-") {
    static_assert(-Farenheit(100.) == -Rankine(100 + 459.67));
  }
  TEST_CASE("Subtraction") {
    SUBCASE("Operator-=") {
      auto celsius = Celsius(5);
      celsius -= Celsius(3);
      CHECK_EQ(celsius.data, 2.);
      CHECK_EQ(celsius.Get(), Celsius(2 - 273.15).Get());

      auto farenheit = Farenheit(5);
      farenheit -= Farenheit(3);
      CHECK_EQ(farenheit.data, doctest::Approx(2. * 5 / 9));
      CHECK_EQ(farenheit.Get(), doctest::Approx(Farenheit(2 - 459.67).Get()));
    }
    SUBCASE("Binary operator-") {
      {
        const auto result = Celsius(5) - Celsius(3);
        CHECK_EQ(result.data, 2.);
        CHECK_EQ(result.Get(), Celsius(2 - 273.15).Get());
      }
      {
        const auto result = Farenheit(5) - Farenheit(3);
        CHECK_EQ(result.data, doctest::Approx(2. * 5 / 9));
        CHECK_EQ(result.Get(), doctest::Approx(Farenheit(2 - 459.67).Get()));
      }
    }
    // CHECK(farenheit.Get() == Farenheit(1.).Get());
  }
  TEST_CASE("Addition") {
    SUBCASE("Operator+=") {
      auto celsius = Celsius(5);
      celsius += Celsius(3);
      CHECK_EQ(celsius.data, 8 + 2 * 273.15);
      CHECK_EQ(celsius.Get(), Celsius(8 + 273.15).Get());

      auto farenheit = Farenheit(5);
      farenheit += Farenheit(3);
      CHECK_EQ(farenheit.data, doctest::Approx((8. + 2 * 459.67) * 5 / 9));
      CHECK_EQ(farenheit.Get(), doctest::Approx(Farenheit(8 + 459.67).Get()));
    }
    // SUBCASE("Binary operator+") {
    //   {
    //     const auto result = Celsius(5) - Celsius(3);
    //     CHECK_EQ(result.data, 2.);
    //     CHECK_EQ(result.Get(), Celsius(2 - 273.15).Get());
    //   }
    //   {
    //     const auto result = Farenheit(5) - Farenheit(3);
    //     CHECK_EQ(result.data, doctest::Approx(2. * 5 / 9));
    //     CHECK_EQ(result.Get(), doctest::Approx(Farenheit(2 - 459.67).Get()));
    //   }
    // }
    // CHECK(farenheit.Get() == Farenheit(1.).Get());
  }
}

// NOLINTEND(modernize-use-trailing-return-type, misc-use-anonymous-namespace)

}  // namespace csm_units::test