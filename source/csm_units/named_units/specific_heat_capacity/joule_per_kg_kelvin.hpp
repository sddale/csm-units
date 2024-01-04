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
#include "dimension.hpp"

namespace csm_units {

namespace definition {

using JoulePerKilogramKelvin =
    decltype(literals::J / (literals::kg * literals::K));
static_assert(
    std::is_same_v<JoulePerKilogramKelvin::dim, SpecificHeatCapacity>);

}  // namespace definition

using JoulePerKilogramKelvin = Unit<definition::JoulePerKilogramKelvin>;

namespace literals {

constexpr auto JperkgK =  // NOLINT(readability-identifier-length)
    definition::JoulePerKilogramKelvin();

constexpr auto operator""_JperkgK(long double data) noexcept {
  return JoulePerKilogramKelvin(
      static_cast<JoulePerKilogramKelvin::type>(data));
}

constexpr auto operator""_JperkgK(unsigned long long data) noexcept {
  return JoulePerKilogramKelvin(
      static_cast<JoulePerKilogramKelvin::type>(data));
}

}  // namespace literals

}  // namespace csm_units
