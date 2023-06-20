#pragma once

#include "../../unit.hpp"
#include "../../unitcast.hpp"
#include "dimension.hpp"

namespace csm_units {

using Bar = Unit<Pressure, "bar", double>;

// Unit Cast for Base Pascals to Unit Bar
// Conversion Equation: 1 bar = 100,000 pascals
template <>
[[nodiscard]] constexpr auto UnitCast(Pressure &&input) noexcept -> Bar {
  return Bar(input.data / 100000);
}

// Unit Cast for Unit Bar to Base Pascals
// Conversion Equation: 1 bar = 100,000 pascals
template <>
[[nodiscard]] constexpr auto UnitCast(Bar &&input) noexcept -> Pressure {
  return Pressure(input.data * 100000);
}

namespace literals {

constexpr auto operator""_bar(long double data) noexcept {
  return Bar(static_cast<double>(data));
}

}  // namespace literals

}  // namespace csm_units