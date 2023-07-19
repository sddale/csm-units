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
#include "../../unitcast.hpp"
#include "dimension.hpp"

namespace csm_units {

using SqrRootJoulesPerSqrRootCubicMeter =
    Unit<SolubilityParameter, "J^(1/2)/m^(3/2)", double>;

// Unit Cast for base m3
template <>
[[nodiscard]] constexpr auto UnitCast(SolubilityParameter &&input) noexcept
    -> SqrRootJoulesPerSqrRootCubicMeter {
  return SqrRootJoulesPerSqrRootCubicMeter(input.data);
}

// Unit Cast for Unit m3
template <>
[[nodiscard]] constexpr auto UnitCast(
    SqrRootJoulesPerSqrRootCubicMeter &&input) noexcept -> SolubilityParameter {
  return SolubilityParameter(input.data);
}

namespace literals {

constexpr auto operator""_SqrRtJpSqrRtM3(long double data) noexcept {
  return SqrRootJoulesPerSqrRootCubicMeter(static_cast<double>(data));
}

}  // namespace literals

}  // namespace csm_units
