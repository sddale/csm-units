/**  \file pascal.hpp
 *   \brief This file is used to define the Pressure SI unit Pascal.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Pascal_(unit)">Pascal</a> if needed.
 */

#pragma once

#include "../../unit.hpp"
#include "dimension.hpp"

namespace csm_units {

using Pascal = Unit<Pressure, "Pa", double>;

// Unit Cast for Base Pascals to Unit Pascals
// Conversion Equation: Pascals = Pascals
template <>
[[nodiscard]] constexpr auto UnitCast(Pressure input) noexcept -> Pascal {
  return Pascal(input.data);
}

// Unit Cast for Unit Pascals to Base Pascals
// Conversion Equation: Pascals = Pascals
template <>
[[nodiscard]] constexpr auto UnitCast(Pascal input) noexcept -> Pressure {
  return Pressure(input.data);
}

namespace literals {

constexpr auto operator""_Pa(long double data) noexcept {
  return Pascal(static_cast<double>(data));
}

constexpr auto operator""_Pa(unsigned long long data) noexcept {
  return Pascal(static_cast<double>(data));
}

}  // namespace literals

}  // namespace csm_units