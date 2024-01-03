/**  \file dimension.hpp
 *   \brief This file is used to define the Amount of a Substance dimension with
 * unit base.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Amount_of_substance#:~:text=In%20chemistry%2C%20the%20amount%20of,the%20Avogadro%20constant%20NA.">Amount
 * of a Substance</a> if needed.
 */

#pragma once

#include "../../dimension.hpp"
#include "../../unitbase.hpp"

namespace csm_units {

using Amount = UnitBase<Dimension<0, 0, 0, 0, 0, 1, 0>>;
using SqrAmount = UnitBase<Dimension<0, 0, 0, 0, 0, 2, 0>>;

}  // namespace csm_units
