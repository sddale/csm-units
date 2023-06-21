/**  \file dimension.hpp
 *   \brief This file is used to define the Conductance dimension with unit
 *   base.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Electrical_resistance_and_conductance">Conductance</a>
 * if needed.
 */

#pragma once

#include "../../exponents.hpp"
#include "../../unitbase.hpp"

namespace csm_units {

using Conductance = UnitBase<Exponents<-2, -1, 3, 2, 0, 0, 0>, double>;

}  // namespace csm_units