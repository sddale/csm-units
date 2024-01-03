/**  \file dimension.hpp
 *   \brief This file is used to define the Electric Current dimension with unit
 *   base.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Electric_current">Electric Current</a> if
 * needed.
 */

#pragma once

#include "../../dimension.hpp"

namespace csm_units {

using ElectricCurrent = DimensionInt<0, 0, 0, 1>;
using SqElectricCurrent = DimensionInt<0, 0, 0, 2>;

}  // namespace csm_units
