/**  \file kg_mps.hpp
 *   \brief This file is used to define the Momentum SI unit Kg * m/s.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Momentum">Gram</a> if needed.
 */

#pragma once

#include "../../unit.hpp"
#include "../../unitcast.hpp"
#include "dimension.hpp"

namespace csm_units {

using Kg_mps = Unit<Momentum, "kgmps", double>;

template <>
[[nodiscard]] constexpr auto UnitCast(Momentum &&input) noexcept -> Kg_mps {
  return Kg_mps(input.data);
}

template <>
[[nodiscard]] constexpr auto UnitCast(Kg_mps &&input) noexcept -> Momentum {
  return Momentum(input.data);
}

namespace literals {

constexpr auto operator""_kgmps(long double data) noexcept {
  return Kg_mps(static_cast<double>(data));
}

constexpr auto operator""_kgmps(unsigned long long data) noexcept {
  return Kg_mps(static_cast<double>(data));
}

}  // namespace literals

}  // namespace csm_units