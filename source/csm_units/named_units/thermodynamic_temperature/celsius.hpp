/**  \file celsius.hpp
 *   \brief This file is used to define the unit Celsius derived from the base
 * dimension for Thermodynamic Temperature.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Celsius">Celsius</a> if needed.
 */

#pragma once

#include "../../unit.hpp"
#include "../../unitcast.hpp"
#include "dimension.hpp"

namespace csm_units {

using Celsius = Unit<Temperature, "degC", double>;

// Base K -> Unit C
template <>
[[nodiscard]] constexpr auto UnitCast(Temperature input) noexcept -> Celsius {
  return Celsius(input.data - 273.15);
}

// Unit C -> Base K
template <>
[[nodiscard]] constexpr auto UnitCast(Celsius input) noexcept -> Temperature {
  return Temperature(input.data + 273.15);
}

namespace literals {

constexpr auto operator""_degC(long double data) noexcept {
  return Celsius(static_cast<double>(data));
}

constexpr auto operator""_degC(unsigned long long data) noexcept {
  return Celsius(static_cast<double>(data));
}

}  // namespace literals

}  // namespace csm_units