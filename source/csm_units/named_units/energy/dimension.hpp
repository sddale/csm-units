/**  \file dimension.hpp
 *   \brief This file is used to define the Energy dimension with unit
 *   base.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Energy">Energy</a> if
 * needed.
 */

#pragma once

#include "../../dimension.hpp"

namespace csm_units {

using Energy = DimensionInt<2, 1, -2>;

}  // namespace csm_units