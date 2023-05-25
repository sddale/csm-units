#pragma once

#include "../../exponents.hpp"
#include "../../unitbase.hpp"

namespace csm_units {

using Length = UnitBase<Exponents<1, 0, 0, 0, 0, 0, 0>, double>;
using InvLength = UnitBase<Exponents<-1, 0, 0, 0, 0, 0, 0>, double>;

}  // namespace csm_units
