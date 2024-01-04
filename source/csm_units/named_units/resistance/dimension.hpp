/**  \file dimension.hpp
 *   \brief This file is used to define the Resistance dimension with unit
 *   base.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Electrical_resistance_and_conductance">Resistance</a>
 * if needed.
 */

#pragma once

#include <source/csm_units/dimension.hpp>

namespace csm_units {

using Resistance = DimensionInt<2, 1, -3, -2, 0, 0, 0>;

}  // namespace csm_units