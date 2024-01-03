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

namespace definition {

using Mole = Definition<Amount>;

}

using Mole = Unit<definition::Mole>;

namespace literals {

constexpr auto mol =  // NOLINT(readability-identifier-length)
    definition::Mole();

constexpr auto operator""_mol(long double data) noexcept {
  return Mole(static_cast<Mole::type>(data));
}

constexpr auto operator""_mol(unsigned long long data) noexcept {
  return Mole(static_cast<Mole::type>(data));
}

}  // namespace literals

}  // namespace csm_units