#pragma once

#include "../../unit.hpp"
#include "../../unitcast.hpp"
#include "dimension.hpp"

namespace csm_units {

using CubeMeter = Unit<Volume, "m3", double>;

// Unit Cast for base m3
template <>
[[nodiscard]] constexpr auto UnitCast(Volume &&input) noexcept -> CubeMeter {
  return CubeMeter(input.data);
}

// Unit Cast for Unit m3
template <>
[[nodiscard]] constexpr auto UnitCast(CubeMeter &&input) noexcept -> Volume {
  return Volume(input.data);
}

namespace literals {

constexpr auto operator""_m3(long double data) noexcept {
  return CubeMeter(static_cast<double>(data));
}

}  // namespace literals

}  // namespace csm_units
