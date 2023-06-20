#pragma once

#include "../../unit.hpp"
#include "../../unitcast.hpp"
#include "dimension.hpp"

namespace csm_units {

using Sievert = Unit<DoseEquivalent, "Sv", double>;

// Unit Cast for Base Sievert
template <>
[[nodiscard]] constexpr auto UnitCast(DoseEquivalent &&input) noexcept
    -> Sievert {
  return Sievert(input.data);
}
template <>
[[nodiscard]] constexpr auto UnitCast(Sievert &&input) noexcept
    -> DoseEquivalent {
  return DoseEquivalent(input.data);
}

namespace literals {

constexpr auto operator""_Sv(long double data) noexcept {
  return Sievert(static_cast<double>(data));
}

}  // namespace literals

}  // namespace csm_units