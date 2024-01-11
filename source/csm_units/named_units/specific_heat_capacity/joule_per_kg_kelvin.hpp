/**  \file joules_per_kelvin.hpp
 *   \brief This file is used to define the Specific Heat Capacity SI unit
 * Joules per Kilogram per Kelvin.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Specific_heat_capacity">Joules Per
 * Kilogram Per Kelvin</a> if needed.
 */

#pragma once

#include "../../definition.hpp"
#include "../../unit.hpp"
#include "../energy/joule.hpp"
#include "../mass/kilogram.hpp"
#include "../thermodynamic_temperature/kelvin.hpp"

namespace csm_units {

using JoulePerKilogramKelvin = Unit<literals::J / (literals::kg * literals::K)>;

namespace literals {

constexpr auto JperkgK =  // NOLINT(readability-identifier-length)
    JoulePerKilogramKelvin::def;

constexpr auto operator""_JperkgK(long double data) noexcept {
  return JoulePerKilogramKelvin(
      static_cast<JoulePerKilogramKelvin::ValueType>(data));
}

constexpr auto operator""_JperkgK(unsigned long long data) noexcept {
  return JoulePerKilogramKelvin(
      static_cast<JoulePerKilogramKelvin::ValueType>(data));
}

}  // namespace literals

}  // namespace csm_units
