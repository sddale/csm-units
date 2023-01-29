#pragma once
#include <cmath>

namespace csm_units {

template <class Converter>
class Temperature {
 public:
  // setting data to temperature, but had to convert it first using template and
  // respective converter function
  constexpr explicit Temperature(
      double temperature) noexcept  // setting data to Kelvin
      : converter(), data(converter.ConvertValue(temperature)) {}

  constexpr auto Set(
      double value) noexcept {  // setting value to Kelvin as default - again??
    data = converter.ConvertValue(value);
  }

  constexpr auto Value() const noexcept
      -> double {  // returning user original unit - F/C/K
    return converter.ConvertValueFrom(data);
  }

  constexpr auto Data() const noexcept
      -> double {  // returning stored/converted data - Kelvin
    return data;
  }

  //[[no_unique_address]] Converter converter;
 private:
  Converter converter;
  double data;
};

class KelvinConverter {
 public:
  constexpr static auto ConvertValue(double value) noexcept -> double {
    return value;
  }

  constexpr static auto ConvertValueFrom(double dataKelvin) noexcept -> double {
    return dataKelvin;
  }
};

class CelsiusConverter {
 public:
  constexpr static auto ConvertValue(double value) noexcept -> double {
    return value + 273.15;
  }

  constexpr static auto ConvertValueFrom(double dataKelvin) noexcept -> double {
    return dataKelvin - 273.15;
  }
};

class FahrenheitConverter {
 public:
  constexpr static auto ConvertValue(double value) noexcept -> double {
    return (value - 32) / 1.8 + 273.15;
  }

  constexpr static auto ConvertValueFrom(double dataKelvin) noexcept -> double {
    return (dataKelvin - 273.15) * 1.8 + 32;
  }
};

using Kelvin = Temperature<KelvinConverter>;
using Celsius = Temperature<CelsiusConverter>;
using Fahrenheit = Temperature<FahrenheitConverter>;

}  // namespace csm_units