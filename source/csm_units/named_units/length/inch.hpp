#pragma once

#include "../../unit.hpp"
#include "../../unitcast.hpp"
#include "dimension.hpp"

namespace csm_units {

using Inch = Unit<Length, "in", double>;

// Unit Cast for Base m to Unit in
// Conversion Equation: 1 m = 39.3701 in
template <>
[[nodiscard]] constexpr auto UnitCast(Length &&input) noexcept -> Inch {
  return Inch(input.data * 39.3701);
}

// Unit Cast for Unit in to Base m
// Conversion Equation: 1 m = 39.3701 in
template <>
[[nodiscard]] constexpr auto UnitCast(Inch &&input) noexcept -> Length {
  return Length(input.data / 39.3701);
}

}  // namespace csm_units