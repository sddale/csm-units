/**  \file dimension.hpp
 *   \brief This file is used to define the Illuminance dimension with unit
 *   base.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Illuminance">Illuminance</a> if
 * needed.
 */

#pragma once

#include <source/csm_units/dimension.hpp>

namespace csm_units {

using Illuminance = DimensionInt<-2, 0, 0, 0, 0, 0, 1>;

}  // namespace csm_units