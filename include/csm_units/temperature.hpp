#pragma once
#include <cmath>
#include <compare>
#include <cstddef>

namespace csm_units {

template <class Converter>
class Temperature {
 public:
  constexpr explicit Temperature(  // setting data to default value
      double temperature) noexcept
      : data(temperature) {}

  // copy constructor - keeps it the same
  constexpr Temperature(const Temperature &temp) noexcept : data(temp.data) {}

  // copy constructor - converts to Kelvin
  template <class OtherConverter>
  constexpr Temperature(const Temperature<OtherConverter> &temp) noexcept
      : data(Converter::ConvertValueFrom(
            OtherConverter::ConvertValue(temp.data))) {}

  // // move constructor
  // constexpr Temperature(Temperature &&temp) noexcept : data(temp.data) {
  //   temp.data = nullptr;
  // }

  // move constructor - converts to Kelvin
  // template <class OtherConverter>
  // constexpr Temperature(Temperature<OtherConverter> &&temp) noexcept
  //     : data(Converter::ConvertValueFrom(
  //           OtherConverter::ConvertValue(temp.data))) {
  //   temp.data = 0;
  // }

  constexpr auto operator==(double temp) const noexcept -> bool {
    return data == temp;
  }

  constexpr auto operator<=>(double temp) const noexcept {
    return data <=> temp;
  }

  template <class OtherConverter>
  constexpr auto operator==(
      const Temperature<OtherConverter> &temp) const noexcept -> bool {
    return Converter::ConvertValue(data) ==
           OtherConverter::ConvertValue(temp.data);
  }

  template <class OtherConverter>
  constexpr auto operator<=>(
      const Temperature<OtherConverter> &temp) const noexcept {
    return Converter::ConvertValue(data) <=>
           OtherConverter::ConvertValue(temp.data);
  }

  // copy assignment
  template <class OtherConverter>
  constexpr auto operator=(
      const Temperature<OtherConverter> &temp) const noexcept -> Temperature & {
    if (this == &temp) {
      return *this;
    }
    data = Converter::ConvertValueFrom(OtherConverter::ConvertValue(temp.data));

    return *this;
  }

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
// added comment

}  // namespace csm_units