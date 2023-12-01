/**  \file kg_per_liter.hpp
 *   \brief This file is used to define the unit Kilogram Per Liter derived from
 * the base dimension for Density.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Kilogram_per_cubic_metre">Kilogram Per
 * Cubic Meter</a> if needed. Kilogram Per Liter having a close description to
 * this.
 */

#pragma once

#include "../../unit.hpp"
#include "dimension.hpp"

namespace csm_units {

using KgPerL = Unit<Density, "kg/L", double>;

// Unit Cast for Unit kg/L
template <>
[[nodiscard]] constexpr auto UnitCast(Density input) noexcept -> KgPerL {
  return KgPerL(input.data / 1000);
}

// Unit Cast for Unit kg/L
template <>
[[nodiscard]] constexpr auto UnitCast(KgPerL input) noexcept -> Density {
  return Density(input.data * 1000);
}

}  // namespace csm_units