/**  \file dimension.hpp
 *   \brief This file is used to define the Conductance dimension with unit
 *   base.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Electrical_resistance_and_conductance">Conductance</a>
 * if needed.
 */

#pragma once

#include "../../dimension.hpp"
#include "../../unitbase.hpp"

namespace csm_units {

using Conductance = UnitBase<Dimension<-2, -1, 3, 2, 0, 0, 0>>;

}  // namespace csm_units