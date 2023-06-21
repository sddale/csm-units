/**  \file dimension.hpp
 *   \brief This file is used to define the Inductance dimension with unit
 *   base.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Inductance">Inductance</a> if
 * needed.
 */

#pragma once

#include "../../exponents.hpp"
#include "../../unitbase.hpp"

namespace csm_units {

using Inductance = UnitBase<Exponents<1, 1, -2, 0, 0, 0, 0>, double>;

}  // namespace csm_units
