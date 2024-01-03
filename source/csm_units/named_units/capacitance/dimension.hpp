/**  \file dimension.hpp
 *   \brief This file is used to define the Capacitance dimension with unit
 *   base.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Capacitance">Capacitance</a> if
 * needed.
 */

#pragma once

#include "../../dimension.hpp"
#include "../../unitbase.hpp"

namespace csm_units {

using Capacitance = UnitBase<Dimension<-2, -1, 4, 2, 0, 0, 0>>;

}  // namespace csm_units