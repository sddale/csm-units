#pragma once

namespace csm_units {

template <class Converter>
class Temperature : public Converter {
 public:
  constexpr explicit Temperature(double temperature) noexcept
      : data(Converter::ConvertValue(temperature)) {}

  double data;
};

class KelvinConverter {
  auto ConvertValue(double value) -> double {
    return value;  
  }
};

class CelsiusConverter {
  auto ConvertValue(double value) -> double { return value + 273.15; }
};

class FahernheitConverter {
    auto ConvertValue(double value) -> double {
        return ((value - 32) / 1.8) + 273.15;
    }

};

using Kelvin = Temperature<KelvinConverter>;
using Celsius = Temperature<CelsiusConverter>;
using Fahrenheit = Temperature<FahernheitConverter>;

// ^ how does it know what that is? the using part

}  // namespace csm_units