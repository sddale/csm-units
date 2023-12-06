/**  \file lux.hpp
 *   \brief This file is used to define the Illuminance SI unit Lux.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Lux">Lux</a> if needed.
 */

#pragma once

#include "../../unit.hpp"
#include "dimension.hpp"

namespace csm_units {

using Lux = Unit<Illuminance, "lx">;

template <>
[[nodiscard]] constexpr auto UnitCast(Illuminance &&input) noexcept -> Lux {
  return Lux(input.data);
}

// Unit Cast for Unit Newton
template <>
[[nodiscard]] constexpr auto UnitCast(Lux &&input) noexcept -> Illuminance {
  return Illuminance(input.data);
}

namespace literals {

constexpr auto operator""_lx(long double data) noexcept {
  return Lux(static_cast<double>(data));
}

constexpr auto operator""_lx(unsigned long long data) noexcept {
  return Lux(static_cast<double>(data));
}

}  // namespace literals

}  // namespace csm_units