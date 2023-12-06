/**  \file watt.hpp
 *   \brief This file is used to define the Power SI unit Watt.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Watt">Watt</a> if needed.
 */

#pragma once

#include "../../unit.hpp"
#include "dimension.hpp"

namespace csm_units {

using Watt = Unit<Power, "W">;

// Unit Cast for Base Watt
template <>
[[nodiscard]] constexpr auto UnitCast(Power &&input) noexcept -> Watt {
  return Watt(input.data);
}
template <>
[[nodiscard]] constexpr auto UnitCast(Watt &&input) noexcept -> Power {
  return Power(input.data);
}

namespace literals {

constexpr auto operator""_W(long double data) noexcept {
  return Watt(static_cast<double>(data));
}

constexpr auto operator""_W(unsigned long long data) noexcept {
  return Watt(static_cast<double>(data));
}

}  // namespace literals

}  // namespace csm_units