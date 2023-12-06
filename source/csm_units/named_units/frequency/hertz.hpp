/**  \file hertz.hpp
 *   \brief This file is used to define the Frequency SI unit Hertz.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Hertz">Hertz</a> if needed.
 */

#pragma once

#include "../../unit.hpp"
#include "dimension.hpp"

namespace csm_units {

using Hertz = Unit<Frequency, "Hz">;

// Unit Cast for Base hertz
template <>
[[nodiscard]] constexpr auto UnitCast(Frequency &&input) noexcept -> Hertz {
  return Hertz(input.data);
}

// Unit Cast for Unit hertz
template <>
[[nodiscard]] constexpr auto UnitCast(Hertz &&input) noexcept -> Frequency {
  return Frequency(input.data);
}

namespace literals {

constexpr auto operator""_Hz(long double data) noexcept {
  return Hertz(static_cast<double>(data));
}

constexpr auto operator""_Hz(unsigned long long data) noexcept {
  return Hertz(static_cast<double>(data));
}

}  // namespace literals

}  // namespace csm_units