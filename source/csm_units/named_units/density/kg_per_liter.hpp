#pragma once

#include "../../unit.hpp"
#include "../../unitcast.hpp"
#include "dimension.hpp"

namespace csm_units {

using KgPerL = Unit<Density, "kg/L", double>;

// Unit Cast for Unit kg/L
template <>
[[nodiscard]] constexpr auto UnitCast(Density &&input) noexcept -> KgPerL {
  return KgPerL(input.data / 1000);
}

// Unit Cast for Unit kg/L
template <>
[[nodiscard]] constexpr auto UnitCast(KgPerL &&input) noexcept -> Density {
  return Density(input.data * 1000);
}

}  // namespace csm_units