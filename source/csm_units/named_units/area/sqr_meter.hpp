#pragma once

#include "../../unit.hpp"
#include "../../unitcast.hpp"
#include "dimension.hpp"

namespace csm_units {

using SqMeter = Unit<Area, "m2", double>;

// Unit Cast for Base m2
template <>
[[nodiscard]] constexpr auto UnitCast(Area &&input) noexcept -> SqMeter {
  return SqMeter(input.data);
}

// Unit Cast for Unit m2
template <>
[[nodiscard]] constexpr auto UnitCast(SqMeter &&input) noexcept -> Area {
  return Area(input.data);
}

constexpr auto operator""_m2(long double data) noexcept {
  return SqMeter(static_cast<double>(data));
}

}  // namespace csm_units