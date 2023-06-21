/**  \file dimension.hpp
 *   \brief This file is used to define the Area dimension with unit
 *   base.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Area">Area</a> if
 * needed.
 */

#pragma once

#include "../../exponents.hpp"
#include "../../unitbase.hpp"

namespace csm_units {

using Area = UnitBase<Exponents<2, 0, 0, 0, 0, 0, 0>, double>;

}  // namespace csm_units
