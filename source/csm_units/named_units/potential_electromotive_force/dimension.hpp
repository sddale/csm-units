/**  \file dimension.hpp
 *   \brief This file is used to define the Potential dimension with unit
 *   base.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Electric_potential">Potential</a> if
 * needed.
 */

#pragma once

#include <source/csm_units/dimension.hpp>

namespace csm_units {

using PotentialElectromotiveForce = DimensionInt<2, 1, -3, -1>;

}  // namespace csm_units