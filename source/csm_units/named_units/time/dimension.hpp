/**  \file dimension.hpp
 *   \brief This file is used to define the Time dimension with unit
 *   base.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Time">Time</a> if
 * needed.
 */

#pragma once

#include "../../exponents.hpp"
#include "../../unitbase.hpp"

namespace csm_units {

using Time = UnitBase<Exponents<0, 0, 1, 0, 0, 0, 0>>;

}  // namespace csm_units