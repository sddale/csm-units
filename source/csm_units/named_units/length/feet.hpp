#pragma once

#include "../../unit.hpp"
#include "../../unitcast.hpp"
#include "dimension.hpp"

namespace csm_units {

using Feet = Unit<Length, "ft", double>;

// Unit Cast for Base m to Unit ft
// Conversion Equation: 1 m = 3.28084 ft
template <>
[[nodiscard]] constexpr auto UnitCast(Length &&input) noexcept -> Feet {
  return Feet(input.data * 3.28084);
}

// Unit Cast for Unit ft to Base m
// Conversion Equation: 1 m = 3.28084 ft
template <>
[[nodiscard]] constexpr auto UnitCast(Feet &&input) noexcept -> Length {
  return Length(input.data / 3.28084);
}

constexpr auto operator""_ft(long double data) noexcept {
  return Feet(static_cast<double>(data));
}

}  // namespace csm_units