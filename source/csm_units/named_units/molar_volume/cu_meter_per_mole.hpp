/**  \file cu_meter_per_mole.hpp
 *   \brief This file is used to define the MolarVolume SI unit Cubic Meter Per
 * Mole.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Molar_volume">Cubic Meter Per Mole</a> if
 * needed.
 */

#pragma once

#include "../../definition.hpp"
#include "../../unit.hpp"
#include "dimension.hpp"

namespace csm_units {

using CuMeterPerMole = Unit<Definition<MolarVolume>{}>;

namespace literals {

constexpr auto m3permole =  // NOLINT(readability-identifier-length)
    CuMeterPerMole::def;

constexpr auto operator""_m3permole(long double data) noexcept {
  return CuMeterPerMole(static_cast<CuMeterPerMole::ValueType>(data));
}

constexpr auto operator""_m3permole(unsigned long long data) noexcept {
  return CuMeterPerMole(static_cast<CuMeterPerMole::ValueType>(data));
}

}  // namespace literals

}  // namespace csm_units
