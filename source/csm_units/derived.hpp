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
  Derived(double in) : data(in) {}
  Data data;
  // not making member variables for now and seeing if I can access them from
  // template

  // an attempt to templatizing the arguments - attempted around lines 63 but
  // wrong approach just did a speed run so bad
  class Length {
   public:
    Base<DimLength, Conv, Ratio> length_value;  // is this right?
    int length_power;
  }

  class Mass {
   public:
    Base<DimMass, Conv, Ratio> mass_value;
    int mass_power;
  }

  class Time {
   public:
    Base<DimTime, Conv, Ratio> time_value;
    int time_power;
  }

  template <class Conv, class Ratio>
  static auto MakeDerived(Base<DimLength, Conv, Ratio> base) {
    return Derived<Base<DimLength, Conv, Ratio>, 1,
                   Base<DimMass, NoConverter, std::ratio<1, 1>>, 0,
                   Base<DimTime, NoConverter, std::ratio<1, 1>>, 0>(base.data);
  }

  template <class Conv, class Ratio>
  static auto MakeDerived(Base<DimTime, Conv, Ratio> base) {
    return Derived<Base<DimLength, NoConverter, std::ratio<1, 1>>, 0,
                   Base<DimMass, NoConverter, std::ratio<1, 1>>, 0,
                   Base<DimTime, Conv, Ratio>, 1>(base.data);
  }

  template <class Conv, class Ratio>
  static auto MakeDerived(Base<DimMass, Conv, Ratio> base) {
    return Derived<Base<DimLength, NoConverter, std::ratio<1, 1>>, 0,
                   Base<DimMass, Conv, Ratio>, 1,
                   Base<DimTime, NoConverter, std::ratio<1, 1>>, 0>(base.data);
  }

  // operator overload methods
  // have to convert data (to proper converter methods when actually dividing)

  // compound / compound
  template <class Length1, int LengthPower1, class Mass1, int MassPower1,
            class Time1, int TimePower1,  // first object
            class Length2, int LengthPower2, class Mass2, int MassPower2,
            class Time2, int TimePower2>  // second object
  // // so instead of line above, we can do using structs...
  // template <class Length, class Mass, class Time> // and now we can get both
  // the value and power from Length
  // // and the operator overload function would like
  // auto operator/(Derived<Length, Mass, Time> lhs, Derived<Length, Mass, Time>
  // rhs) { // oops figure out mistake yikes but good start)
  //   return Derived< // confused here hmmm - wrong approach

  auto operator/(
      Derived<Length1, LengthPower1, Mass1, MassPower1, Time1, TimePower1> lhs,
      Derived<Length2, LengthPower2, Mass2, MassPower2, Time2, TimePower2>
          rhs) {
    return Derived<Length1, LengthPower1 - LengthPower2, Mass1,
                   MassPower1 - MassPower2, Time1,
                   TimePower1 - TimePower2>(lhs.data /
                                            rhs.data);  // still have to do
  }

  // compound / base
  template <class Length1, int LengthPower1, class Mass1, int MassPower1,
            class Time1, int TimePower1, class T>
  auto operator/(
      Derived<Length1, LengthPower1, Mass1, MassPower1, Time1, TimePower1> lhs,
      T rhs) {
    return lhs / DerivedFactory::MakeDerived(rhs);  // still have to do
  }

  // base / compound
 template <class Length1, int LengthPower1, class Mass1, int MassPower1,
            class Time1, int TimePower1, class T> // don't think we have to define template again
  auto operator/(
      T lhs,
      Derived<Length1, LengthPower1, Mass1, MassPower1, Time1, TimePower1>
          rhs) {
    return DerivedFactory::MakeDerived(lhs) / rhs;  // still have to do
  }

  // base / base ?
};
}  // namespace csm_units