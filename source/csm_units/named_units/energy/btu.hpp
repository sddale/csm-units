/**  \file btu.hpp
 *   \brief This file is used to define the British Thermal Unit (Btu) derived
 * from the base dimension for Energy.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/British_thermal_unit">Btu</a> if needed.
 */

#pragma once

#include "../../unit.hpp"
#include "dimension.hpp"

namespace csm_units {

using BritishThermalUnit = Unit<Energy, "Btu", double>;

// Unit Cast for Base Joules to Btu
// Conversion Equation: 1 Btu = 1055.06 Joules (according to International Table
// standards)
template <>
[[nodiscard]] constexpr auto UnitCast(Energy input) noexcept
    -> BritishThermalUnit {
  return BritishThermalUnit(input.data / 1055.06);
}

// Unit Cast for Btu to Base Joules
// Conversion Equation: 1 Btu = 1055.06 Joules (according to International Table
// standards)
template <>
[[nodiscard]] constexpr auto UnitCast(BritishThermalUnit input) noexcept
    -> Energy {
  return Energy(input.data * 1055.06);
}

namespace literals {

constexpr auto operator""_Btu(long double data) noexcept {
  return BritishThermalUnit(static_cast<double>(data));
}

constexpr auto operator""_Btu(unsigned long long data) noexcept {
  return BritishThermalUnit(static_cast<double>(data));
}

}  // namespace literals

}  // namespace csm_units