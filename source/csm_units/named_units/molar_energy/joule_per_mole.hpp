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
#include "dimension.hpp"

namespace csm_units {

namespace definition {

using JoulePerMole = Definition<MolarEnergy>;

}

using JoulePerMole = Unit<definition::JoulePerMole>;

namespace literals {

constexpr auto Jpermol =  // NOLINT(readability-identifier-length)
    definition::JoulePerMole();

constexpr auto operator""_Jpermol(long double data) noexcept {
  return JoulePerMole(static_cast<JoulePerMole::type>(data));
}

constexpr auto operator""_Jpermol(unsigned long long data) noexcept {
  return JoulePerMole(static_cast<JoulePerMole::type>(data));
}

}  // namespace literals

}  // namespace csm_units