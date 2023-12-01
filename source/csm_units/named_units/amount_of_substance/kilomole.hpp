/**  \file kilomole.hpp
 *   \brief This file is used to define the unit Kilomole derived from the base
 * dimension for Amount of a Substance.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Mole_(unit)">Mole</a> if needed.
 */

#pragma once

#include "../../unit.hpp"
#include "../../unitcast.hpp"
#include "dimension.hpp"

namespace csm_units {

using Kilomole = Unit<Amount, "kmol", double>;

// Base Mole -> Kilomole unit
template <>
[[nodiscard]] constexpr auto UnitCast(Amount input) noexcept -> Kilomole {
  return Kilomole(input.data / 1000);
}

// unit kmol -> Base Mol
template <>
[[nodiscard]] constexpr auto UnitCast(Kilomole input) noexcept -> Amount {
  return Amount(input.data * 1000);
}

namespace literals {

constexpr auto operator""_kmol(long double data) noexcept {
  return Kilomole(static_cast<double>(data));
}

constexpr auto operator""_kmol(unsigned long long data) noexcept {
  return Kilomole(static_cast<double>(data));
}

}  // namespace literals

}  // namespace csm_units