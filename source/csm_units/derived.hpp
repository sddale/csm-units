#pragma once

#include <csm_units/concepts.hpp>
#include <ratio>
#include <utility>

#include "base.hpp"
#include "converter.hpp"
#include "dim_length.hpp"
#include "dim_mass.hpp"
#include "dim_time.hpp"
#include "exponents.hpp"

namespace csm_units {

// compound - compoud alias
// compound - base alias

template <ExpType Powers, class Length, class Mass, class Time, Arithmetic Data>
class Derived;

namespace derived {

struct Factory {
  template <class Conv, class Ratio, Arithmetic Data>
  static auto Make(Base<DimLength, Conv, Ratio, Data>&& base) {
    return Derived<Exponents<1, 0, 0>, Base<DimLength, Conv, Ratio, Data>,
                   Base<DimMass>, Base<DimTime>, Data>(
        std::forward<decltype(base)>(base));
  }

  template <class Conv, class Ratio, Arithmetic Data>
  static auto Make(Base<DimTime, Conv, Ratio, Data>&& base) {
    return Derived<Exponents<0, 0, 1>, Base<DimLength>, Base<DimMass>,
                   Base<DimTime, Conv, Ratio, Data>, Data>(
        std::forward<decltype(base)>(base));
  }

  template <class Conv, class Ratio, Arithmetic Data>
  static auto Make(Base<DimMass, Conv, Ratio, Data>&& base) {
    return Derived<Exponents<0, 1, 0>, Base<DimLength>,
                   Base<DimMass, Conv, Ratio, Data>, Base<DimTime>, Data>(
        std::forward<decltype(base)>(base));
  }
  // template <class Conv, class Ratio, Arithmetic Data>
  // static auto Make(Base<DimLength, Conv, Ratio, Data>& base) {
  //   return Derived<Base<DimLength, Conv, Ratio, Data>, 1, Base<DimMass>, 0,
  //                  Base<DimTime>, 0,
  //                  Data>(std::forward<decltype(base)>(base));
  // }

  // template <class Conv, class Ratio, Arithmetic Data>
  // static auto Make(Base<DimTime, Conv, Ratio, Data>& base) {
  //   return Derived<Base<DimLength>, 0, Base<DimMass>, 0,
  //                  Base<DimTime, Conv, Ratio, Data>, 1, Data>(
  //       std::forward<decltype(base)>(base));
  // }

  // template <class Conv, class Ratio, Arithmetic Data>
  // static auto Make(Base<DimMass, Conv, Ratio, Data>& base) {
  //   return Derived<Base<DimLength>, 0, Base<DimMass, Conv, Ratio, Data>, 1,
  //                  Base<DimTime>, 0,
  //                  Data>(std::forward<decltype(base)>(base));
  // }
};

}  // namespace derived

template <ExpType Powers, class Length, class Mass, class Time, Arithmetic Data>
class Derived {
 public:
  constexpr explicit Derived(Data value = 0) noexcept : data(value) {
    static_assert(
        Powers::L::num != 0 or Powers::M::num != 0 or Powers::T::num != 0,
        "You defined all exponents equal to zero. Use an arithmetic "
        "type instead");
  }

  // copy constructor
  constexpr Derived(const Derived& other) noexcept = default;
  constexpr Derived(const BaseType auto& other) noexcept : data(other.data){};

  // move constructor
  constexpr Derived(Derived&& other) noexcept = default;

  // NOLINTBEGIN(bugprone-forwarding-reference-overload) Factory requires std
  // move
  constexpr Derived(BaseType auto&& other) noexcept
      : data(std::move(other.data)) {}
  // NOLINTEND(bugprone-forwarding-reference-overload)

  Data data;

  // quick stab at Flip member function
  constexpr auto Flip() noexcept {
    return Derived<ExponentsFlip<Powers>, Length, Mass, Time, Data>(
        std::move(1 / data));
  }

  // / operator overloads

  // compound / compound for two of the same derived
  friend constexpr auto operator/(Derived lhs, Derived rhs) noexcept {
    return lhs.data / rhs.data;
  }

  // compound / compound
  template <ExpType Powers2, class Length2, class Mass2,
            class Time2>  // second object
  friend constexpr auto operator/(
      Derived lhs, Derived<Powers2, Length2, Mass2, Time2, Data> rhs) noexcept {
    return (
        Derived<ExponentsSubtract<Powers, Powers2>, Length, Mass, Time, Data>(
            lhs.data / rhs.data));
  }

  // NOLINTBEGIN(bugprone-move-forwarding-reference) Factory requires std move
  //  compound / base
  friend constexpr auto operator/(Derived lhs, BaseType auto&& rhs) noexcept {
    return lhs / derived::Factory::Make(std::move(rhs));
  }

  // base / compound
  friend constexpr auto operator/(BaseType auto&& lhs, Derived rhs) noexcept {
    return derived::Factory::Make(std::move(lhs)) / rhs;
  }

  // compound /= double
  constexpr auto operator/=(Arithmetic auto rhs) noexcept -> auto& {
    data /= rhs;
    return *this;
  }

  // compound / double
  friend constexpr auto operator/(Derived lhs, Arithmetic auto rhs) noexcept {
    lhs /= rhs;
    return lhs;
  }

  // double / compound
  friend constexpr auto operator/(Arithmetic auto lhs, Derived rhs) noexcept {
    return (Derived<ExponentsFlip<Powers>, Base<DimLength>, Base<DimMass>,
                    Base<DimTime>, decltype(lhs)>(lhs / rhs.data));
  }

