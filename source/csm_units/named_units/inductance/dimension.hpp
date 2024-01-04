/**  \file dimension.hpp
 *   \brief This file is used to define the Inductance dimension with unit
 *   base.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Inductance">Inductance</a> if
 * needed.
 */

#pragma once

#include <source/csm_units/dimension.hpp>

namespace csm_units {

using Inductance = DimensionInt<1, 1, -2>;

}  // namespace csm_units
