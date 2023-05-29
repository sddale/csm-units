#pragma once

#include "../../unit.hpp"
#include "../../unitcast.hpp"
#include "dimension.hpp"

namespace csm_units {

using Newton = Unit<Force, "N", double>;

// Unit Cast for Base Newton
template <>
[[nodiscard]] constexpr auto UnitCast(Force &&input) noexcept -> Newton {
  return Newton(input.data);
}
template <>
[[nodiscard]] constexpr auto UnitCast(Newton &&input) noexcept -> Force {
  return Force(input.data);
}

}  // namespace csm_units