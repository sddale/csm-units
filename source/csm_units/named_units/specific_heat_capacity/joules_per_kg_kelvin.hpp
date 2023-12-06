/**  \file joules_per_kelvin.hpp
 *   \brief This file is used to define the Specific Heat Capacity SI unit
 * Joules per Kilogram per Kelvin.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Specific_heat_capacity">Joules Per
 * Kilogram Per Kelvin</a> if needed.
 */

#pragma once

#include "../../unit.hpp"
#include "dimension.hpp"

namespace csm_units {

using JoulesPerKilogramKelvin = Unit<SpecificHeatCapacity, "J/K/kg">;

template <>
[[nodiscard]] constexpr auto UnitCast(SpecificHeatCapacity &&input) noexcept
    -> JoulesPerKilogramKelvin {
  return JoulesPerKilogramKelvin(input.data);
}
template <>
[[nodiscard]] constexpr auto UnitCast(JoulesPerKilogramKelvin &&input) noexcept
    -> SpecificHeatCapacity {
  return SpecificHeatCapacity(input.data);
}

}  // namespace csm_units