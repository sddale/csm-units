/**  \file celsius.hpp
 *   \brief This file is used to define the unit Celsius derived from the base
 * dimension for Thermodynamic Temperature.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Celsius">Celsius</a> if needed.
 */

#pragma once

#include "../../unit.hpp"
#include "kelvin.hpp"

namespace csm_units {

using Celsius = Unit<definition::Kelvin, Kelvin::type, std::ratio<5463, 20>>;

namespace literals {

// TODO literals for relative units

constexpr auto operator""_degC(long double data) noexcept {
  return Celsius(static_cast<Celsius::type>(data));
}

constexpr auto operator""_degC(unsigned long long data) noexcept {
  return Celsius(static_cast<Celsius::type>(data));
}

}  // namespace literals

}  // namespace csm_units