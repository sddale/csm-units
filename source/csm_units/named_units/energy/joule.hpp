/**  \file joule.hpp
 *   \brief This file is used to define the Energy SI unit Joule.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Joule">Joule</a> if needed.
 */

#pragma once

#include "../../unit.hpp"
#include "../../unitcast.hpp"
#include "dimension.hpp"

namespace csm_units {

using Joule = Unit<Energy, "J", double>;

// Unit Cast for Base Joule
template <>
[[nodiscard]] constexpr auto UnitCast(Energy &&input) noexcept -> Joule {
  return Joule(input.data);
}
template <>
[[nodiscard]] constexpr auto UnitCast(Joule &&input) noexcept -> Energy {
  return Energy(input.data);
}

namespace literals {

constexpr auto operator""_J(long double data) noexcept {
  return Joule(static_cast<double>(data));
}

constexpr auto operator""_J(unsigned long long data) noexcept {
  return Joule(static_cast<double>(data));
}

}  // namespace literals

}  // namespace csm_units