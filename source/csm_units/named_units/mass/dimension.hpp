/**  \file dimension.hpp
 *   \brief This file is used to define the Mass dimension with unit
 *   base.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Mass">Mass</a> if
 * needed.
 */

#pragma once

#include "../../exponents.hpp"
#include "../../unitbase.hpp"

namespace csm_units {

using Mass = UnitBase<Exponents<0, 1, 0, 0, 0, 0, 0>, double>;

}  // namespace csm_units