  // * operator overloads
  friend constexpr auto operator*(
      Derived lhs,
      Derived<ExponentsFlip<Powers>, Length, Mass, Time, Data> rhs) noexcept {
    return lhs.data * rhs.data;
  }

  // compound * compound
  template <ExpType Powers2, class Length2, class Mass2,
            class Time2>  // second object
  friend constexpr auto operator*(
      Derived lhs, Derived<Powers2, Length2, Mass2, Time2, Data> rhs) noexcept {
    return (Derived<ExponentsAdd<Powers, Powers2>, Length, Mass, Time, Data>(
        lhs.data * rhs.data));
  }

  // compound * base
  friend constexpr auto operator*(Derived lhs, BaseType auto&& rhs) noexcept {
    return lhs * derived::Factory::Make(std::move(rhs));
  }

  // base * compound
  friend constexpr auto operator*(BaseType auto&& lhs, Derived rhs) noexcept {
    return derived::Factory::Make(std::move(lhs)) * rhs;
  }

  // compoud *= double
  constexpr auto operator*=(Arithmetic auto rhs) noexcept -> auto& {
    data *= rhs;
    return *this;
  }

  // compound * double
  friend constexpr auto operator*(Derived lhs, Arithmetic auto rhs) noexcept {
    lhs *= rhs;
    return lhs;
  }

  // double * compound
  friend constexpr auto operator*(Arithmetic auto lhs, Derived rhs) noexcept {
    return (Derived(lhs * rhs.data));
  }
  // like that ^?

  // + operator overloads

  // REFACTOR ATTEMPT according to cppreference.com

  constexpr auto operator+=(const Derived& rhs) noexcept -> auto& {
    data += rhs.data;
    return *this;
  }

  // compound + compound
  friend constexpr auto operator+(Derived lhs, const Derived& rhs) noexcept {
    // return (Derived(lhs.data + rhs.data));  // what we had before
    // return (Derived(lhs.data += rhs.data));  // attempt not sure
    lhs += rhs;
    return lhs;
  }

  // compound + base (I guess a scenario where this happens is rare)
  friend constexpr auto operator+(Derived lhs, BaseType auto&& rhs) noexcept {
    lhs += derived::Factory::Make(std::move(rhs));
    return lhs;
  }

  // base + compound (I guess a scenario where this happens is rare?)
  friend constexpr auto operator+(BaseType auto&& lhs, Derived rhs) noexcept {
    rhs += derived::Factory::Make(std::move(
        lhs));  // Is this okay to do with rhs on the left side of the +=?
    return rhs;
  }

  // - operator overloads

  constexpr auto operator-=(const Derived& rhs) noexcept -> auto& {
    data -= rhs.data;
    return *this;
  }

  // compound - compound
  friend constexpr auto operator-(Derived lhs, const Derived& rhs) noexcept {
    lhs -= rhs;
    return lhs;
  }

  // compound - base (I guess a scenario where this happens is rare)
  friend constexpr auto operator-(Derived lhs, BaseType auto&& rhs) noexcept {
    lhs -= derived::Factory::Make(std::move(rhs));
    return lhs;
  }

  // base - compound (I guess a scenario where this happens is rare?)
  // template <class... Ts>
  friend constexpr auto operator-(BaseType auto&& lhs, Derived rhs) noexcept {
    rhs.data *= -1;  // Is this okay to do? I thought it would save more space
                     // than casting lhs to derived then doing -=
    rhs += derived::Factory::Make(std::move(lhs));
    return rhs;
  }
};

// base / base
constexpr auto operator/(BaseType auto&& lhs, BaseType auto&& rhs) noexcept {
  return derived::Factory::Make(std::move(lhs)) /
         derived::Factory::Make(std::move(rhs));
}

// base * base
constexpr auto operator*(BaseType auto&& lhs, BaseType auto&& rhs) noexcept {
  return derived::Factory::Make(std::move(lhs)) *
         derived::Factory::Make(std::move(rhs));
}

// NOLINTEND(bugprone-move-forwarding-reference)

// user defined literals - all we have as of now: rest play with prefixes and
// then more dimensions of course meter
constexpr auto operator""_m(long double data) noexcept {
  return Derived<Exponents<1, 0, 0>, Base<DimLength>, Base<DimMass>,
                 Base<DimTime>, double>(static_cast<double>(data));
}

// kilogram
constexpr auto operator""_kg(long double data) noexcept {
  return Derived<Exponents<0, 1, 0>, Base<DimLength>, Base<DimMass>,
                 Base<DimTime>, double>(static_cast<double>(data));
}

// second
constexpr auto operator""_s(long double data) noexcept {
  return Derived<Exponents<0, 0, 1>, Base<DimLength>, Base<DimMass>,
                 Base<DimTime>, double>(static_cast<double>(data));
}

// Aliases for basic units
template <int LP, int MP, int TP>
using DBasic = Derived<Exponents<LP, MP, TP>, Base<DimLength>, Base<DimMass>,
                       Base<DimTime>, double>;

using Meter = DBasic<1, 0, 0>;
using Seconds = DBasic<0, 0, 1>;
// using Kilograms =
//     Derived<Base<DimLength>, 0,
//             Base<DimMass, NoConverter, std::ratio<1000, 1>, double>, 1,
//             Base<DimTime>, 0, double>; // Kilograms can't be used like this
//             yet, because the test cases can't handle ratio yet
// using Mole = //cannot do this yet
// using Ampere = //cannot do this yet
// using Kelvin = //cannot do this yet
// using Candela = //cannot do this yet

}  // namespace csm_units