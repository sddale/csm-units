/**  \file joule_per_kelvin.hpp
 *   \brief This file is used to define the Specific Heat Capacity SI unit
 * Joule per Kilogram per Kelvin.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Specific_heat_capacity">Joule Per
 * Kilogram Per Kelvin</a> if needed.
 */

#pragma once

#include "../../definition.hpp"
#include "../../unit.hpp"
#include "../energy/joule.hpp"
#include "../mass/kilogram.hpp"
#include "../thermodynamic_temperature/kelvin.hpp"

namespace csm_units {

using JoulesPerKilogramKelvin =
    Unit<literals::J / (literals::kg * literals::K)>;

namespace literals {

constexpr auto JperkgK =  // NOLINT(readability-identifier-length)
    JoulesPerKilogramKelvin::def;

constexpr auto operator""_JperkgK(long double data) noexcept {
  return JoulesPerKilogramKelvin(
      static_cast<JoulesPerKilogramKelvin::ValueType>(data));
}

constexpr auto operator""_JperkgK(unsigned long long data) noexcept {
  return JoulesPerKilogramKelvin(
      static_cast<JoulesPerKilogramKelvin::ValueType>(data));
}

}  // namespace literals

}  // namespace csm_units
