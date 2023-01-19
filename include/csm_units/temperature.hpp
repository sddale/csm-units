
#pragma once

namespace csm_units {

template <class Converter>
class Temperature : public Converter {
 public:
  //setting data to temperature, but had to convert it first using template and respective converter function
  constexpr explicit Temperature(double temperature) noexcept : data(Converter::ConvertValue(temperature)) {}
    
  double data;
};

class KelvinConverter {
  constexpr auto ConvertValue(double value) noexcept -> double {
    return value;  
  }
};

class CelsiusConverter {
  constexpr auto ConvertValue(double value) noexcept -> double { 
    return value + 273.15; }
};

//not in clang tidy yet - still have to figure out
class FahernheitConverter {
    constexpr auto ConvertValue(double value) noexcept -> double {
        return ((value - 32) / 1.8) + 273.15;
    }

};

using Kelvin = Temperature<KelvinConverter>;
using Celsius = Temperature<CelsiusConverter>;
using Fahrenheit = Temperature<FahernheitConverter>;

// ^ how does it know what that is? the using part

}  // namespace csm_units