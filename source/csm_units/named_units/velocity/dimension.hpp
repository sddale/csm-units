/**  \file dimension.hpp
 *   \brief This file is used to define the Velocity dimension with unit
 *   base.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Velocity">Velocity</a> if
 * needed.
 */

#pragma once

#include <source/csm_units/dimension.hpp>

namespace csm_units {

using Velocity = DimensionInt<1, 0, -1, 0, 0, 0, 0>;

}  // namespace csm_units