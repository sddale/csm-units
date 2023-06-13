#pragma once

#include "../../unit.hpp"
#include "../../unitcast.hpp"
#include "dimension.hpp"

namespace csm_units {

using Celsius = Unit<Temperature, "degC", double>;

// Base K -> Unit C
template <>
[[nodiscard]] constexpr auto UnitCast(Temperature &&input) noexcept -> Celsius {
  return Celsius(input.data - 273.15);
}

// Unit C -> Base K
template <>
[[nodiscard]] constexpr auto UnitCast(Celsius &&input) noexcept -> Temperature {
  return Temperature(input.data + 273.15);
}

constexpr auto operator""_degC(long double data) noexcept {
  return Celsius(static_cast<double>(data));
}

}  // namespace csm_units