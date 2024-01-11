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

using Celsius = Unit<literals::K + std::ratio<5463, 20>()>;

namespace literals {

constexpr auto degC =  // NOLINT(readability-identifier-length)
    Celsius::def;

constexpr auto operator""_degC(long double data) noexcept {
  return Celsius(static_cast<Celsius::ValueType>(data));
}

constexpr auto operator""_degC(unsigned long long data) noexcept {
  return Celsius(static_cast<Celsius::ValueType>(data));
}

}  // namespace literals

}  // namespace csm_units