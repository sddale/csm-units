/**  \file cubic_meter.hpp
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

namespace definition {

using CuMeterPerMole = Definition<MolarVolume>;

}

using CuMeterPerMole = Unit<definition::CuMeterPerMole>;

namespace literals {

constexpr auto m3permole =  // NOLINT(readability-identifier-length)
    definition::CuMeterPerMole();

constexpr auto operator""_m3permole(long double data) noexcept {
  return CuMeterPerMole(static_cast<CuMeterPerMole::type>(data));
}

constexpr auto operator""_m3permole(unsigned long long data) noexcept {
  return CuMeterPerMole(static_cast<CuMeterPerMole::type>(data));
}

}  // namespace literals

}  // namespace csm_units
