/**  \file dimension.hpp
 *   \brief This file is used to define the Molar Volume dimension with unit
 *   base.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Molar_volume">Molar Volume</a> if
 * needed.
 */

#pragma once

#include <source/csm_units/dimension.hpp>

namespace csm_units {

using MolarVolume = DimensionInt<3, 0, 0, 0, 0, -1>;

}  // namespace csm_units
