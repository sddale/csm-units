/**  \file volt.hpp
 *   \brief This file is used to define the Potential SI unit Volt.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Volt">Volt</a> if needed.
 */

#pragma once

#include "../../unit.hpp"
#include "dimension.hpp"

namespace csm_units {

using Volt = Unit<Potential, "V", double>;

// Unit Cast for Base Volt
template <>
[[nodiscard]] constexpr auto UnitCast(Potential input) noexcept -> Volt {
  return Volt(input.data);
}
template <>
[[nodiscard]] constexpr auto UnitCast(Volt input) noexcept -> Potential {
  return Potential(input.data);
}

namespace literals {

constexpr auto operator""_V(long double data) noexcept {
  return Volt(static_cast<double>(data));
}

constexpr auto operator""_V(unsigned long long data) noexcept {
  return Volt(static_cast<double>(data));
}

}  // namespace literals

}  // namespace csm_units