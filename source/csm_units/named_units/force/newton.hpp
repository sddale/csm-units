/**  \file newton.hpp
 *   \brief This file is used to define the Force SI unit Newton.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Newton_(unit)">Newton</a> if needed.
 */

#pragma once

#include "../../unit.hpp"
#include "../../unitcast.hpp"
#include "dimension.hpp"

namespace csm_units {

using Newton = Unit<Force, "N", double>;

// Unit Cast for Base Newton
template <>
[[nodiscard]] constexpr auto UnitCast(Force &&input) noexcept -> Newton {
  return Newton(input.data);
}
template <>
[[nodiscard]] constexpr auto UnitCast(Newton &&input) noexcept -> Force {
  return Force(input.data);
}

namespace literals {

constexpr auto operator""_N(long double data) noexcept {
  return Newton(static_cast<double>(data));
}

}  // namespace literals

}  // namespace csm_units