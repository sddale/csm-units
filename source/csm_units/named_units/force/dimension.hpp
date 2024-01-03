/**  \file dimension.hpp
 *   \brief This file is used to define the Force dimension with unit
 *   base.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Force">Force</a> if
 * needed.
 */

#pragma once

#include "../../dimension.hpp"
#include "../../unitbase.hpp"

namespace csm_units {

using Force = UnitBase<Dimension<1, 1, -2, 0, 0, 0, 0>>;

}  // namespace csm_units