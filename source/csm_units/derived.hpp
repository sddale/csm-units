#pragma once

#include <ratio>
#include <utility>

#include "Converter.hpp"
#include "DimLength.hpp"
#include "DimMass.hpp"
#include "DimTime.hpp"
#include "base.hpp"

namespace csm_units {

template <class Length, int LengthPower, class Mass, int MassPower, class Time,
          int TimePower, Arithmetic Data>
class Derived;

namespace derived {
struct Factory {
  template <class Conv, class Ratio, Arithmetic Data>
  static auto Make(Base<DimLength, Conv, Ratio, Data> base) {
    return Derived<Base<DimLength, Conv, Ratio, Data>, 1, Base<DimMass>, 0,
                   Base<DimTime>, 0, Data>(base.data);
  }

  template <class Conv, class Ratio, Arithmetic Data>
  static auto Make(Base<DimTime, Conv, Ratio, Data> base) {
    return Derived<Base<DimLength>, 0, Base<DimMass>, 0,
                   Base<DimTime, Conv, Ratio, Data>, 1, Data>(base.data);
  }

  template <class Conv, class Ratio, Arithmetic Data>
  static auto Make(Base<DimMass, Conv, Ratio, Data> base) {
    return Derived<Base<DimLength>, 0, Base<DimMass, Conv, Ratio, Data>, 1,
                   Base<DimTime>, 0, Data>(base.data);
  }
};
}  // namespace derived

template <class Length, int LengthPower, class Mass, int MassPower, class Time,
          int TimePower, Arithmetic Data>
class Derived {
 public:
  constexpr explicit Derived(Data value) noexcept : data(value) {}

  // copy constructor for derived of the same type
  constexpr Derived(const Derived& other) noexcept = default;

  Data data;

  // / operator overloads

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
  template <class... Ts>
  friend constexpr auto operator/(Derived lhs, Base<Ts...> rhs) noexcept {
    return lhs / derived::Factory::Make(rhs);
  }

  // base / compound
  template <class... Ts>
  friend constexpr auto operator/(Base<Ts...> lhs, Derived rhs) noexcept {
    return derived::Factory::Make(lhs) / rhs;
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
  template <class... Ts>
  friend constexpr auto operator*(Derived lhs, Base<Ts...> rhs) noexcept {
    return lhs * derived::Factory::Make(rhs);
  }

  // base * compound
  template <class... Ts>
  friend constexpr auto operator*(Base<Ts...> lhs, Derived rhs) noexcept {
    return derived::Factory::Make(lhs) * rhs;
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
    return (Derived<Base<DimLength>, LengthPower, Base<DimMass>, MassPower,
                    Base<DimTime>, TimePower, decltype(lhs)>(lhs * rhs.data));
  }
  // like that ^?

  // + operator overloads

  // compound + compound
  friend constexpr auto operator+(Derived lhs, Derived rhs) noexcept {
    return (Derived(lhs.data + rhs.data));
  }

  // compound + base (I guess a scenario where this happens is rare)
  template <class... Ts>
  friend constexpr auto operator+(Derived lhs, Base<Ts...> rhs) noexcept {
    return lhs + derived::Factory::Make(rhs);
  }

  // base + compound (I guess a scenario where this happens is rare?)
  template <class... Ts>
  friend constexpr auto operator+(Base<Ts...> lhs, Derived rhs) noexcept {
    return derived::Factory::Make(lhs) + rhs;
  }

  // compoud += double
  constexpr auto operator+=(Arithmetic auto rhs) noexcept -> auto& {
    data += rhs;
    return *this;
  }

  // compound + double
  friend constexpr auto operator+(Derived lhs, Arithmetic auto rhs) noexcept {
    lhs += rhs;
    return lhs;
  }

  // double + compound
  friend constexpr auto operator+(Arithmetic auto lhs, Derived rhs) noexcept {
    return (Derived(lhs + rhs.data));
  }

  // - operator overloads

  // compound - compound
  friend constexpr auto operator-(Derived lhs, Derived rhs) noexcept {
    return (Derived(lhs.data - rhs.data));
  }

  // compound + base (I guess a scenario where this happens is rare)
  template <class... Ts>
  friend constexpr auto operator-(Derived lhs, Base<Ts...> rhs) noexcept {
    return lhs - derived::Factory::Make(rhs);
  }

  // base + compound (I guess a scenario where this happens is rare?)
  template <class... Ts>
  friend constexpr auto operator+(Base<Ts...> lhs, Derived rhs) noexcept {
    return derived::Factory::Make(lhs) - rhs;
  }

  // compoud += double
  constexpr auto operator-=(Arithmetic auto rhs) noexcept -> auto& {
    data -= rhs;
    return *this;
  }

  // compound + double
  friend constexpr auto operator-(Derived lhs, Arithmetic auto rhs) noexcept {
    lhs -= rhs;
    return lhs;
  }

  // double + compound
  friend constexpr auto operator-(Arithmetic auto lhs, Derived rhs) noexcept {
    return (Derived(lhs - rhs.data));
  }
};

// base / base
template <class... T1s, class... T2s>
constexpr auto operator/(Base<T1s...> lhs, Base<T2s...> rhs) noexcept {
  return derived::Factory::Make(lhs) / derived::Factory::Make(rhs);
}

// base * base
template <class... T1s, class... T2s>
constexpr auto operator*(Base<T1s...> lhs, Base<T2s...> rhs) noexcept {
  return derived::Factory::Make(lhs) * derived::Factory::Make(rhs);
}

// base + base
template <class... T1s, class... T2s>
constexpr auto operator+(Base<T1s...> lhs, Base<T2s...> rhs) noexcept {
  return derived::Factory::Make(lhs) + derived::Factory::Make(rhs);
}

}  // namespace csm_units