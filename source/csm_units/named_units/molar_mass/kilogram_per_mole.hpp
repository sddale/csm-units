/**  \file kilogram_per_mole.hpp
 *   \brief This file is used to define the Molar Mass SI unit Kilogram Per
 * Mole.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Molar_mass">Kilogram Per Mole</a> if
 * needed.
 */

#pragma once

#include "../../definition.hpp"
#include "../../unit.hpp"
#include "../amount_of_substance/mole.hpp"
#include "../mass/kilogram.hpp"

namespace csm_units {

using KilogramPerMole = Unit<literals::kg / literals::mol>;

namespace literals {

constexpr auto kgpermol =  // NOLINT(readability-identifier-length)
    KilogramPerMole::def;

constexpr auto operator""_kgpermol(long double data) noexcept {
  return KilogramPerMole(static_cast<KilogramPerMole::ValueType>(data));
}

constexpr auto operator""_kgpermol(unsigned long long data) noexcept {
  return KilogramPerMole(static_cast<KilogramPerMole::ValueType>(data));
}

}  // namespace literals

}  // namespace csm_units