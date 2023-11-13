/**  \file KgMPS.hpp
 *   \brief This file is used to define the Momentum SI unit Kg * m/s.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Momentum">Momentum</a> if needed.
 */

#pragma once

#include "../../unit.hpp"
#include "../../unitcast.hpp"
#include "dimension.hpp"

namespace csm_units {

using KgMPS = Unit<Momentum, "kgmps", double>;

template <>
[[nodiscard]] constexpr auto UnitCast(Momentum &&input) noexcept -> KgMPS {
  return KgMPS(input.data);
}

template <>
[[nodiscard]] constexpr auto UnitCast(KgMPS &&input) noexcept -> Momentum {
  return Momentum(input.data);
}

namespace literals {

constexpr auto operator""_kgmps(long double data) noexcept {
  return KgMPS(static_cast<double>(data));
}

constexpr auto operator""_kgmps(unsigned long long data) noexcept {
  return KgMPS(static_cast<double>(data));
}

}  // namespace literals

}  // namespace csm_units