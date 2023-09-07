/**  \file gram.hpp
 *   \brief This file is used to define the unit Gram derived from the base
 * dimension for Mass.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Gram">Gram</a> if needed.
 */

#pragma once

#include "../../unit.hpp"
#include "../../unitcast.hpp"
#include "dimension.hpp"

namespace csm_units {

using Gram = Unit<Mass, "g", double>;

// Unit Cast for Base g to Unit g
template <>
[[nodiscard]] constexpr auto UnitCast(Mass &&input) noexcept -> Gram {
  return Gram(input.data * 1000);
}

// Unit Cast for Unit g to Base g
template <>
[[nodiscard]] constexpr auto UnitCast(Gram &&input) noexcept -> Mass {
  return Mass(input.data / 1000);
}

namespace literals {

constexpr auto operator""_g(long double data) noexcept {
  return Gram(static_cast<double>(data));
}

constexpr auto operator""_g(unsigned long long data) noexcept {
  return Gram(static_cast<double>(data));
}

}  // namespace literals

}  // namespace csm_units