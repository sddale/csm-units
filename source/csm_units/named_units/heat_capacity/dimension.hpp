/**  \file dimension.hpp
 *   \brief This file is used to define the Heat Capacity dimension with unit
 *   base.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Heat_capacity">Heat Capacity</a> if
 * needed.
 */

#pragma once

#include "../../exponents.hpp"
#include "../../unitbase.hpp"

namespace csm_units {

using HeatCapacity = UnitBase<Exponents<2, 1, -2, 0, -1, 0, 0>>;
using Entropy = HeatCapacity;

}  // namespace csm_units