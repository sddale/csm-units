/**  \file lumen.hpp
 *   \brief This file is used to define the Luminous Flux SI unit Lumen.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Lumen_(unit)">Lumen</a> if needed.
 */

#pragma once

#include "../../unit.hpp"
#include "../../unitcast.hpp"
#include "dimension.hpp"

namespace csm_units {

using Lumen = Unit<LuminousFlux, "lm", double>;

template <>
[[nodiscard]] constexpr auto UnitCast(LuminousFlux &&input) noexcept -> Lumen {
  return Lumen(input.data);
}

// Unit Cast for Unit Lumen
template <>
[[nodiscard]] constexpr auto UnitCast(Lumen &&input) noexcept -> LuminousFlux {
  return LuminousFlux(input.data);
}

namespace literals {

constexpr auto operator""_lm(long double data) noexcept {
  return Lumen(static_cast<double>(data));
}

constexpr auto operator""_lm(unsigned long long data) noexcept {
  return Lumen(static_cast<double>(data));
}

}  // namespace literals

}  // namespace csm_units