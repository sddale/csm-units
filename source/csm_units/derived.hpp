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
};

}  // namespace csm_units