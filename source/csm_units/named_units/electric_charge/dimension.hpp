/**  \file dimension.hpp
 *   \brief This file is used to define the Electric Charge dimension with unit
 *   base.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Electric_charge">Electric Charge</a> if
 * needed.
 */

#pragma once

#include "../../exponents.hpp"
#include "../../unitbase.hpp"

namespace csm_units {

using ElectrCharge = UnitBase<Exponents<0, 0, 1, 1, 0, 0, 0>, double>;

}  // namespace csm_units
