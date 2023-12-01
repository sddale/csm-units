/**  \file grams_per_mole.hpp
 *   \brief This file is used to define the unit Grams Per Mole derived from the
 * base dimension for Molar Mass.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Molar_mass">Grams Per Mole</a> if needed.
 */

#pragma once

#include "../../unit.hpp"
#include "dimension.hpp"

namespace csm_units {

using GramsPerMol = Unit<MolarMass, "g/mol", double>;

// Unit Cast for Base GramsPerMol
template <>
[[nodiscard]] constexpr auto UnitCast(MolarMass input) noexcept -> GramsPerMol {
  return GramsPerMol(input.data * 1000);
}
template <>
[[nodiscard]] constexpr auto UnitCast(GramsPerMol input) noexcept -> MolarMass {
  return MolarMass(input.data / 1000);
}

}  // namespace csm_units