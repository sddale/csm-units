/**  \file dimension.hpp
 *   \brief This file is used to define the Pressure dimension with unit
 *   base.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Pressure">Pressure</a> if
 * needed.
 */

#pragma once

#include "../../exponents.hpp"
#include "../../unitbase.hpp"

namespace csm_units {

using Pressure = UnitBase<Exponents<-1, 1, -2, 0, 0, 0, 0>, double>;
using InvPressure = UnitBase<Exponents<1, -1, 2, 0, 0, 0, 0>, double>;

}  // namespace csm_units