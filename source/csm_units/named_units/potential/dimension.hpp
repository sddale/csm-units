/**  \file dimension.hpp
 *   \brief This file is used to define the Potential dimension with unit
 *   base.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Electric_potential">Potential</a> if
 * needed.
 */

#pragma once

#include "../../exponents.hpp"
#include "../../unitbase.hpp"

namespace csm_units {

using Potential = UnitBase<Exponents<2, 1, -3, -1, 0, 0, 0>, double>;

}  // namespace csm_units