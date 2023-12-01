/**  \file cubic_meter.hpp
 *   \brief This file is used to define the MolarVolume SI unit Cubic Meter Per
 * Mole.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Molar_volume">Cubic Meter Per Mole</a> if
 * needed.
 */

#pragma once

#include "../../unit.hpp"
#include "../../unitcast.hpp"
#include "dimension.hpp"

namespace csm_units {

using CubicMeterPerMole = Unit<MolarVolume, "m3/mol", double>;

// Unit Cast for base m3
template <>
[[nodiscard]] constexpr auto UnitCast(MolarVolume input) noexcept
    -> CubicMeterPerMole {
  return CubicMeterPerMole(input.data);
}

// Unit Cast for Unit m3
template <>
[[nodiscard]] constexpr auto UnitCast(CubicMeterPerMole input) noexcept
    -> MolarVolume {
  return MolarVolume(input.data);
}

}  // namespace csm_units
