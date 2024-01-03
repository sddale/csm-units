/**  \file dimension.hpp
 *   \brief This file is used to define the Time dimension with unit
 *   base.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Time">Time</a> if
 * needed.
 */

#pragma once

#include "../../dimension.hpp"

namespace csm_units {

using Time = Dimension<std::ratio<0>, std::ratio<0>, std::ratio<1>>;

}  // namespace csm_units