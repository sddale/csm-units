/**  \file joule_per_mole_kelvin.hpp
 *   \brief This file is used to define the Molar Heat Capacity SI unit Joule
 * per Mole per Kelvin.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Molar_heat_capacity">Joule Per Mole
 * Per Kelvin</a> if needed.
 */
#pragma once

#include "../../definition.hpp"
#include "../../unit.hpp"
#include "dimension.hpp"

namespace csm_units {

using JoulePerMoleKelvin = Unit<Definition<MolarHeatCapacity>{}>;

namespace literals {

constexpr auto JpermolK =  // NOLINT(readability-identifier-length)
    JoulePerMoleKelvin::def;

constexpr auto operator""_JpermolK(long double data) noexcept {
  return JoulePerMoleKelvin(static_cast<JoulePerMoleKelvin::ValueType>(data));
}

constexpr auto operator""_JpermolK(unsigned long long data) noexcept {
  return JoulePerMoleKelvin(static_cast<JoulePerMoleKelvin::ValueType>(data));
}

}  // namespace literals

}  // namespace csm_units