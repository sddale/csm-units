#pragma once

#include "../../unit.hpp"
#include "../../unitcast.hpp"
#include "dimension.hpp"

namespace csm_units {

using Atm = Unit<Pressure, "Atm", double>;

// Unit Cast for Base Pascals to Unit Atm
// Conversion Equation: 1 atm = 101,325 pascals
template <>
[[nodiscard]] constexpr auto UnitCast(Pressure &&input) noexcept -> Atm {
  return Atm(input.data / 101325);
}

// Unit Cast for Unit Bar to Base Pascals
// Conversion Equation: 1 bar = 101,325 pascals
template <>
[[nodiscard]] constexpr auto UnitCast(Atm &&input) noexcept -> Pressure {
  return Pressure(input.data * 101325);
}

}  // namespace csm_units