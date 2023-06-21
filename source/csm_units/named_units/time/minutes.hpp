/**  \file minutes.hpp
 *   \brief This file is used to define the unit Minutes derived from the base
 * dimension for Time.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Minute">Minutes</a> if needed.
 */

#pragma once

#include "../../unit.hpp"
#include "../../unitcast.hpp"
#include "dimension.hpp"

namespace csm_units {

using Minutes = Unit<Time, "min", double>;

// Unit Cast for Unit min to Base s
template <>
[[nodiscard]] constexpr auto UnitCast(Minutes &&input) noexcept -> Time {
  return Time(input.data * 60);
}

// Unit Cast for Base s to Unit min
template <>
[[nodiscard]] constexpr auto UnitCast(Time &&input) noexcept -> Minutes {
  return Minutes(input.data / 60);
}

namespace literals {

constexpr auto operator""_min(long double data) noexcept {
  return Minutes(static_cast<double>(data));
}

}  // namespace literals

}  // namespace csm_units