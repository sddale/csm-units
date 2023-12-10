#include <doctest/doctest.h>

#include <csm_units/concepts.hpp>
#include <source/csm_units/definition.hpp>
#include <source/csm_units/exponents.hpp>
#include <source/csm_units/unit.hpp>
// #include <csm_units/units.hpp>
#include <gcem.hpp>

#ifndef CSMUNITS_VALUE_TYPE
#define CSMUNITS_VALUE_TYPE double
#endif

namespace csm_units::test {
using concepts::Arithmetic;
using concepts::ExpType;

namespace definition {
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

using Rankine = Unit<decltype(R), double>;
using Kelvin = Unit<definition::Kelvin, double>;
using Celsius = RelativeUnit<Kelvin, std::ratio<5463, 20>>;
using Farenheit = RelativeUnit<Rankine, std::ratio<45967, 100>>;

// NOLINTBEGIN(modernize-use-trailing-return-type, misc-use-anonymous-namespace)

TEST_SUITE("Conversion Operators") {
  TEST_CASE("Definition") {
    static_assert(
        std::is_same_v<Unit<definition::Rankine, double>, decltype(1.0 * R)>);
    static_assert(std::is_same_v<Unit<definition::SquareRankine, double>,
                                 decltype(1.0 * R * R)>);
    static_assert(std::is_same_v<Unit<definition::SquareRankine, double>,
                                 decltype(Rankine(1.0) * R)>);
  }
}

TEST_SUITE("Unit") {
  TEST_CASE("Size") {
    static_assert(sizeof(CSMUNITS_VALUE_TYPE) ==
                  sizeof(Unit<definition::Kelvin>));
    static_assert(sizeof(double) == sizeof(Unit<definition::Kelvin, double>));
    static_assert(sizeof(float) == sizeof(Unit<definition::Kelvin, float>));
    static_assert(sizeof(double) ==
                  sizeof(decltype(Unit<definition::Kelvin, double>() *
                                  Unit<definition::Kelvin, float>())));
    static_assert(sizeof(double) ==
                  sizeof(decltype(Unit<definition::Kelvin, float>() *
                                  Unit<definition::Kelvin, double>())));
    static_assert(sizeof(double) ==
                  sizeof(decltype(Unit<definition::Kelvin, double>() /
                                  Unit<definition::Kelvin, float>())));
    static_assert(sizeof(double) ==
                  sizeof(decltype(Unit<definition::Kelvin, float>() /
                                  Unit<definition::Kelvin, double>())));
  }
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
    SUBCASE("Binary operator+") {
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
  }
}

// NOLINTEND(modernize-use-trailing-return-type, misc-use-anonymous-namespace)

}  // namespace csm_units::test