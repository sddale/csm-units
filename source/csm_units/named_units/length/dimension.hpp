/**  \file dimension.hpp
 *   \brief This file is used to define the Length dimension with unit
 *   base.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Length">Length</a> if
 * needed.
 */

#pragma once

#include "../../dimension.hpp"
#include "../../unitbase.hpp"

namespace csm_units {

using Length = UnitBase<Dimension<1, 0, 0, 0, 0, 0, 0>>;
using InvLength = UnitBase<Dimension<-1, 0, 0, 0, 0, 0, 0>>;

}  // namespace csm_units
