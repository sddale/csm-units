#pragma once

#include "../../unit.hpp"
#include "../../unitcast.hpp"
#include "dimension.hpp"

namespace csm_units {

using MeterPerSecond = Unit<Velocity, "m/s", double>;

// Unit Cast for Unit m/s
template <>
[[nodiscard]] constexpr auto UnitCast(Velocity &&input) noexcept
    -> MeterPerSecond {
  return MeterPerSecond(input.data);
}

// Unit Cast for Unit m/s
template <>
[[nodiscard]] constexpr auto UnitCast(MeterPerSecond &&input) noexcept
    -> Velocity {
  return Velocity(input.data);
}

}  // namespace csm_units