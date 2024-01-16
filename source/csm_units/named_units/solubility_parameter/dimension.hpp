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

namespace csm_units {

using SolubilityParameter =
    Dimension<std::ratio<-1, 2>, std::ratio<1, 2>, std::ratio<-1>>;
using SqSolubilityParameter = DimensionInt<-1, 1, -2>;

}  // namespace csm_units
