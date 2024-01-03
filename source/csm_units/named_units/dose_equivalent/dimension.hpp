/**  \file dimension.hpp
 *   \brief This file is used to define the Dose Equivalent dimension with unit
 *   base.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Equivalent_dose">Dose Equivalent</a> if
 * needed.
 */

#pragma once

#include "../../dimension.hpp"

namespace csm_units {

using DoseEquivalent = DimensionInt<2, 0, -2>;

}  // namespace csm_units