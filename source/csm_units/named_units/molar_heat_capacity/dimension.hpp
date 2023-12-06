/**  \file dimension.hpp
 *   \brief This file is used to define the Molar Heat Capacity dimension with
 * unit base.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Molar_heat_capacity">Molar Heat
 * Capacity</a> if needed.
 */

#pragma once

#include "../../exponents.hpp"
#include "../../unitbase.hpp"

namespace csm_units {

using MolarHeatCapacity = UnitBase<Exponents<2, 1, -2, 0, -1, -1, 0>>;
using MolarEntropy = MolarHeatCapacity;

}  // namespace csm_units