/**  \file dimension.hpp
 *   \brief This file is used to define the Luminous Flux dimension with unit
 *   base.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Luminous_flux">Luminous Flux</a> if
 * needed.
 */

#pragma once

#include "../../dimension.hpp"
#include "../../unitbase.hpp"

namespace csm_units {

using LuminousFlux = UnitBase<Dimension<0, 0, 0, 0, 0, 0, 1>>;

}  // namespace csm_units