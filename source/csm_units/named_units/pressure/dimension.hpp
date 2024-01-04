/**  \file dimension.hpp
 *   \brief This file is used to define the Pressure dimension with unit
 *   base.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Pressure">Pressure</a> if
 * needed.
 */

#pragma once

#include <source/csm_units/dimension.hpp>

namespace csm_units {

using Pressure = DimensionInt<-1, 1, -2, 0, 0, 0, 0>;

}  // namespace csm_units