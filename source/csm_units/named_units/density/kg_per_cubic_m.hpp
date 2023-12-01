/**  \file kg_per_cubic_m.hpp
 *   \brief This file is used to define the Density SI unit Kilogram Per Cubic
 * Meter.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Kilogram_per_cubic_metre#:~:text=The%20kilogram%20per%20cubic%20metre,by%20volume%20in%20cubic%20metres.">Kilogram
 * Per Cubic Meter</a> if needed.
 */

#pragma once

#include "../../unit.hpp"
#include "../../unitcast.hpp"
#include "dimension.hpp"

namespace csm_units {

using KgPerM3 = Unit<Density, "kg/m3", double>;

// Unit Cast for Unit kg/m^3
template <>
[[nodiscard]] constexpr auto UnitCast(Density input) noexcept -> KgPerM3 {
  return KgPerM3(input.data);
}

// Unit Cast for Unit kg/m^3
template <>
[[nodiscard]] constexpr auto UnitCast(KgPerM3 input) noexcept -> Density {
  return Density(input.data);
}

}  // namespace csm_units