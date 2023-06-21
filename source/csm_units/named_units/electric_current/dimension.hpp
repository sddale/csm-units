/**  \file dimension.hpp
 *   \brief This file is used to define the Electric Current dimension with unit
 *   base.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Electric_current">Electric Current</a> if
 * needed.
 */

#pragma once

#include "../../exponents.hpp"
#include "../../unitbase.hpp"

namespace csm_units {

using ElectrCurrent = UnitBase<Exponents<0, 0, 0, 1, 0, 0, 0>, double>;
using SqrElectrCurrent = UnitBase<Exponents<0, 0, 0, 2, 0, 0, 0>, double>;

}  // namespace csm_units
