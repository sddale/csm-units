/**  \file joules_per_kelvin.hpp
 *   \brief This file is used to define the Heat Capacity SI unit Joules per
 * Kelvin.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Heat_capacity">Joules Per Kelvin</a> if
 * needed.
 */
#pragma once

#include "../../definition.hpp"
#include "../../unit.hpp"
#include "dimension.hpp"

namespace csm_units {

using JoulesPerKelvin = Unit<Definition<HeatCapacity>{}>;

namespace literals {

constexpr auto JperK =  // NOLINT(readability-identifier-length)
    JoulesPerKelvin::def;

constexpr auto operator""_JperK(long double data) noexcept {
  return JoulesPerKelvin(static_cast<JoulesPerKelvin::ValueType>(data));
}

constexpr auto operator""_JperK(unsigned long long data) noexcept {
  return JoulesPerKelvin(static_cast<JoulesPerKelvin::ValueType>(data));
}

}  // namespace literals

}  // namespace csm_units
