/**  \file kilograms_per_mole.hpp
 *   \brief This file is used to define the Molar Mass SI unit Kilograms Per
 * Mole.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Molar_mass">Kilograms Per Mole</a> if
 * needed.
 */

#pragma once

#include "../../unit.hpp"
#include "../../unitcast.hpp"
#include "dimension.hpp"

namespace csm_units {

using KilogramsPerMol = Unit<MolarMass, "kg/mol", double>;

// Unit Cast for Base KilogramsPerMol
template <>
[[nodiscard]] constexpr auto UnitCast(MolarMass input) noexcept
    -> KilogramsPerMol {
  return KilogramsPerMol(input.data);
}
template <>
[[nodiscard]] constexpr auto UnitCast(KilogramsPerMol input) noexcept
    -> MolarMass {
  return MolarMass(input.data);
}

}  // namespace csm_units