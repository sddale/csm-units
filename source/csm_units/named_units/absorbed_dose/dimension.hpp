/**  \file dimension.hpp
 *   \brief This file is used to define the Absorbed Dose dimension with unit
 *   base.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Absorbed_dose">Absorbed Dose</a> if
 * needed.
 */

#pragma once

#include "../../dimension.hpp"

namespace csm_units {

using AbsorbedDose = Dimension<2, 0, -2, 0, 0, 0, 0>;

}  // namespace csm_units