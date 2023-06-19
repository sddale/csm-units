#pragma once

#include "../../exponents.hpp"
#include "../../unitbase.hpp"

namespace csm_units {

using ElectrCurrent = UnitBase<Exponents<0, 0, 0, 1, 0, 0, 0>, double>;
using SqrElectrCurrent = UnitBase<Exponents<0, 0, 0, 2, 0, 0, 0>, double>;

}  // namespace csm_units
