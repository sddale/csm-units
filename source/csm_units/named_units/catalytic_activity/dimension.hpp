/**  \file dimension.hpp
 *   \brief This file is used to define the Catalytic Activity dimension with
 * unit base.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Catalysis">Catalytic Activity</a> if
 * needed.
 */

#pragma once

#include <source/csm_units/dimension.hpp>

namespace csm_units {

using CatalyticActivity = DimensionInt<0, 0, -1, 0, 0, 1>;

}  // namespace csm_units