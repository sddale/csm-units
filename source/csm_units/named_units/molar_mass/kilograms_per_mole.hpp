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
[[nodiscard]] constexpr auto UnitCast(MolarMass &&input) noexcept
    -> KilogramsPerMol {
  return KilogramsPerMol(input.data);
}
template <>
[[nodiscard]] constexpr auto UnitCast(KilogramsPerMol &&input) noexcept
    -> MolarMass {
  return MolarMass(input.data);
}

namespace literals {

constexpr auto operator""_kgpmol(long double data) noexcept {
  return KilogramsPerMol(static_cast<double>(data));
}

}  // namespace literals

}  // namespace csm_units