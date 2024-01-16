/**  \file dimension.hpp
 *   \brief This file is used to define the Molar Energy dimension with unit
 *   base.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Joule_per_mole">Molar Energy</a> if
 * needed.
 */

#pragma once

#include <source/csm_units/dimension.hpp>

namespace csm_units {

using MolarEnergy = DimensionInt<2, 1, -2, 0, 0, -1>;

}  // namespace csm_units