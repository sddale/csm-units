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

namespace definition {

using Kelvin = Definition<Temperature>;

}

using Kelvin = Unit<definition::Kelvin>;

namespace literals {

constexpr auto K =  // NOLINT(readability-identifier-length)
    definition::Kelvin();

constexpr auto operator""_K(long double data) noexcept {
  return Kelvin(static_cast<Kelvin::type>(data));
}

constexpr auto operator""_K(unsigned long long data) noexcept {
  return Kelvin(static_cast<Kelvin::type>(data));
}

}  // namespace literals

}  // namespace csm_units
