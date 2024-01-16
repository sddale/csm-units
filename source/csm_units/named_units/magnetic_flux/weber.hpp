/**  \file weber.hpp
 *   \brief This file is used to define the Magnetic Flux SI unit Weber.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Weber_(unit)">Weber</a> if needed.
 */

#pragma once

#include "../../definition.hpp"
#include "../../unit.hpp"
#include "dimension.hpp"

namespace csm_units {

using Weber = Unit<Definition<MagneticFlux>{}>;

namespace literals {

constexpr auto Wb =  // NOLINT(readability-identifier-length)
    Weber::def;

constexpr auto operator""_Wb(long double data) noexcept {
  return Weber(static_cast<Weber::ValueType>(data));
}

constexpr auto operator""_Wb(unsigned long long data) noexcept {
  return Weber(static_cast<Weber::ValueType>(data));
}

}  // namespace literals

}  // namespace csm_units