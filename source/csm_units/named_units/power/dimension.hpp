/**  \file dimension.hpp
 *   \brief This file is used to define the Power dimension with unit
 *   base.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Electric_power">Power</a> if
 * needed.
 */

#pragma once

#include <source/csm_units/dimension.hpp>

namespace csm_units {

using Power = DimensionInt<2, 1, -3, 0, 0, 0, 0>;

}  // namespace csm_units