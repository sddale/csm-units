/**  \file inch.hpp
 *   \brief This file is used to define the unit Inch derived from the
 * base dimension for Length.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Inch">Inch</a> if needed.
 */

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

namespace literals {

constexpr auto operator""_in(long double data) noexcept {
  return Inch(static_cast<double>(data));
}

}  // namespace literals

}  // namespace csm_units