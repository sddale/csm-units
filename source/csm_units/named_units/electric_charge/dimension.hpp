/**  \file dimension.hpp
 *   \brief This file is used to define the Electric Charge dimension with unit
 *   base.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Electric_charge">Electric Charge</a> if
 * needed.
 */

#pragma once

#include "../../dimension.hpp"

namespace csm_units {

using ElectricCharge = DimensionInt<0, 0, 1, 1>;

}  // namespace csm_units
