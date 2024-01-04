/**  \file dimension.hpp
 *   \brief This file is used to define the Force dimension with unit
 *   base.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Force">Force</a> if
 * needed.
 */

#pragma once

#include <source/csm_units/dimension.hpp>

namespace csm_units {

using Force = DimensionInt<1, 1, -2>;

}  // namespace csm_units