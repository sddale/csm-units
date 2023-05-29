#pragma once

#include "../../unit.hpp"
#include "../../unitcast.hpp"
#include "dimension.hpp"

namespace csm_units {

using Radian = Unit<PlaneAngle, "rad", double>;

template <>
[[nodiscard]] constexpr auto UnitCast(PlaneAngle &&input) noexcept -> Radian {
  return Radian(input.data);
}

// Unit Cast for Unit Radian
template <>
[[nodiscard]] constexpr auto UnitCast(Radian &&input) noexcept -> PlaneAngle {
  return PlaneAngle(input.data);
}

}  // namespace csm_units