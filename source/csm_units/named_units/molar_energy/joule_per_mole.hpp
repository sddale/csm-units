/**  \file joule_per_mole.hpp
 *   \brief This file is used to define the Energy SI unit Joule.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Joule_per_mole">Joule Per Mole</a> if
 * needed.
 */

#pragma once

#include "../../definition.hpp"
#include "../../unit.hpp"
#include "../amount_of_substance/mole.hpp"
#include "../energy/joule.hpp"

namespace csm_units {

using JoulesPerMole = Unit<literals::J / literals::mol>;

namespace literals {

constexpr auto Jpermol =  // NOLINT(readability-identifier-length)
    JoulesPerMole::def;

constexpr auto operator""_Jpermol(long double data) noexcept {
  return JoulesPerMole(static_cast<JoulesPerMole::ValueType>(data));
}

constexpr auto operator""_Jpermol(unsigned long long data) noexcept {
  return JoulesPerMole(static_cast<JoulesPerMole::ValueType>(data));
}

}  // namespace literals

}  // namespace csm_units