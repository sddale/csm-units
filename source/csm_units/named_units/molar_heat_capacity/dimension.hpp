/**  \file dimension.hpp
 *   \brief This file is used to define the Molar Heat Capacity dimension with
 * unit base.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Molar_heat_capacity">Molar Heat
 * Capacity</a> if needed.
 */

#pragma once

#include <source/csm_units/dimension.hpp>

namespace csm_units {

using MolarHeatCapacity = DimensionInt<2, 1, -2, 0, -1, -1>;
using MolarEntropy = MolarHeatCapacity;

}  // namespace csm_units