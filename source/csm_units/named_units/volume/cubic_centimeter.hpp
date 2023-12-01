/**  \file cubic_meter.hpp
 *   \brief This file is used to define the unit Cubic Centimeter from the base
 * dimension for Volume.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Cubic_centimetre">Cubic Centimeter</a> if
 * needed.
 */

#pragma once

#include "../../unit.hpp"
#include "dimension.hpp"

namespace csm_units {

using CubicCentimeter = Unit<Volume, "cm3", double>;

// Unit Cast for base m3
template <>
[[nodiscard]] constexpr auto UnitCast(Volume input) noexcept
    -> CubicCentimeter {
  return CubicCentimeter(input.data / 1E-6);
}

// Unit Cast for Unit m3
template <>
[[nodiscard]] constexpr auto UnitCast(CubicCentimeter input) noexcept
    -> Volume {
  return Volume(input.data * 1E-6);
}

namespace literals {

constexpr auto operator""_cm3(long double data) noexcept {
  return CubicCentimeter(static_cast<double>(data));
}

constexpr auto operator""_cm3(unsigned long long data) noexcept {
  return CubicCentimeter(static_cast<double>(data));
}

}  // namespace literals

}  // namespace csm_units
