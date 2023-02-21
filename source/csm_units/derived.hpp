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
  Derived(Data value) : data(value) {}

  // copy constructor for derived of the same type
  constexpr Derived(const Derived& other) noexcept = default;

  // copy constructor for derived of different type -- not sure how to implement
  // this yet
  template <class... T>
  constexpr Derived(const Derived<T...>& other) noexcept : data(other.data) {}

  Data data;

  // not making member variables for now and seeing if I can access them from
  // template

  // // an attempt to templatizing the arguments - attempted around lines 63 but
  // // wrong approach just did a speed run so bad
  // struct {
  //   template <class Conv, class Ratio>
  //   Base<DimLength, Conv, Ratio> lengthValue;  // is this right?
  //   int length_power;
  // } Length;

  // class Mass {
  //  public:
  //   template <class Conv, class Ratio>
  //   Base<DimMass, Conv, Ratio> massValue;
  //   int mass_power;
  // }

  // class Time {
  //  public:
  //   template <class Conv, class Ratio>
  //   Base<DimTime, Conv, Ratio> timeValue;
  //   int time_power;
  // }

  // operator overload methods
  // have to convert data (to proper converter methods when actually dividing)

  // compound / compound
  template <class Length2, int LengthPower2, class Mass2, int MassPower2,
            class Time2, int TimePower2>  // second object
  // // so instead of line above, we can do using structs...
  // template <class Length, class Mass, class Time> // and now we can get both
  // the value and power from Length
  // // and the operator overload function would like
  // auto operator/(Derived<Length, Mass, Time> lhs, Derived<Length, Mass, Time>
  // rhs) { // oops figure out mistake yikes but good start)
  //   return Derived< // confused here hmmm - wrong approach
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
  constexpr auto operator/=(double rhs) noexcept -> auto& {
    data /= rhs;
    return *this;
  }

  // compound / double
  friend constexpr auto operator/(Derived lhs, double rhs) noexcept {
    lhs /= rhs;
    return lhs;
  }
};

// base / base
template <class... T1s, class... T2s>
constexpr auto operator/(Base<T1s...> lhs, Base<T2s...> rhs) noexcept {
  return derived::Factory::Make(lhs) / derived::Factory::Make(rhs);
}

}  // namespace csm_units