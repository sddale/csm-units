/**  \file sievert.hpp
 *   \brief This file is used to define the Dose Equivalent SI unit Sievert.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Sievert">Sievert</a> if needed.
 */

#pragma once

#include "../../unit.hpp"
#include "dimension.hpp"

namespace csm_units {

using Sievert = Unit<DoseEquivalent, "Sv", double>;

// Unit Cast for Base Sievert
template <>
[[nodiscard]] constexpr auto UnitCast(DoseEquivalent input) noexcept
    -> Sievert {
  return Sievert(input.data);
}
template <>
[[nodiscard]] constexpr auto UnitCast(Sievert input) noexcept
    -> DoseEquivalent {
  return DoseEquivalent(input.data);
}

namespace literals {

constexpr auto operator""_Sv(long double data) noexcept {
  return Sievert(static_cast<double>(data));
}

constexpr auto operator""_Sv(unsigned long long data) noexcept {
  return Sievert(static_cast<double>(data));
}

}  // namespace literals

}  // namespace csm_units