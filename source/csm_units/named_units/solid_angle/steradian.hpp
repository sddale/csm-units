#pragma once

#include "../../unit.hpp"
#include "../../unitcast.hpp"
#include "dimension.hpp"

namespace csm_units {

using Steradian = Unit<SolidAngle, "sr", double>;

template <>
[[nodiscard]] constexpr auto UnitCast(SolidAngle &&input) noexcept
    -> Steradian {
  return Steradian(input.data);
}

// Unit Cast for Unit Steradian
template <>
[[nodiscard]] constexpr auto UnitCast(Steradian &&input) noexcept
    -> SolidAngle {
  return SolidAngle(input.data);
}

}  // namespace csm_units