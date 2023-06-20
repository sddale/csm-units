#pragma once

#include "../../unit.hpp"
#include "../../unitcast.hpp"
#include "dimension.hpp"

namespace csm_units {

using MilliMeter = Unit<Length, "mm", double>;

// Unit cast for Base m to Unit mm
// Conversion Equation: 1 m = 1000 mm
template <>
[[nodiscard]] constexpr auto UnitCast(Length &&input) noexcept -> MilliMeter {
  return MilliMeter(input.data * 1000);
}

// Unit Cast for Unit mm to Base m
// Conversion Equation: 1 m = 1000 mm
template <>
[[nodiscard]] constexpr auto UnitCast(MilliMeter &&input) noexcept -> Length {
  return Length(input.data / 1000);
}

namespace literals {

constexpr auto operator""_mm(long double data) noexcept {
  return MilliMeter(static_cast<double>(data));
}

}  // namespace literals

}  // namespace csm_units