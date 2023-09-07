/**  \file yard.hpp
 *   \brief This file is used to define the unit Yards derived from the
 * base dimension for Length.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Yard">Yards</a> if needed.
 */

#pragma once

#include "../../unit.hpp"
#include "../../unitcast.hpp"
#include "dimension.hpp"

namespace csm_units {

using Yard = Unit<Length, "yd", double>;

// Unit Cast for Base m to Unit yard
// Conversion Equation: 1 m = 1.09361 yard
template <>
[[nodiscard]] constexpr auto UnitCast(Length &&input) noexcept -> Yard {
  return Yard(input.data * 1.09361);
}

// Unit Cast for Unit yard to Base m
// Conversion Equation: 1 m = 1.09361 yard
template <>
[[nodiscard]] constexpr auto UnitCast(Yard &&input) noexcept -> Length {
  return Length(input.data / 1.09361);
}

namespace literals {

constexpr auto operator""_yd(long double data) noexcept {
  return Yard(static_cast<double>(data));
}

constexpr auto operator""_yd(unsigned long long data) noexcept {
  return Yard(static_cast<double>(data));
}

}  // namespace literals

}  // namespace csm_units