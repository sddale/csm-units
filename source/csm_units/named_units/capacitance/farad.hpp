/**  \file farad.hpp
 *   \brief This file is used to define the Capacitance SI unit Farad.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Farad">Farad</a> if needed.
 */

#pragma once

#include "../../unit.hpp"
#include "dimension.hpp"

namespace csm_units {

using Farad = Unit<Capacitance, "F">;

// Unit Cast for Base farad
template <>
[[nodiscard]] constexpr auto UnitCast(Capacitance &&input) noexcept -> Farad {
  return Farad(input.data);
}

// Unit Cast for Unit farad
template <>
[[nodiscard]] constexpr auto UnitCast(Farad &&input) noexcept -> Capacitance {
  return Capacitance(input.data);
}

namespace literals {

constexpr auto operator""_F(long double data) noexcept {
  return Farad(static_cast<double>(data));
}

constexpr auto operator""_F(unsigned long long data) noexcept {
  return Farad(static_cast<double>(data));
}

}  // namespace literals

}  // namespace csm_units