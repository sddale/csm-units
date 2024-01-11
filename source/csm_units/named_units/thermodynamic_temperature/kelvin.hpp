/**  \file kelvin.hpp
 *   \brief This file is used to define the Thermodynamic Temperature SI unit
 * Kelvin.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Kelvin">Kelvin</a> if needed.
 */

#pragma once

#include "../../definition.hpp"
#include "../../unit.hpp"
#include "dimension.hpp"

namespace csm_units {

using Kelvin = Unit<Definition<Temperature>{}>;

namespace literals {

constexpr auto K =  // NOLINT(readability-identifier-length)
    Kelvin::def;

constexpr auto operator""_K(long double data) noexcept {
  return Kelvin(static_cast<Kelvin::ValueType>(data));
}

constexpr auto operator""_K(unsigned long long data) noexcept {
  return Kelvin(static_cast<Kelvin::ValueType>(data));
}

}  // namespace literals

}  // namespace csm_units
