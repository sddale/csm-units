/**  \file sq_mole.hpp
 *   \brief This file is used to define the unit Square Mole derived from
 * the base dimension for Amount of a Substance.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Mole_(unit)">Mole</a> if
 * needed. Square Mole having a close description to this.
 */

#pragma once

#include "../../definition.hpp"
#include "../../unit.hpp"
#include "mole.hpp"

namespace csm_units {

using SqMole = Unit<literals::mol * literals::mol>;

namespace literals {

constexpr auto mol2 =  // NOLINT(readability-identifier-length)
    SqMole::def;

constexpr auto operator""_mol2(long double data) noexcept {
  return SqMole(static_cast<SqMole::ValueType>(data));
}

constexpr auto operator""_mol2(unsigned long long data) noexcept {
  return SqMole(static_cast<SqMole::ValueType>(data));
}

}  // namespace literals

}  // namespace csm_units