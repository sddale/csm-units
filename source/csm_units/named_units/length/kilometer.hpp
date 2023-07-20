/**  \file kilometer.hpp
 *   \brief This file is used to define the unit Kilometer derived from the
 * base dimension for Length.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Kilometre">Kilometer</a> if needed.
 */

#pragma once

#include "../../unit.hpp"
#include "../../unitcast.hpp"
#include "dimension.hpp"

namespace csm_units {

using Kilometer = Unit<Length, "km", double>;

// Unit cast for Base m to Unit km
// Conversion Equation: 1000 m = 1 km
template <>
[[nodiscard]] constexpr auto UnitCast(Length &&input) noexcept -> Kilometer {
  return Kilometer(input.data / 1000);
}

// Unit Cast for Unit km to Base m
// Conversion Equation: 1000 m = 1 km
template <>
[[nodiscard]] constexpr auto UnitCast(Kilometer &&input) noexcept -> Length {
  return Length(input.data * 1000);
}

namespace literals {

constexpr auto operator""_km(long double data) noexcept {
  return Kilometer(static_cast<double>(data));
}

}  // namespace literals

}  // namespace csm_units