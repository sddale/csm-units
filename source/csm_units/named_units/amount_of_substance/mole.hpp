/**  \file mole.hpp
 *   \brief This file is used to define the Amount of a Substance SI unit Mole.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Mole_(unit)">Mole</a> if needed.
 */

#pragma once

#include "../../unit.hpp"
#include "../../unitcast.hpp"
#include "dimension.hpp"

namespace csm_units {

using Mole = Unit<Amount, "mol", double>;

// Unit Cast for Unit Mol
template <>
[[nodiscard]] constexpr auto UnitCast(Amount &&input) noexcept -> Mole {
  return Mole(input.data);
}

// Unit Cast for Unit Mole
template <>
[[nodiscard]] constexpr auto UnitCast(Mole &&input) noexcept -> Amount {
  return Amount(input.data);
}

namespace literals {

// amount - mole
constexpr auto operator""_mol(long double data) noexcept {
  return Mole(static_cast<double>(data));
}

}  // namespace literals

}  // namespace csm_units