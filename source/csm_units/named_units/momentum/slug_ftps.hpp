/**  \file slug_ftps.hpp
 *   \brief This file is used to define the unit slug * ft/s derived from the
 * base dimension for Momentum.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Momentum">Gram</a> if needed.
 */

#pragma once

#include "../../unit.hpp"
#include "../../unitcast.hpp"
#include "dimension.hpp"

namespace csm_units {

using Slug_ftps = Unit<Momentum, "slugftps", double>;

template <>
[[nodiscard]] constexpr auto UnitCast(Momentum &&input) noexcept -> Slug_ftps {
  return Kg_mps(input.data / 4.44822162);
}

template <>
[[nodiscard]] constexpr auto UnitCast(Slug_ftps &&input) noexcept -> Momentum {
  return Momentum(input.data * 4.44822162);
}

namespace literals {

constexpr auto operator""_slugftps(long double data) noexcept {
  return Kg_mps(static_cast<double>(data));
}

constexpr auto operator"" slugftps(unsigned long long data) noexcept {
  return Kg_mps(static_cast<double>(data));
}

}  // namespace literals

}  // namespace csm_units