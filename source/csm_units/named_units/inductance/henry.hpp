#pragma once

#include "../../unit.hpp"
#include "../../unitcast.hpp"
#include "dimension.hpp"

namespace csm_units {

using Henry = Unit<Inductance, "H", double>;

// Unit Cast for Unit Henry
template <>
[[nodiscard]] constexpr auto UnitCast(Inductance &&input) noexcept -> Henry {
  return Henry(input.data);
}

// Unit Cast for Unit Henry
template <>
[[nodiscard]] constexpr auto UnitCast(Henry &&input) noexcept -> Inductance {
  return Inductance(input.data);
}

}  // namespace csm_units