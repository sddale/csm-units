/**  \file atm.hpp
 *   \brief This file is used to define the unit Atmosphere derived from the
 * base dimension for Pressure.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Standard_atmosphere_(unit)">Atmosphere</a>
 * if needed.
 */

#pragma once

#include "../../unit.hpp"
#include "dimension.hpp"

namespace csm_units {

using Atm = Unit<Pressure, "Atm", double>;

// Unit Cast for Base Pascals to Unit Atm
// Conversion Equation: 1 atm = 101,325 pascals
template <>
[[nodiscard]] constexpr auto UnitCast(Pressure input) noexcept -> Atm {
  return Atm(input.data / 101325);
}

// Unit Cast for Unit Bar to Base Pascals
// Conversion Equation: 1 bar = 101,325 pascals
template <>
[[nodiscard]] constexpr auto UnitCast(Atm input) noexcept -> Pressure {
  return Pressure(input.data * 101325);
}

namespace literals {

constexpr auto operator""_Atm(long double data) noexcept {
  return Atm(static_cast<double>(data));
}

constexpr auto operator""_Atm(unsigned long long data) noexcept {
  return Atm(static_cast<double>(data));
}

}  // namespace literals

}  // namespace csm_units