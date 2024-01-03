/**  \file sqr_mole.hpp
 *   \brief This file is used to define the unit Square Mole derived from
 * the base dimension for Amount of a Substance.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Mole_(unit)">Mole</a> if
 * needed.
 */

#pragma once

#include "../../definition.hpp"
#include "../../unit.hpp"
#include "dimension.hpp"

namespace csm_units {

namespace definition {

using SqMole = Definition<SqAmount>;

}

using SqMole = Unit<definition::SqMole>;

namespace literals {

constexpr auto mol2 =  // NOLINT(readability-identifier-length)
    definition::SqMole();

constexpr auto operator""_mol2(long double data) noexcept {
  return SqMole(static_cast<SqMole::type>(data));
}

constexpr auto operator""_mol2(unsigned long long data) noexcept {
  return SqMole(static_cast<SqMole::type>(data));
}

}  // namespace literals

}  // namespace csm_units