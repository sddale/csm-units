#pragma once

#include <ratio>
#include <utility>

#include "base.hpp"
#include "converter.hpp"
#include "dim_length.hpp"
#include "dim_mass.hpp"
#include "dim_time.hpp"

namespace csm_units {

// compound - compoud alias
// compound - base alias

template <class Length, int LengthPower, class Mass, int MassPower, class Time,
          int TimePower, Arithmetic Data>
class Derived;

namespace derived {

struct Factory {
  template <class Conv, class Ratio, Arithmetic Data>
  static auto Make(Base<DimLength, Conv, Ratio, Data>&& base) {
    return Derived<Base<DimLength, Conv, Ratio, Data>, 1, Base<DimMass>, 0,
                   Base<DimTime>, 0, Data>(std::forward<decltype(base)>(base));
  }

  template <class Conv, class Ratio, Arithmetic Data>
  static auto Make(Base<DimTime, Conv, Ratio, Data>&& base) {
    return Derived<Base<DimLength>, 0, Base<DimMass>, 0,
                   Base<DimTime, Conv, Ratio, Data>, 1, Data>(
        std::forward<decltype(base)>(base));
  }

  template <class Conv, class Ratio, Arithmetic Data>
  static auto Make(Base<DimMass, Conv, Ratio, Data>&& base) {
    return Derived<Base<DimLength>, 0, Base<DimMass, Conv, Ratio, Data>, 1,
                   Base<DimTime>, 0, Data>(std::forward<decltype(base)>(base));
  }
};

}  // namespace derived

template <class Length, int LengthPower, class Mass, int MassPower, class Time,
          int TimePower, Arithmetic Data>
class Derived {
 public:
  constexpr explicit Derived(Data value = 0) noexcept : data(value) {
    static_assert(LengthPower != 0 or MassPower != 0 or TimePower != 0,
                  "You defined all exponents equal to zero. Use an arithmetic "
                  "type instead");
  }

  // copy constructor
  constexpr Derived(const Derived& other) noexcept = default;

  // move constructor
  constexpr Derived(const Derived&& other) noexcept = default;

  Data data;

  // / operator overloads

  // compound / compound for two of the same derived
  friend constexpr auto operator/(Derived lhs, Derived rhs) noexcept {
    return lhs.data / rhs.data;
  }

  // compound / compound
  template <class Length2, int LengthPower2, class Mass2, int MassPower2,
            class Time2, int TimePower2>  // second object
  friend constexpr auto operator/(
      Derived lhs,
      Derived<Length2, LengthPower2, Mass2, MassPower2, Time2, TimePower2, Data>
          rhs) noexcept {
    return (Derived<Length, LengthPower - LengthPower2, Mass,
                    MassPower - MassPower2, Time, TimePower - TimePower2, Data>(
        lhs.data / rhs.data));
  }

  // compound / base
  friend constexpr auto operator/(Derived lhs, BaseType auto&& rhs) noexcept {
    return lhs / derived::Factory::Make(std::forward<decltype(rhs)>(rhs));
  }

  // base / compound
  friend constexpr auto operator/(BaseType auto&& lhs, Derived rhs) noexcept {
    return derived::Factory::Make(std::forward<decltype(lhs)>(lhs)) / rhs;
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
    return (Derived<Base<DimLength>, -LengthPower, Base<DimMass>, -MassPower,
                    Base<DimTime>, -TimePower, decltype(lhs)>(lhs / rhs.data));
  }

  // * operator overloads
  friend constexpr auto operator*(
      Derived lhs,
      Derived<Length, -LengthPower, Mass, -MassPower, Time, -TimePower, Data>
          rhs) noexcept {
    return lhs.data * rhs.data;
  }

  // compound * compound
  template <class Length2, int LengthPower2, class Mass2, int MassPower2,
            class Time2, int TimePower2>  // second object
  friend constexpr auto operator*(
      Derived lhs,
      Derived<Length2, LengthPower2, Mass2, MassPower2, Time2, TimePower2, Data>
          rhs) noexcept {
    return (Derived<Length, LengthPower + LengthPower2, Mass,
                    MassPower + MassPower2, Time, TimePower + TimePower2, Data>(
        lhs.data * rhs.data));
  }

  // compound * base
  friend constexpr auto operator*(Derived lhs, BaseType auto&& rhs) noexcept {
    return lhs * derived::Factory::Make(std::forward<decltype(rhs)>(rhs));
  }

  // base * compound
  friend constexpr auto operator*(BaseType auto&& lhs, Derived rhs) noexcept {
    return derived::Factory::Make(std::forward<decltype(lhs)>(lhs)) * rhs;
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
    lhs += derived::Factory::Make(std::forward<decltype(rhs)>(rhs));
    return lhs;
  }

  // base + compound (I guess a scenario where this happens is rare?)
  friend constexpr auto operator+(BaseType auto&& lhs, Derived rhs) noexcept {
    rhs += derived::Factory::Make(std::forward<decltype(lhs)>(
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
    lhs -= derived::Factory::Make(std::forward<decltype(rhs)>(rhs));
    return lhs;
  }

  // base - compound (I guess a scenario where this happens is rare?)
  // template <class... Ts>
  friend constexpr auto operator-(BaseType auto&& lhs, Derived rhs) noexcept {
    rhs.data *= -1;  // Is this okay to do? I thought it would save more space
                     // than casting lhs to derived then doing -=
    rhs += derived::Factory::Make(std::forward<decltype(lhs)>(lhs));
    return rhs;
  }
};

// base / base
constexpr auto operator/(BaseType auto&& lhs, BaseType auto&& rhs) noexcept {
  return derived::Factory::Make(std::forward<decltype(lhs)>(lhs)) /
         derived::Factory::Make(std::forward<decltype(rhs)>(rhs));
}

// base * base
constexpr auto operator*(BaseType auto&& lhs, BaseType auto&& rhs) noexcept {
  return derived::Factory::Make(std::forward<decltype(lhs)>(lhs)) *
         derived::Factory::Make(std::forward<decltype(rhs)>(rhs));
}

// Aliases for basic units
template <int LP, int MP, int TP>
using DBasic =
    Derived<Base<DimLength>, LP, Base<DimMass>, MP, Base<DimTime>, TP, double>;

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