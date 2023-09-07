/**  \file foot.hpp
 *   \brief This file is used to define the unit Foot derived from the
 * base dimension for Length.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Foot_(unit)">Foot</a> if needed.
 */

#pragma once

#include "../../unit.hpp"
#include "../../unitcast.hpp"
#include "dimension.hpp"

namespace csm_units {

using Foot = Unit<Length, "ft", double>;

// Unit Cast for Base m to Unit ft
// Conversion Equation: 1 m = 3.28084 ft
template <>
[[nodiscard]] constexpr auto UnitCast(Length &&input) noexcept -> Foot {
  return Foot(input.data * 3.28084);
}

// Unit Cast for Unit ft to Base m
// Conversion Equation: 1 m = 3.28084 ft
template <>
[[nodiscard]] constexpr auto UnitCast(Foot &&input) noexcept -> Length {
  return Length(input.data / 3.28084);
}

namespace literals {

constexpr auto operator""_ft(long double data) noexcept {
  return Foot(static_cast<double>(data));
}

constexpr auto operator""_ft(unsigned long long data) noexcept {
  return Foot(static_cast<double>(data));
}

}  // namespace literals

}  // namespace csm_units