/**  \file dimension.hpp
 *   \brief This file is used to define the Solubility Parameter dimension with
 * unit base.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Hildebrand_solubility_parameter">Solubility
 * Parameter</a> if needed.
 */

#pragma once

#include "../../exponents.hpp"
#include "../../unitbase.hpp"

namespace csm_units {

using SolubilityParameter =
    UnitBase<Exponents<-1, 1, -1, 0, 0, 0, 0, 2, 2, 1, 1, 1, 1, 1>, double>;
using SqrSolubilityParameter =
    UnitBase<Exponents<-1, 1, -2, 0, 0, 0, 0>, double>;

}  // namespace csm_units
