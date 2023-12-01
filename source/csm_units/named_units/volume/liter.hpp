/**  \file liter.hpp
 *   \brief This file is used to define the unit Liter derived from the base
 * dimension for Volume.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Litre">Liter</a> if needed.
 */

#pragma once

#include "../../unit.hpp"
#include "../../unitcast.hpp"
#include "dimension.hpp"

namespace csm_units {

using Liter = Unit<Volume, "L", double>;

// Unit Cast for base
template <>
[[nodiscard]] constexpr auto UnitCast(Volume input) noexcept -> Liter {
  return Liter(input.data * 1000);
}

// Unit Cast for Unit Liter
template <>
[[nodiscard]] constexpr auto UnitCast(Liter input) noexcept -> Volume {
  return Volume(input.data / 1000);
}

namespace literals {

constexpr auto operator""_L(long double data) noexcept {
  return Liter(static_cast<double>(data));
}

constexpr auto operator""_L(unsigned long long data) noexcept {
  return Liter(static_cast<double>(data));
}

}  // namespace literals

}  // namespace csm_units