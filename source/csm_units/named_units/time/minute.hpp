/**  \file minute.hpp
 *   \brief This file is used to define the unit Minute derived from the base
 * dimension for Time.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Minute">Minute</a> if needed.
 */

#pragma once

#include "../../unit.hpp"
#include "../../unitcast.hpp"
#include "dimension.hpp"

namespace csm_units {

using Minute = Unit<Time, "min", double>;

// Unit Cast for Unit min to Base s
template <>
[[nodiscard]] constexpr auto UnitCast(Minute &&input) noexcept -> Time {
  return Time(input.data * 60);
}

// Unit Cast for Base s to Unit min
template <>
[[nodiscard]] constexpr auto UnitCast(Time &&input) noexcept -> Minute {
  return Minute(input.data / 60);
}

namespace literals {

constexpr auto operator""_min(long double data) noexcept {
  return Minute(static_cast<double>(data));
}

constexpr auto operator""_min(unsigned long long data) noexcept {
  return Minute(static_cast<double>(data));
}

}  // namespace literals

}  // namespace csm_units