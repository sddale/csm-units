/**  \file hour.hpp
 *   \brief This file is used to define the unit Hour derived from the base
 * dimension for Time.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Hour">Hour</a> if needed.
 */

#pragma once

#include "../../unit.hpp"
#include "../../unitcast.hpp"
#include "dimension.hpp"

namespace csm_units {

using Hour = Unit<Time, "hour", double>;

// Unit Cast for Unit min to Base s
template <>
[[nodiscard]] constexpr auto UnitCast(Hour &&input) noexcept -> Time {
  return Time(input.data * 3600);
}

// Unit Cast for Base s to Unit min
template <>
[[nodiscard]] constexpr auto UnitCast(Time &&input) noexcept -> Hour {
  return Hour(input.data / 3600);
}

namespace literals {

constexpr auto operator""_hour(long double data) noexcept {
  return Hour(static_cast<double>(data));
}

constexpr auto operator""_hour(unsigned long long data) noexcept {
  return Hour(static_cast<double>(data));
}

}  // namespace literals

}  // namespace csm_units