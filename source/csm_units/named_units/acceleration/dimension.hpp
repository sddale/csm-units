/**  \file dimension.hpp
 *   \brief This file is used to define the Acceleration dimension with unit
 *   base.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Acceleration">Acceleration</a> if needed.
 */

#pragma once

#include <source/csm_units/dimension.hpp>

namespace csm_units {

using Acceleration = DimensionInt<1, 0, -2>;

}  // namespace csm_units