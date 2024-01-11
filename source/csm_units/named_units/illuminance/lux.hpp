/**  \file lux.hpp
 *   \brief This file is used to define the Illuminance SI unit Lux.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Lux">Lux</a> if needed.
 */

#pragma once

#include "../../definition.hpp"
#include "../../unit.hpp"
#include "dimension.hpp"

namespace csm_units {

namespace definition {

using Lux = Definition<Illuminance>;

}

using Lux = Unit<definition::Lux>;

namespace literals {

constexpr auto lx =  // NOLINT(readability-identifier-length)
    Lux::def;

constexpr auto operator""_lx(long double data) noexcept {
  return Lux(static_cast<Lux::ValueType>(data));
}

constexpr auto operator""_lx(unsigned long long data) noexcept {
  return Lux(static_cast<Lux::ValueType>(data));
}

}  // namespace literals

}  // namespace csm_units
