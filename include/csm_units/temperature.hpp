
#pragma once
#include <iostream>
#include <cmath>

namespace csm_units {

template <class Converter>
class Temperature : public Converter {
 public:
  //setting data to temperature, but had to convert it first using template and respective converter function
  constexpr explicit Temperature(double temperature) noexcept : data(Converter::ConvertValue(temperature)) {}
    
  double data;
};

class KelvinConverter {
  public:
  constexpr auto ConvertValue(double value) noexcept -> double {
    
    return value;  
  }
};

class CelsiusConverter {
  public:
  constexpr auto ConvertValue(double value) noexcept -> double { 
    value = value + 273.15;                   // actual calculation
    value = (int)(value * 1000.0) / 1000.0;   // rounding to 3 decimal places
    
    return value;
    }
};

//not in clang tidy yet - still have to figure out
class FahrenheitConverter {
  public:
    constexpr auto ConvertValue(double value) noexcept -> double {
        value = (value - 32) / 1.8 + 273.15;      // actual calculation
        value = (int)(value * 1000.0) / 1000.0;   // rounding to 3 decimal places
        
        return value;
    }

};

using Kelvin = Temperature<KelvinConverter>;
using Celsius = Temperature<CelsiusConverter>;
using Fahrenheit = Temperature<FahrenheitConverter>;

// ^ how does it know what that is? the using part

}  // namespace csm_units