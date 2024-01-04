/**  \file dimension.hpp
 *   \brief This file is used to define the Reciprocal Length dimension with
 * unit base.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Reciprocal_Length">Reciprocal Length</a>
 * if needed.
 */

#pragma once

#include <source/csm_units/dimension.hpp>

namespace csm_units {

using ReciprocalLength = DimensionInt<-1, 0, 0, 0, 0, 0, 0>;

}  // namespace csm_units
