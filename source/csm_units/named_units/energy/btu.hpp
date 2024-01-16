/**  \file btu.hpp
 *   \brief This file is used to define the British Thermal Unit (Btu) derived
 * from the base dimension for Energy.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/British_thermal_unit">Btu</a> if needed.
 */

#pragma once

#include "../../definition.hpp"
#include "../../unit.hpp"
#include "joule.hpp"

namespace csm_units {

using BritishThermalUnit =
    Unit<literals::J * std::ratio<50000000, 52752792631>()>;

namespace literals {

constexpr auto BTU =  // NOLINT(readability-identifier-length)
    BritishThermalUnit::def;

constexpr auto Btu =  // NOLINT(readability-identifier-length)
    BritishThermalUnit::def;

constexpr auto operator""_BTU(long double data) noexcept {
  return BritishThermalUnit(static_cast<BritishThermalUnit::ValueType>(data));
}

constexpr auto operator""_BTU(unsigned long long data) noexcept {
  return BritishThermalUnit(static_cast<BritishThermalUnit::ValueType>(data));
}

constexpr auto operator""_Btu(long double data) noexcept {
  return BritishThermalUnit(static_cast<BritishThermalUnit::ValueType>(data));
}

constexpr auto operator""_Btu(unsigned long long data) noexcept {
  return BritishThermalUnit(static_cast<BritishThermalUnit::ValueType>(data));
}

}  // namespace literals

}  // namespace csm_units