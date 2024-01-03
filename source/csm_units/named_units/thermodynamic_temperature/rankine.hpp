/**  \file rankine.hpp
 *   \brief This file is used to define the Thermodynamic Temperature SI unit
 * Kelvin.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Rankine_scale">Rankine</a> if needed.
 */

#pragma once

#include "../../definition.hpp"
#include "../../unit.hpp"
#include "dimension.hpp"

namespace csm_units {

namespace definition {

using Rankine = Definition<Temperature, std::ratio<1>, std::ratio<1>,
                           std::ratio<1>, std::ratio<1>, std::ratio<9, 5>>;

}

using Rankine = Unit<definition::Rankine>;

namespace literals {

constexpr auto degR =  // NOLINT(readability-identifier-length)
    definition::Rankine();

constexpr auto operator""_degR(long double data) noexcept {
  return Rankine(static_cast<Rankine::type>(data));
}

constexpr auto operator""_degR(unsigned long long data) noexcept {
  return Rankine(static_cast<Rankine::type>(data));
}

}  // namespace literals

}  // namespace csm_units
