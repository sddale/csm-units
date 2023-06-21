/**  \file dimension.hpp
 *   \brief This file is used to define the Magnetic Flux Density dimension with
 * unit base.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Magnetic_field#The_B-field">Magnetic Flux
 * Density</a> if needed.
 */

#pragma once

#include "../../exponents.hpp"
#include "../../unitbase.hpp"

namespace csm_units {

using MagneticFluxDensity = UnitBase<Exponents<-1, 1, -2, 1, 0, 0, 0>, double>;

}  // namespace csm_units