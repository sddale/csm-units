/**  \file gram_per_mole.hpp
 *   \brief This file is used to define the unit Grams Per Mole derived from the
 * base dimension for Molar Mass.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Molar_mass">Grams Per Mole</a> if needed.
 */

#pragma once

#include "../../definition.hpp"
#include "../../unit.hpp"
#include "../amount_of_substance/mole.hpp"
#include "../mass/gram.hpp"

namespace csm_units {

using GramPerMole = Unit<literals::g / literals::mol>;

namespace literals {

constexpr auto gpermol =  // NOLINT(readability-identifier-length)
    GramPerMole::def;

constexpr auto operator""_gpermol(long double data) noexcept {
  return GramPerMole(static_cast<GramPerMole::ValueType>(data));
}

constexpr auto operator""_gpermol(unsigned long long data) noexcept {
  return GramPerMole(static_cast<GramPerMole::ValueType>(data));
}

}  // namespace literals

}  // namespace csm_units