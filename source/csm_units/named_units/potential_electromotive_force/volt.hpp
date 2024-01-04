/**  \file volt.hpp
 *   \brief This file is used to define the Potential SI unit Volt.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Volt">Volt</a> if needed.
 */

#pragma once

#include "../../definition.hpp"
#include "../../unit.hpp"
#include "dimension.hpp"

namespace csm_units {

namespace definition {

using Volt = Definition<PotentialElectromotiveForce>;

}

using Volt = Unit<definition::Volt>;

namespace literals {

constexpr auto V =  // NOLINT(readability-identifier-length)
    definition::Volt();

constexpr auto operator""_V(long double data) noexcept {
  return Volt(static_cast<Volt::type>(data));
}

constexpr auto operator""_V(unsigned long long data) noexcept {
  return Volt(static_cast<Volt::type>(data));
}

}  // namespace literals

}  // namespace csm_units