/**  \file dimension.hpp
 *   \brief This file is used to define the Absorbed Dose dimension with unit
 *   base.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Absorbed_dose">Absorbed Dose</a> if
 * needed.
 */

#pragma once

#include "../../exponents.hpp"
#include "../../unitbase.hpp"

namespace csm_units {

using AbsorbedDose = UnitBase<Exponents<2, 0, -2, 0, 0, 0, 0>, double>;

}  // namespace csm_units