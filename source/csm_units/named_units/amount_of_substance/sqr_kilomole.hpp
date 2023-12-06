/**  \file sqr_kilomole.hpp
 *   \brief This file is used to define the unit Square Kilomole derived from
 * the base dimension for Amount of a Substance.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Mole_(unit)">Mole</a> if
 * needed.
 */

#pragma once

#include "../../unit.hpp"
#include "dimension.hpp"

namespace csm_units {

using SqrKilomole = Unit<SqrAmount, "kmol2">;

template <>
[[nodiscard]] constexpr auto UnitCast(SqrAmount &&input) noexcept
    -> SqrKilomole {
  return SqrKilomole(input.data / 1000000);
}

template <>
[[nodiscard]] constexpr auto UnitCast(SqrKilomole &&input) noexcept
    -> SqrAmount {
  return SqrAmount(input.data * 1000000);
}

namespace literals {

constexpr auto operator""_kmol2(long double data) noexcept {
  return SqrKilomole(static_cast<double>(data));
}

constexpr auto operator""_kmol2(unsigned long long data) noexcept {
  return SqrKilomole(static_cast<double>(data));
}

}  // namespace literals

}  // namespace csm_units