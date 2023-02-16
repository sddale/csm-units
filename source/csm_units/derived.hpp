#pragma once

#include <ratio>

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
  // have to convert (to proper converter methods when actually dividing)

  template <class Length1, int LengthPower1, class Mass1, int MassPower1,
            class Time1, int TimePower1,  // first object
            class Length2, int LengthPower2, class Mass2, int MassPower2,
            class Time2, int TimePower2>  // second object
  auto operator/(
      Derived<Length1, LengthPower1, Mass1, MassPower1, Time1, TimePower1> lhs,
      Derived<Length2, LengthPower2, Mass2, MassPower2, Time2, TimePower2> rhs)
       return Derived<Length1, LengthPower1 - LengthPower2, Mass1,
                 MassPower1 - MassPower2, Time1, TimePower1 - TimePower2>(lhs.data / rhs.data);


  template <class Length1, int LengthPower1, class Mass1, int MassPower1,
          class Time1, int TimePower1, class T>
  auto operator/(
    Derived<Length1, LengthPower1, Mass1, MassPower1, Time1, TimePower1> lhs,  // understand this
    T rhs) {                                                                   // doing compound / base
  return lhs / DerivedFactory::MakeDerived(rhs); 
};

}  // namespace csm_units