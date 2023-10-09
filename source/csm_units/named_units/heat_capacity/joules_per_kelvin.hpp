/**  \file joules_per_kelvin.hpp
 *   \brief This file is used to define the Heat Capacity SI unit Joules per
 * Kelvin.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Heat_capacity">Joules Per Kelvin</a> if
 * needed.
 */

#pragma once

#include "../../unit.hpp"
#include "../../unitcast.hpp"
#include "dimension.hpp"

namespace csm_units {

using JoulesPerKelvin = Unit<HeatCapacity, "J/K", double>;

// Unit Cast for Base Joules Per Kelvin
template <>
[[nodiscard]] constexpr auto UnitCast(HeatCapacity &&input) noexcept
    -> JoulesPerKelvin {
  return JoulesPerKelvin(input.data);
}
template <>
[[nodiscard]] constexpr auto UnitCast(JoulesPerKelvin &&input) noexcept
    -> HeatCapacity {
  return HeatCapacity(input.data);
}

}  // namespace csm_units