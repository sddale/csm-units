#pragma once

#include "../../unit.hpp"
#include "../../unitcast.hpp"
#include "dimension.hpp"

namespace csm_units {

using Watt = Unit<Power, "W", double>;

// Unit Cast for Base Watt
template <>
[[nodiscard]] constexpr auto UnitCast(Power &&input) noexcept -> Watt {
  return Watt(input.data);
}
template <>
[[nodiscard]] constexpr auto UnitCast(Watt &&input) noexcept -> Power {
  return Power(input.data);
}

constexpr auto operator""_W(long double data) noexcept {
  return Watt(static_cast<double>(data));
}

}  // namespace csm_units