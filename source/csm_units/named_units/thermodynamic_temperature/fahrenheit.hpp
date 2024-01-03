/**  \file fahrenheit.hpp
 *   \brief This file is used to define the unit Fahrenheit derived from the
 * base dimension for Thermodynamic Temperature.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Fahrenheit">Fahrenheit</a> if needed.
 */

#pragma once

#include "../../unit.hpp"
#include "rankine.hpp"

namespace csm_units {

using Fahrenheit =
    Unit<definition::Rankine, Rankine::type, std::ratio<45967, 180>>;

namespace literals {

// TODO literals for relative units

constexpr auto operator""_degF(long double data) noexcept {
  return Fahrenheit(static_cast<Fahrenheit::type>(data));
}

constexpr auto operator""_degF(unsigned long long data) noexcept {
  return Fahrenheit(static_cast<Fahrenheit::type>(data));
}

}  // namespace literals

}  // namespace csm_units