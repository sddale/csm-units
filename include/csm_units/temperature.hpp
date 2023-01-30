#pragma once
#include <cmath>
#include <compare>

namespace csm_units {

template <class Converter>
class Temperature {
 public:
  // setting data to temperature, but had to convert it first using template and
  // respective converter function
  constexpr explicit Temperature(
      double temperature) noexcept  // setting data to Kelvin
      : converter(), data(converter.ConvertValue(temperature)) {}





  // copy constructor hmmm... this is right but test being weird
  constexpr explicit Temperature(const Temperature &temp) noexcept
      : data(temp.data) {}






  constexpr auto Set(
      double value) noexcept {  // setting value to Kelvin as default - again??
    data = converter.ConvertValue(value);
  }

  [[nodiscard]] constexpr auto Value() const noexcept
      -> double {  // returning user original unit - F/C/K
    return converter.ConvertValueFrom(data);
  }

  [[nodiscard]] constexpr auto Data() const noexcept
      -> double {  // returning stored/converted data - Kelvin
    return data;
  }

  constexpr auto operator==(const Temperature &temp) const noexcept -> bool {
    return data == temp.Data();
  }

  constexpr auto operator<=>(const Temperature &temp) const noexcept {
    return data <=> temp.Data();
  }

 private:
  [[no_unique_address]] Converter converter;
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