/**  \file seconds.hpp
 *   \brief This file is used to define the Time SI unit Seconds.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Second">Seconds</a> if needed.
 */

#pragma once

#include "../../unit.hpp"
#include "../../unitcast.hpp"
#include "dimension.hpp"

namespace csm_units {

using Second = Unit<Time, "s", double>;

// Unit Cast for Unit s to Base s
template <>
[[nodiscard]] constexpr auto UnitCast(Second &&input) noexcept -> Time {
  return Time(input.data);
}

// Unit Cast for Base s to Unit s
template <>
[[nodiscard]] constexpr auto UnitCast(Time &&input) noexcept -> Second {
  return Second(input.data);
}

namespace literals {

// time - second
constexpr auto operator""_s(long double data) noexcept {
  return Second(static_cast<double>(data));
}

}  // namespace literals

}  // namespace csm_units