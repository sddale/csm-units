/**  \file millimeter.hpp
 *   \brief This file is used to define the unit Millimeter derived from the
 * base dimension for Length.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Millimetre">Millimeter</a> if needed.
 */

#pragma once

#include "../../unit.hpp"
#include "dimension.hpp"

namespace csm_units {

using Millimeter = Unit<Length, "mm", double>;

// Unit cast for Base m to Unit mm
// Conversion Equation: 1 m = 1000 mm
template <>
[[nodiscard]] constexpr auto UnitCast(Length input) noexcept -> Millimeter {
  return Millimeter(input.data * 1000);
}

// Unit Cast for Unit mm to Base m
// Conversion Equation: 1 m = 1000 mm
template <>
[[nodiscard]] constexpr auto UnitCast(Millimeter input) noexcept -> Length {
  return Length(input.data / 1000);
}

namespace literals {

constexpr auto operator""_mm(long double data) noexcept {
  return Millimeter(static_cast<double>(data));
}

constexpr auto operator""_mm(unsigned long long data) noexcept {
  return Millimeter(static_cast<double>(data));
}

}  // namespace literals

}  // namespace csm_units