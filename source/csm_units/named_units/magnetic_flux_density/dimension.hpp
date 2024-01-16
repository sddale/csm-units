/**  \file dimension.hpp
 *   \brief This file is used to define the Magnetic Flux Density dimension with
 * unit base.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Magnetic_field#The_B-field">Magnetic Flux
 * Density</a> if needed.
 */

#pragma once

#include <source/csm_units/dimension.hpp>

namespace csm_units {

using MagneticFluxDensity = DimensionInt<-1, 1, -2, 1>;

}  // namespace csm_units