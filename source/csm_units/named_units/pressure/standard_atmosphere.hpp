/**  \file atm.hpp
 *   \brief This file is used to define the unit Standard Atmosphere derived
 * from the base dimension for Pressure.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Standard_atmosphere_(unit)">Atmosphere</a>
 * if needed.
 */

#pragma once

#include "../../definition.hpp"
#include "../../unit.hpp"
#include "pascal.hpp"

namespace csm_units {

using StandardAtmosphere = Unit<literals::Pa * std::ratio<1, 101325>()>;

namespace literals {

constexpr auto atm =  // NOLINT(readability-identifier-length)
    StandardAtmosphere::def;

constexpr auto operator""_atm(long double data) noexcept {
  return StandardAtmosphere(static_cast<StandardAtmosphere::ValueType>(data));
}

constexpr auto operator""_atm(unsigned long long data) noexcept {
  return StandardAtmosphere(static_cast<StandardAtmosphere::ValueType>(data));
}

}  // namespace literals

}  // namespace csm_units