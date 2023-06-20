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

namespace literals {

constexpr auto operator""_mps(long double data) noexcept {
  return MeterPerSecond(static_cast<double>(data));
}

}  // namespace literals

}  // namespace csm_units