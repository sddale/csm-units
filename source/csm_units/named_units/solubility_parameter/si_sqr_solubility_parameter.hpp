/**  \file si_sqr_solubility_parameter.hpp
 *   \brief This file is used to define the Square Solubility Parameter SI unit
 * Joules Per Cubic Meter.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Hildebrand_solubility_parameter">Joules
 * Per Cubic Meter</a> if needed.
 */

#pragma once

#include "../../unit.hpp"
#include "../../unitcast.hpp"
#include "dimension.hpp"

namespace csm_units {

using JoulesPerCubicMeter = Unit<SqrSolubilityParameter, "J/m^3", double>;

// Unit Cast for base m3
template <>
[[nodiscard]] constexpr auto UnitCast(SqrSolubilityParameter input) noexcept
    -> JoulesPerCubicMeter {
  return JoulesPerCubicMeter(input.data);
}

// Unit Cast for Unit m3
template <>
[[nodiscard]] constexpr auto UnitCast(JoulesPerCubicMeter input) noexcept
    -> SqrSolubilityParameter {
  return SqrSolubilityParameter(input.data);
}

}  // namespace csm_units
