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

}  // namespace csm_units