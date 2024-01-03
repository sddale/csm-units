/**  \file dimension.hpp
 *   \brief This file is used to define the Heat Capacity dimension with unit
 *   base.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Heat_capacity">Heat Capacity</a> if
 * needed.
 */

#pragma once

#include "../../dimension.hpp"

namespace csm_units {

using HeatCapacity = DimensionInt<2, 1, -2, 0, -1>;
using Entropy = HeatCapacity;

}  // namespace csm_units