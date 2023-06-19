#pragma once

#include "../../unit.hpp"
#include "../../unitcast.hpp"
#include "dimension.hpp"

namespace csm_units {

using Psi = Unit<Pressure, "psi", double>;

// Unit Cast for Base Pascals to Unit psi
// Conversion Equation: 1 psi = 6894.76 pascals
template <>
[[nodiscard]] constexpr auto UnitCast(Pressure &&input) noexcept -> Psi {
  return Psi(input.data / 6894.76);
}

// Unit Cast for Unit psi to Base Pascals
// Conversion Equation: 1 psi = 6894.76 pascals
template <>
[[nodiscard]] constexpr auto UnitCast(Psi &&input) noexcept -> Pressure {
  return Pressure(input.data * 6894.76);
}

constexpr auto operator""_psi(long double data) noexcept {
  return Psi(static_cast<double>(data));
}

}  // namespace csm_units