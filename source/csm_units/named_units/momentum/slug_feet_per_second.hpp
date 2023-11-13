/**  \file slug_feet_per_second.hpp
 *   \brief This file is used to define the unit slug * ft/s derived from the
 * base dimension for Momentum.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Momentum">Momentum</a> if needed.
 */

#pragma once

#include "../../unit.hpp"
#include "../../unitcast.hpp"
#include "dimension.hpp"

namespace csm_units {

using SlugFTPS = Unit<Momentum, "slugftps", double>;

template <>
[[nodiscard]] constexpr auto UnitCast(Momentum &&input) noexcept -> SlugFTPS {
  return SlugFTPS(input.data / 4.44822162);
}

template <>
[[nodiscard]] constexpr auto UnitCast(SlugFTPS &&input) noexcept -> Momentum {
  return Momentum(input.data * 4.44822162);
}

namespace literals {

constexpr auto operator""_slugftps(long double data) noexcept {
  return SlugFTPS(static_cast<double>(data));
}

constexpr auto operator"" slugftps(unsigned long long data) noexcept {
  return SlugFTPS(static_cast<double>(data));
}

}  // namespace literals

}  // namespace csm_units