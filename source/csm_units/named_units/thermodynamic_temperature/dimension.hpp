/**  \file dimension.hpp
 *   \brief This file is used to define the Thermodynamic Temperature dimension
 * with unit base.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Thermodynamic_temperature">Thermodynamic
 * Temperature</a> if needed.
 */

#pragma once

#include "../../dimension.hpp"

namespace csm_units {

using Temperature = DimensionInt<0, 0, 0, 0, 1>;

}  // namespace csm_units
