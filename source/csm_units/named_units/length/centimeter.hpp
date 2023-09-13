/**  \file centimeter.hpp
 *   \brief This file is used to define the unit Centimeter derived from the
 * base dimension for Length.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Centimetre#">Centimeter</a> if needed.
 */

#pragma once

#include "../../unit.hpp"
#include "../../unitcast.hpp"
#include "dimension.hpp"

namespace csm_units {

using Centimeter = Unit<Length, "cm", double>;

// Unit cast for Base m to Unit cm
// Conversion Equation: 1 m = 100 cm
template <>
[[nodiscard]] constexpr auto UnitCast(Length &&input) noexcept -> Centimeter {
  return Centimeter(input.data * 100);
}

// Unit Cast for Unit cm to Base m
// Conversion Equation: 1 m = 100 cm
template <>
[[nodiscard]] constexpr auto UnitCast(Centimeter &&input) noexcept -> Length {
  return Length(input.data / 100);
}

namespace literals {

constexpr auto operator""_cm(long double data) noexcept {
  return Centimeter(static_cast<double>(data));
}

constexpr auto operator""_cm(unsigned long long data) noexcept {
  return Centimeter(static_cast<double>(data));
}

}  // namespace literals

}  // namespace csm_units