#pragma once

#include "../../unit.hpp"
#include "../../unitcast.hpp"
#include "dimension.hpp"

namespace csm_units {

using KgPerM3 = Unit<Density, "kg/m3", double>;

// Unit Cast for Unit kg/m^3
template <>
[[nodiscard]] constexpr auto UnitCast(Density &&input) noexcept -> KgPerM3 {
  return KgPerM3(input.data);
}

// Unit Cast for Unit kg/m^3
template <>
[[nodiscard]] constexpr auto UnitCast(KgPerM3 &&input) noexcept -> Density {
  return Density(input.data);
}

namespace literals {

constexpr auto operator""_kgperm3(long double data) noexcept {
  return KgPerM3(static_cast<double>(data));
}

}  // namespace literals

}  // namespace csm_units