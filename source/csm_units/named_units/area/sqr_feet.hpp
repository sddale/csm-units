/**  \file sqr_feet.hpp
 *   \brief This file is used to define the unit Square Foot derived from the
 * base dimension for Area.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Square_foot">Square Foot</a> if needed.
 */

#pragma once

#include "../../unit.hpp"
#include "../../unitcast.hpp"
#include "dimension.hpp"

namespace csm_units {

using SqFt = Unit<Area, "ft2", double>;

// Unit Cast for Base area to ft2
template <>
[[nodiscard]] constexpr auto UnitCast(Area &&input) noexcept -> SqFt {
  return SqFt(input.data * 10.764);
}

// Unit Cast for Unit ft2 to base area
template <>
[[nodiscard]] constexpr auto UnitCast(SqFt &&input) noexcept -> Area {
  return Area(input.data / 10.764);
}

namespace literals {

constexpr auto operator""_ft2(long double data) noexcept {
  return SqFt(static_cast<double>(data));
}

}  // namespace literals

}  // namespace csm_units