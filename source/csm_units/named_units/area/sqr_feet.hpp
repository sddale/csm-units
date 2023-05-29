#pragma once

#include "../../unit.hpp"
#include "../../unitcast.hpp"
#include "dimension.hpp"

namespace csm_units {

using SqFt = Unit<Area, "ft2", double>;

// Unit Cast for Base area to ft2
template <>
[[nodiscard]] constexpr auto UnitCast(Area &&input) noexcept -> SqFt {
  return SqFt(input.data * 10.764);
}

// Unit Cast for Unit ft2 to base area
template <>
[[nodiscard]] constexpr auto UnitCast(SqFt &&input) noexcept -> Area {
  return Area(input.data / 10.764);
}

}  // namespace csm_units