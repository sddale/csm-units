/**  \file dimension.hpp
 *   \brief This file is used to define the Luminous Flux dimension with unit
 *   base.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Luminous_flux">Luminous Flux</a> if
 * needed.
 */

#pragma once

#include <source/csm_units/dimension.hpp>

namespace csm_units {

using LuminousFlux = DimensionInt<0, 0, 0, 0, 0, 0, 1>;  // Radians are unitless

}  // namespace csm_units