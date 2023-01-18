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
  // how do we represent a kelvin such that we can easily convert units
  auto ConvertValue(double value) -> double {
    return value;  // Do nothing
  }
};

class CelsiusConverter {
  // how do we represent a kelvin such that we can easily convert units
  auto ConvertValue(double value) -> double { return value + 273.15; }
};

using Kelvin = Temperature<KelvinConverter>;
using Celsius = Temperature<CelsiusConverter>;

}  // namespace csm_units