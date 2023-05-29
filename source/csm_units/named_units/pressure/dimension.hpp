#pragma once

#include "../../exponents.hpp"
#include "../../unitbase.hpp"

namespace csm_units {

using Pressure = UnitBase<Exponents<-1, 1, -2, 0, 0, 0, 0>, double>;

}  // namespace csm_units