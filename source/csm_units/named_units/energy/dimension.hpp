/**  \file dimension.hpp
 *   \brief This file is used to define the Energy dimension with unit
 *   base.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Energy">Energy</a> if
 * needed.
 */

#pragma once

#include "../../exponents.hpp"
#include "../../unitbase.hpp"

namespace csm_units {

using Energy = UnitBase<Exponents<2, 1, -2, 0, 0, 0, 0>>;

}  // namespace csm_units