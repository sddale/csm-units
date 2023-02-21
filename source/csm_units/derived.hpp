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
          int TimePower, Arithmetic Data = double>
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

  struct DerivedFactory {
    template <class Conv, class Ratio>
    static auto MakeDerived(Base<DimLength, Conv, Ratio> base) {
      return Derived<Base<DimLength, Conv, Ratio>, 1, Base<DimMass>, 0,
                     Base<DimTime>, 0>(base.data);
    }

    template <class Conv, class Ratio>
    static auto MakeDerived(Base<DimTime, Conv, Ratio> base) {
      return Derived<Base<DimLength>, 0, Base<DimMass>, 0,
                     Base<DimTime, Conv, Ratio>, 1>(base.data);
    }

    template <class Conv, class Ratio>
    static auto MakeDerived(Base<DimMass, Conv, Ratio> base) {
      return Derived<Base<DimLength>, 0, Base<DimMass, Conv, Ratio>, 1,
                     Base<DimTime>, 0>(base.data);
    }
  };

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
      Derived<Length2, LengthPower2, Mass2, MassPower2, Time2, TimePower2>
          rhs) noexcept {
    return (Derived<Length, LengthPower - LengthPower2, Mass,
                    MassPower - MassPower2, Time, TimePower - TimePower2>(
        lhs.data / rhs.data));
  }

  // compound / base
  template <class... Ts>
  friend constexpr auto operator/(Derived lhs, Base<Ts...> rhs) noexcept {
    return lhs / DerivedFactory::MakeDerived(rhs);
  }

  // base / compound
  template <class... Ts>  // don't think we have to define template again
  friend constexpr auto operator/(Base<Ts...> lhs, Derived rhs) noexcept {
    return DerivedFactory::MakeDerived(lhs) / rhs;
  }

  // base / base ?
};
}  // namespace csm_units