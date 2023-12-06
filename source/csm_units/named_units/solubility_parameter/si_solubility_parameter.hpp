/**  \file si_solubility_parameter.hpp
 *   \brief This file is used to define the Solubility Parameter SI unit J^(1/2)
 * / m^(3/2).
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Hildebrand_solubility_parameter">J^(1/2)
 * / m^(3/2)</a> if needed.
 */

#pragma once

#include "../../unit.hpp"
#include "dimension.hpp"

namespace csm_units {

using SqrtJoulesPerSqrtCubicMeter =
    Unit<SolubilityParameter, "J^(1/2)/m^(3/2)">;

// Unit Cast for base m3
template <>
[[nodiscard]] constexpr auto UnitCast(SolubilityParameter &&input) noexcept
    -> SqrtJoulesPerSqrtCubicMeter {
  return SqrtJoulesPerSqrtCubicMeter(input.data);
}

// Unit Cast for Unit m3
template <>
[[nodiscard]] constexpr auto UnitCast(
    SqrtJoulesPerSqrtCubicMeter &&input) noexcept -> SolubilityParameter {
  return SolubilityParameter(input.data);
}

}  // namespace csm_units
