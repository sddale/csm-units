/**  \file kilomole.hpp
 *   \brief This file is used to define the unit Kilomole derived from the base
 * dimension for Amount of a Substance.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Mole_(unit)">Mole</a> if needed. Kilomole
 * having a close description to this.
 */

#pragma once

#include "../../definition.hpp"
#include "../../unit.hpp"
#include "mole.hpp"

namespace csm_units {

using Kilomole = Unit<literals::mol / std::kilo()>;

namespace literals {

constexpr auto kmol =  // NOLINT(readability-identifier-length)
    Kilomole::def;

constexpr auto operator""_kmol(long double data) noexcept {
  return Kilomole(static_cast<Kilomole::ValueType>(data));
}

constexpr auto operator""_kmol(unsigned long long data) noexcept {
  return Kilomole(static_cast<Kilomole::ValueType>(data));
}

}  // namespace literals

}  // namespace csm_units