#pragma once

#include "../../unit.hpp"
#include "../../unitcast.hpp"
#include "dimension.hpp"

namespace csm_units {

using KiloMeter = Unit<Length, "km", double>;

// Unit cast for Base m to Unit km
// Conversion Equation: 1000 m = 1 km
template <>
[[nodiscard]] constexpr auto UnitCast(Length &&input) noexcept -> KiloMeter {
  return KiloMeter(input.data / 1000);
}

// Unit Cast for Unit km to Base m
// Conversion Equation: 1000 m = 1 km
template <>
[[nodiscard]] constexpr auto UnitCast(KiloMeter &&input) noexcept -> Length {
  return Length(input.data * 1000);
}

namespace literals {

constexpr auto operator""_km(long double data) noexcept {
  return KiloMeter(static_cast<double>(data));
}

}  // namespace literals

}  // namespace csm_units