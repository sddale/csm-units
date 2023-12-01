/**  \file siemens.hpp
 *   \brief This file is used to define the Conductance SI unit Siemens.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Siemens_(unit)">Siemens</a> if needed.
 */

#pragma once

#include "../../unit.hpp"
#include "dimension.hpp"

namespace csm_units {

using Siemens = Unit<Conductance, "S", double>;

// Unit Cast for Base Siemens
template <>
[[nodiscard]] constexpr auto UnitCast(Conductance input) noexcept -> Siemens {
  return Siemens(input.data);
}
template <>
[[nodiscard]] constexpr auto UnitCast(Siemens input) noexcept -> Conductance {
  return Conductance(input.data);
}

namespace literals {

constexpr auto operator""_S(long double data) noexcept {
  return Siemens(static_cast<double>(data));
}

constexpr auto operator""_S(unsigned long long data) noexcept {
  return Siemens(static_cast<double>(data));
}

}  // namespace literals

}  // namespace csm_units