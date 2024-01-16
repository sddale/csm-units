/**  \file sq_kilomole.hpp
 *   \brief This file is used to define the unit Square Kilomole derived from
 * the base dimension for Amount of a Substance.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Mole_(unit)">Mole</a> if needed. Square
 * Kilomole having a close description to this.
 */

#pragma once

#include "../../definition.hpp"
#include "../../unit.hpp"
#include "kilomole.hpp"

namespace csm_units {

using SqKilomole = Unit<literals::kmol * literals::kmol>;

namespace literals {

constexpr auto kmol2 =  // NOLINT(readability-identifier-length)
    SqKilomole::def;

constexpr auto operator""_kmol2(long double data) noexcept {
  return SqKilomole(static_cast<SqKilomole::ValueType>(data));
}

constexpr auto operator""_kmol2(unsigned long long data) noexcept {
  return SqKilomole(static_cast<SqKilomole::ValueType>(data));
}

}  // namespace literals

}  // namespace csm_units