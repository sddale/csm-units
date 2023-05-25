#pragma once

#include "../../unit.hpp"
#include "../../unitcast.hpp"
#include "dimension.hpp"

namespace csm_units {

using CentiMeter = Unit<Length, "cm", double>;

// Unit cast for Base m to Unit cm
// Conversion Equation: 1 m = 100 cm
template <>
[[nodiscard]] constexpr auto UnitCast(Length &&input) noexcept -> CentiMeter {
  return CentiMeter(input.data * 100);
}

// Unit Cast for Unit cm to Base m
// Conversion Equation: 1 m = 100 cm
template <>
[[nodiscard]] constexpr auto UnitCast(CentiMeter &&input) noexcept -> Length {
  return Length(input.data / 100);
}

}  // namespace csm_units