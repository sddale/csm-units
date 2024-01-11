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
#include "kelvin.hpp"

namespace csm_units {

using Rankine = Unit<literals::K * std::ratio<9, 5>()>;

namespace literals {

constexpr auto degR =  // NOLINT(readability-identifier-length)
    Rankine::definition;

constexpr auto operator""_degR(long double data) noexcept {
  return Rankine(static_cast<Rankine::ValueType>(data));
}

constexpr auto operator""_degR(unsigned long long data) noexcept {
  return Rankine(static_cast<Rankine::ValueType>(data));
}

}  // namespace literals

}  // namespace csm_units
