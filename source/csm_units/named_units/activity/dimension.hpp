/**  \file dimension.hpp
 *   \brief This file is used to define the Activity of a Radionuclide dimension
 * with unit base.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Specific_activity">Activity of a
 * Radionuclide</a> if needed.
 */

#pragma once

#include <source/csm_units/dimension.hpp>

namespace csm_units {

using Activity = DimensionInt<0, 0, -1>;

}  // namespace csm_units