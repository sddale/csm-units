/**  \file mole.hpp
 *   \brief This file is used to define the Amount of a Substance SI unit Mole.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Mole_(unit)">Mole</a> if needed.
 */

#pragma once

#include "../../definition.hpp"
#include "../../unit.hpp"
#include "dimension.hpp"

namespace csm_units {

using Mole = Unit<Definition<Amount>{}>;

namespace literals {

constexpr auto mol =  // NOLINT(readability-identifier-length)
    Mole::def;

constexpr auto operator""_mol(long double data) noexcept {
  return Mole(static_cast<Mole::ValueType>(data));
}

constexpr auto operator""_mol(unsigned long long data) noexcept {
  return Mole(static_cast<Mole::ValueType>(data));
}

}  // namespace literals

}  // namespace csm_units