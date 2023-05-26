#pragma once

#include "../../unit.hpp"
#include "../../unitcast.hpp"
#include "dimension.hpp"

namespace csm_units {

using Hours = Unit<Time, "hour", double>;

// Unit Cast for Unit min to Base s
template <>
[[nodiscard]] constexpr auto UnitCast(Hours &&input) noexcept -> Time {
  return Time(input.data * 3600);
}

// Unit Cast for Base s to Unit min
template <>
[[nodiscard]] constexpr auto UnitCast(Time &&input) noexcept -> Hours {
  return Hours(input.data / 3600);
}

}  // namespace csm_units