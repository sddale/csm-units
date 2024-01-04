/**  \file dimension.hpp
 *   \brief This file is used to define the Specific Heat Capacity dimension
 * with unit base.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Specific_heat_capacity">Specific Molar
 * Heat Capacity</a> if needed.
 */

#pragma once

#include <source/csm_units/dimension.hpp>

namespace csm_units {

using SpecificHeatCapacity = DimensionInt<2, 0, -2, 0, -1, 0, 0>;

}  // namespace csm_units