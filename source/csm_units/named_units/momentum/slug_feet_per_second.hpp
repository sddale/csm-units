/**  \file slug_feet_per_second.hpp
 *   \brief This file is used to define the unit Slug Feet Per Second derived
 * from the base dimension for Momentum.
 *
 */

#pragma once

#include "../../unit.hpp"
#include "dimension.hpp"

namespace csm_units {

using SlugFeetPerSecond = Unit<Momentum, "slugft/s">;

template <>
[[nodiscard]] constexpr auto UnitCast(Momentum &&input) noexcept
    -> SlugFeetPerSecond {
  return SlugFeetPerSecond(input.data / 4.44822162);
}

template <>
[[nodiscard]] constexpr auto UnitCast(SlugFeetPerSecond &&input) noexcept
    -> Momentum {
  return Momentum(input.data * 4.44822162);
}

namespace literals {

constexpr auto operator""_slugftps(long double data) noexcept {
  return SlugFeetPerSecond(static_cast<double>(data));
}

constexpr auto operator""_slugftps(unsigned long long data) noexcept {
  return SlugFeetPerSecond(static_cast<double>(data));
}

}  // namespace literals

}  // namespace csm_units