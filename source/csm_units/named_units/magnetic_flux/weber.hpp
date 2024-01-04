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

namespace definition {

using Weber = Definition<MagneticFlux>;

}

using Weber = Unit<definition::Weber>;

namespace literals {

constexpr auto Wb =  // NOLINT(readability-identifier-length)
    definition::Weber();

constexpr auto operator""_Wb(long double data) noexcept {
  return Weber(static_cast<Weber::type>(data));
}

constexpr auto operator""_Wb(unsigned long long data) noexcept {
  return Weber(static_cast<Weber::type>(data));
}

}  // namespace literals

}  // namespace csm_units