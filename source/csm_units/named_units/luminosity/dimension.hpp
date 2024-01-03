/**  \file dimension.hpp
 *   \brief This file is used to define the Luminosity dimension with unit
 *   base.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Luminosity">Luminosity</a> if
 * needed.
 */

#pragma once

#include "../../dimension.hpp"
#include "../../unitbase.hpp"

namespace csm_units {

using Luminosity = UnitBase<Dimension<0, 0, 0, 0, 0, 0, 1>>;
using SqrLuminosity = UnitBase<Dimension<0, 0, 0, 0, 0, 0, 2>>;

}  // namespace csm_units
