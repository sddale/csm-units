#pragma once

#include "../../unit.hpp"
#include "../../unitcast.hpp"
#include "dimension.hpp"

namespace csm_units {

using Second = Unit<Time, "s", double>;

// Unit Cast for Unit s to Base s
template <>
[[nodiscard]] constexpr auto UnitCast(Second &&input) noexcept -> Time {
  return Time(input.data);
}

// Unit Cast for Base s to Unit s
template <>
[[nodiscard]] constexpr auto UnitCast(Time &&input) noexcept -> Second {
  return Second(input.data);
}

}  // namespace csm_units