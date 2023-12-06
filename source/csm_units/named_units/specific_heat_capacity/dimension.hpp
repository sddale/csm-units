/**  \file dimension.hpp
 *   \brief This file is used to define the Specific Heat Capacity dimension
 * with unit base.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Specific_heat_capacity">Specific Molar
 * Heat Capacity</a> if needed.
 */

#pragma once

#include "../../exponents.hpp"
#include "../../unitbase.hpp"

namespace csm_units {

using SpecificHeatCapacity = UnitBase<Exponents<2, 0, -2, 0, -1, 0, 0>>;
using SpecificEntropy = SpecificHeatCapacity;

}  // namespace csm_units