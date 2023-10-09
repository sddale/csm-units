/**  \file joules_per_kelvin.hpp
 *   \brief This file is used to define the Molar Heat Capacity SI unit Joules
 * per Mole per Kelvin.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Molar_heat_capacity">Joules Per Mole
 * Per Kelvin</a> if needed.
 */

#pragma once

#include "../../unit.hpp"
#include "../../unitcast.hpp"
#include "dimension.hpp"

namespace csm_units {

using JoulesPerMoleKelvin = Unit<MolarHeatCapacity, "J/K/mol", double>;

// Unit Cast for Base Joules Per Kelvin
template <>
[[nodiscard]] constexpr auto UnitCast(MolarHeatCapacity &&input) noexcept
    -> JoulesPerMoleKelvin {
  return JoulesPerMoleKelvin(input.data);
}
template <>
[[nodiscard]] constexpr auto UnitCast(JoulesPerMoleKelvin &&input) noexcept
    -> MolarHeatCapacity {
  return MolarHeatCapacity(input.data);
}

}  // namespace csm_units