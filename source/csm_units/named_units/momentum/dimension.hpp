/**  \file dimension.hpp
 *   \brief This file is used to define the Momentum dimension with
 * unit base.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Momentum">Momentum
 * </a> if needed.
 */

#pragma once

#include "../../dimension.hpp"
#include "../../unitbase.hpp"

namespace csm_units {

using Momentum = UnitBase<Dimension<1, 1, -1, 0, 0, 0, 0>>;

}  // namespace csm_units