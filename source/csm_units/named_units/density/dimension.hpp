/**  \file dimension.hpp
 *   \brief This file is used to define the Density dimension with unit
 *   base.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Density">Density</a> if
 * needed.
 */

#pragma once

#include "../../dimension.hpp"
#include "../../unitbase.hpp"

namespace csm_units {

using Density = UnitBase<Dimension<-3, 1, 0, 0, 0, 0, 0>>;

}  // namespace csm_units