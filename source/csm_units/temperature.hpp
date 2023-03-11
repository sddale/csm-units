#pragma once
#include "base.hpp"

namespace csm_units {

class DimTemperature {};

/*
// Converters to define relationship between various pressure units
class KelvinConverter {
 public:
  [[nodiscard]] constexpr static auto ToBase(double value) noexcept -> double {
    return value;
  }

  [[nodiscard]] constexpr static auto FromBase(double dataKelvin) noexcept
      -> double {
    return dataKelvin;
  }
};
*/ // *** Shouldn't need this anymore. Talk with Seth though before deleting ***

class CelsiusConverter {
 public:
  [[nodiscard]] constexpr static auto ToBase(double value) noexcept -> double {
    return value + 273.15;
  }

  [[nodiscard]] constexpr static auto FromBase(double dataKelvin) noexcept
      -> double {
    return dataKelvin - 273.15;
  }
};

class FahrenheitConverter {
 public:
  [[nodiscard]] constexpr static auto ToBase(double value) noexcept -> double {
    return (value - 32) / 1.8 + 273.15;
  }

  [[nodiscard]] constexpr static auto FromBase(double dataKelvin) noexcept
      -> double {
    return (dataKelvin - 273.15) * 1.8 + 32;
  }

  /*
  want to be able to define a variable like this: const auto temp = 330.0_K;

  friend constexpr auto operator""_K(long double) {
  }
  friend constexpr auto operator""_C(long double) {
  }
  friend constexpr auto operator""_F(long double) {
  }

  const auto kelvinTemp = 330.0_K;
  const auto fahTemp = 98.0_F;
  const auto celTemp = 32.0_C;
  */
};

}  // namespace csm_units