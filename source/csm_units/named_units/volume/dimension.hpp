/**  \file dimension.hpp
 *   \brief This file is used to define the Volume dimension with unit
 *   base.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Volume">Volume</a> if
 * needed.
 */

#pragma once

#include "../../exponents.hpp"
#include "../../unitbase.hpp"

namespace csm_units {

using Volume = UnitBase<Exponents<3, 0, 0, 0, 0, 0, 0>>;

}  // namespace csm_units
