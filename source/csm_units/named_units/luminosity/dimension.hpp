/**  \file dimension.hpp
 *   \brief This file is used to define the Luminosity dimension with unit
 *   base.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Luminosity">Luminosity</a> if
 * needed.
 */

#pragma once

#include <source/csm_units/dimension.hpp>

namespace csm_units {

using Luminosity = DimensionInt<0, 0, 0, 0, 0, 0, 1>;
using SqLuminosity = DimensionInt<0, 0, 0, 0, 0, 0, 2>;

}  // namespace csm_units
