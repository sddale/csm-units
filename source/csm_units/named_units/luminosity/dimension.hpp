#pragma once

#include "../../exponents.hpp"
#include "../../unitbase.hpp"

namespace csm_units {

using Luminosity = UnitBase<Exponents<0, 0, 0, 0, 0, 0, 1>, double>;
using SqrLuminosity = UnitBase<Exponents<0, 0, 0, 0, 0, 0, 2>, double>;

}  // namespace csm_units
