/**  \file dimension.hpp
 *   \brief This file is used to define the Momentum dimension with
 * unit base.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Momentum">Momentum
 * </a> if needed.
 */

#pragma once

#include <source/csm_units/dimension.hpp>

namespace csm_units {

using Momentum = DimensionInt<1, 1, -1>;

}  // namespace csm_units