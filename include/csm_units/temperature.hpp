#pragma once
#include <cmath>

namespace csm_units {

template <class Converter>
class Temperature {
 public:
  // setting data to temperature, but had to convert it first using template and
  // respective converter function
  constexpr explicit Temperature(double temperature) noexcept
      : converter(), data(converter.ConvertValue(temperature)) {}

  [[no_unique_address]] Converter converter;
  double data;
};

class KelvinConverter {
 public:
  constexpr static auto ConvertValue(double value) noexcept -> double {
    return value;
  }
};

class CelsiusConverter {
 public:
  constexpr static auto ConvertValue(double value) noexcept -> double {
    value = value + 273.15;
    return value;
  }
};

class FahrenheitConverter {
 public:
  constexpr static auto ConvertValue(double value) noexcept -> double {
    value = (value - 32) / 1.8 + 273.15;
    return value;
  }
};

using Kelvin = Temperature<KelvinConverter>;
using Celsius = Temperature<CelsiusConverter>;
using Fahrenheit = Temperature<FahrenheitConverter>;

}  // namespace csm_units