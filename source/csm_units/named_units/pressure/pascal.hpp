#pragma once

#include "../../unit.hpp"
#include "../../unitcast.hpp"
#include "dimension.hpp"

namespace csm_units {

using Pascal = Unit<Pressure, "Pa", double>;

// Unit Cast for Base Pascals to Unit Pascals
// Conversion Equation: Pascals = Pascals
template <>
[[nodiscard]] constexpr auto UnitCast(Pressure &&input) noexcept -> Pascal {
  return Pascal(input.data);
}

// Unit Cast for Unit Pascals to Base Pascals
// Conversion Equation: Pascals = Pascals
template <>
[[nodiscard]] constexpr auto UnitCast(Pascal &&input) noexcept -> Pressure {
  return Pressure(input.data);
}

constexpr auto operator""_Pa(long double data) noexcept {
  return Pascal(static_cast<double>(data));
}

}  // namespace csm_units