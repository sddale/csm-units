/**  \file kilograms_per_mole.hpp
 *   \brief This file is used to define the Molar Mass SI unit Kilograms Per
 * Mole.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Molar_mass">Kilograms Per Mole</a> if
 * needed.
 */

#pragma once

#include "../../definition.hpp"
#include "../../unit.hpp"
#include "dimension.hpp"

namespace csm_units {

namespace definition {

using KilogramPerMole = Definition<MolarMass, NoConv>;

}

using KilogramPerMole = Unit<definition::KilogramPerMole>;

namespace literals {

constexpr auto kgpermol =  // NOLINT(readability-identifier-length)
    definition::KilogramPerMole();

constexpr auto operator""_kgpermol(long double data) noexcept {
  return KilogramPerMole(static_cast<KilogramPerMole::type>(data));
}

constexpr auto operator""_kgpermol(unsigned long long data) noexcept {
  return KilogramPerMole(static_cast<KilogramPerMole::type>(data));
}

}  // namespace literals

}  // namespace csm_units