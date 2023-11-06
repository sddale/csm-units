/**  \file joule_per_mole.hpp
 *   \brief This file is used to define the Energy SI unit Joule.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Joule_per_mole">Joule Per Mole</a> if
 * needed.
 */

#pragma once

#include "../../unit.hpp"
#include "../../unitcast.hpp"
#include "dimension.hpp"

namespace csm_units {

using JoulePerMole = Unit<MolarEnergy, "J/mol", double>;

// Unit Cast for Base Joule
template <>
[[nodiscard]] constexpr auto UnitCast(MolarEnergy &&input) noexcept
    -> JoulePerMole {
  return JoulePerMole(input.data);
}
template <>
[[nodiscard]] constexpr auto UnitCast(JoulePerMole &&input) noexcept
    -> MolarEnergy {
  return MolarEnergy(input.data);
}

}  // namespace csm_units