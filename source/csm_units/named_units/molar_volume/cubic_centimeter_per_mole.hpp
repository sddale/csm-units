/**  \file cubic_meter.hpp
 *   \brief This file is used to define the unit Cubic Centimeter Per Mole from
 * the base dimension for MolarVolume.
 *
 */

#pragma once

#include "../../unit.hpp"
#include "../../unitcast.hpp"
#include "dimension.hpp"

namespace csm_units {

using CubicCentimeterPerMole = Unit<MolarVolume, "cm3/mol", double>;

// Unit Cast for base m3
template <>
[[nodiscard]] constexpr auto UnitCast(MolarVolume &&input) noexcept
    -> CubicCentimeterPerMole {
  return CubicCentimeterPerMole(input.data / 1E-6);
}

// Unit Cast for Unit m3
template <>
[[nodiscard]] constexpr auto UnitCast(CubicCentimeterPerMole &&input) noexcept
    -> MolarVolume {
  return MolarVolume(input.data * 1E-6);
}

}  // namespace csm_units
