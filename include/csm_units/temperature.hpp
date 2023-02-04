#pragma once
#include <cmath>
#include <compare>

namespace csm_units {

template <class Converter>
class Temperature {
 public:
  constexpr explicit Temperature(  // setting data to default value
      double temperature) noexcept
      : data(temperature), converter() {}

  // copy constructor
  constexpr explicit Temperature(const Temperature &temp) noexcept
      : data(temp.data) {}

  // other copy constructor
  template <class OtherConverter>
  constexpr explicit Temperature(
      const Temperature<OtherConverter> &temp) noexcept
      : data(converter.ConvertValueFrom(
            OtherConverter::ConvertValue(temp.data))) {}

  constexpr auto operator==(const Temperature &temp) const noexcept -> bool {
    return data == temp.data;
  }

  template <class OtherConverter>
  constexpr auto operator==(
      const Temperature<OtherConverter> &temp) const noexcept -> bool {
    return converter.ConvertValue(data) ==
           OtherConverter::ConvertValue(temp.data);
  }

  template <class OtherConverter>
  constexpr auto operator<=>(
      const Temperature<OtherConverter> &temp) const noexcept {
    return converter.ConvertValue(data) <=>
           OtherConverter::ConvertValue(temp.data);
  }

  double data;

 private:
  [[no_unique_address]] Converter
      converter;  // Performance compared to references to static i.e.
                  // converter.Convert vs. Converter::Convert ?
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
// added comment

}  // namespace csm_units