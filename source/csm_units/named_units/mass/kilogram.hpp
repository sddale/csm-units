#pragma once

#include "../../unit.hpp"
#include "../../unitcast.hpp"
#include "dimension.hpp"

namespace csm_units {

using Kilogram = Unit<Mass, "kg", double>;

// Unit Cast for Base g to Unit kg
// Conversion Equation: 1000 g = 1 kg
template <>
[[nodiscard]] constexpr auto UnitCast(Mass &&input) noexcept -> Kilogram {
  return Kilogram(input.data);
}

// Unit Cast for Unit kg to Base g
// Conversion Equation: 1000 g = 1 kg
template <>
[[nodiscard]] constexpr auto UnitCast(Kilogram &&input) noexcept -> Mass {
  return Mass(input.data);
}

namespace literals {

// mass - kilogram
constexpr auto operator""_kg(long double data) noexcept {
  return Kilogram(static_cast<double>(data));
}

}  // namespace literals

}  // namespace csm_units