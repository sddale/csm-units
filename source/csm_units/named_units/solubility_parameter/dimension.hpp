/**  \file dimension.hpp
 *   \brief This file is used to define the Solubility Parameter dimension with
 * unit base.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Hildebrand_solubility_parameter">Solubility
 * Parameter</a> if needed.
 */

#pragma once

#include <source/csm_units/dimension.hpp>

#include "../../unitbase.hpp"

namespace csm_units {

using SolubilityParameter =
    UnitBase<Dimension<-1, 1, -1, 0, 0, 0, 0, 2, 2, 1, 1, 1, 1, 1>>;
using SqrSolubilityParameter = UnitBase<Dimension<-1, 1, -2, 0, 0, 0, 0>>;

}  // namespace csm_units
