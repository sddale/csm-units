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
#include "../../unitbase.hpp"

namespace csm_units {

using Energy = UnitBase<Dimension<2, 1, -2, 0, 0, 0, 0>>;

}  // namespace csm_units