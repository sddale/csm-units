/**  \file dimension.hpp
 *   \brief This file is used to define the Magnetic Flux dimension with unit
 *   base.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Magnetic_flux">Magnetic Flux</a> if
 * needed.
 */

#pragma once

#include "../../dimension.hpp"
#include "../../unitbase.hpp"

namespace csm_units {

using MagneticFlux = UnitBase<Dimension<1, 1, -2, 1, 0, 0, 0>>;

}  // namespace csm_units