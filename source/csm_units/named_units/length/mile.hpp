/**  \file mile.hpp
 *   \brief This file is used to define the unit Miles derived from the
 * base dimension for Length.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Mile">Miles</a> if needed.
 */

#pragma once

#include "../../unit.hpp"
#include "dimension.hpp"

namespace csm_units {

using Miles = Unit<Length, "miles">;

// Unit Cast for Base m to Unit miles
// Conversion Equation: 1609.34 m = 1 miles
template <>
[[nodiscard]] constexpr auto UnitCast(Length &&input) noexcept -> Miles {
  return Miles(input.data / 1609.34);
}

// Unit Cast for Unit miles to Base m
// Conversion Equation: 1609.34 m = 1 miles
template <>
[[nodiscard]] constexpr auto UnitCast(Miles &&input) noexcept -> Length {
  return Length(input.data * 1609.34);
}

namespace literals {

constexpr auto operator""_miles(long double data) noexcept {
  return Miles(static_cast<double>(data));
}

constexpr auto operator""_miles(unsigned long long data) noexcept {
  return Miles(static_cast<double>(data));
}

}  // namespace literals

}  // namespace csm_units