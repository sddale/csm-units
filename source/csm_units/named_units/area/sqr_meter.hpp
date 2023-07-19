/**  \file sqr_meter.hpp
 *   \brief This file is used to define the unit Square Meter derived from the
 * base dimension for Area.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Square_metre">Square Meter</a> if needed.
 */

#pragma once

#include "../../unit.hpp"
#include "../../unitcast.hpp"
#include "dimension.hpp"

namespace csm_units {

using SqMeter = Unit<Area, "m2", double>;

// Unit Cast for Base m2
template <>
[[nodiscard]] constexpr auto UnitCast(Area &&input) noexcept -> SqMeter {
  return SqMeter(input.data);
}

// Unit Cast for Unit m2
template <>
[[nodiscard]] constexpr auto UnitCast(SqMeter &&input) noexcept -> Area {
  return Area(input.data);
}

namespace literals {

constexpr auto operator""_m2(long double data) noexcept {
  return SqMeter(static_cast<double>(data));
}

}  // namespace literals

}  // namespace csm_units