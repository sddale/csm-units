/**  \file fahrenheit.hpp
 *   \brief This file is used to define the unit Fahrenheit derived from the
 * base dimension for Thermodynamic Temperature.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Fahrenheit">Fahrenheit</a> if needed.
 */

#pragma once

#include "../../unit.hpp"
#include "dimension.hpp"

namespace csm_units {

using Fahrenheit = Unit<Temperature, "degF">;

// Unit Cast for Base K to Unit F
template <>
[[nodiscard]] constexpr auto UnitCast(Temperature &&input) noexcept
    -> Fahrenheit {
  return Fahrenheit((input.data - 273.15) * 1.8 + 32);
}

// Unit Cast for Unit F to Base K
template <>
[[nodiscard]] constexpr auto UnitCast(Fahrenheit &&input) noexcept
    -> Temperature {
  return Temperature((input.data - 32) * 5 / 9 + 273.15);
}

namespace literals {

constexpr auto operator""_degF(long double data) noexcept {
  return Fahrenheit(static_cast<double>(data));
}

constexpr auto operator""_degF(unsigned long long data) noexcept {
  return Fahrenheit(static_cast<double>(data));
}

}  // namespace literals

}  // namespace csm_units