/**  \file dimension.hpp
 *   \brief This file is used to define the Frequency dimension with unit
 *   base.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Frequency">Frequency</a> if
 * needed.
 */

#pragma once

#include "../../exponents.hpp"
#include "../../unitbase.hpp"

namespace csm_units {

using Frequency = UnitBase<Exponents<0, 0, -1, 0, 0, 0, 0>, double>;

}  // namespace csm_units