/**  \file dimension.hpp
 *   \brief This file is used to define the Molar Mass dimension with unit
 *   base.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Molar_mass">Molar Mass</a> if
 * needed.
 */

#pragma once

#include <source/csm_units/dimension.hpp>

namespace csm_units {

using MolarMass = DimensionInt<0, 1, 0, 0, 0, -1>;

}  // namespace csm_units