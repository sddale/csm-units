/**  \file pascal.hpp
 *   \brief This file is used to define the Inverse Pressure base unit Inverse
 * Pascal.
 *
 */

#pragma once

#include "../../unit.hpp"
#include "../../unitcast.hpp"
#include "dimension.hpp"

namespace csm_units {

using InvPascal = Unit<InvPressure, "inv_Pa", double>;

// Unit Cast for Base Pascals to Unit Pascals
// Conversion Equation: Pascals = Pascals
template <>
[[nodiscard]] constexpr auto UnitCast(InvPressure &&input) noexcept
    -> InvPascal {
  return InvPascal(input.data);
}

// Unit Cast for Unit Pascals to Base Pascals
// Conversion Equation: Pascals = Pascals
template <>
[[nodiscard]] constexpr auto UnitCast(InvPascal &&input) noexcept
    -> InvPressure {
  return InvPressure(input.data);
}

}  // namespace csm_units