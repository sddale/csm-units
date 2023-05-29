#pragma once

#include "../../exponents.hpp"
#include "../../unitbase.hpp"

namespace csm_units {

using Amount = UnitBase<Exponents<0, 0, 0, 0, 0, 1, 0>, double>;
using SqrAmount = UnitBase<Exponents<0, 0, 0, 0, 0, 2, 0>, double>;

}  // namespace csm_units
