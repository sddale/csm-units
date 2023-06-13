#pragma once

#include "../../unit.hpp"
#include "../../unitcast.hpp"
#include "dimension.hpp"

namespace csm_units {

using Miles = Unit<Length, "miles", double>;

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

constexpr auto operator""_miles(long double data) noexcept {
  return Miles(static_cast<double>(data));
}

}  // namespace csm_units