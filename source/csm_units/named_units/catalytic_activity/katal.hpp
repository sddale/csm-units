/**  \file katal.hpp
 *   \brief This file is used to define the Absorbed Dose SI unit Katal.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Katal">Katal</a> if needed.
 */

#pragma once

#include "../../unit.hpp"
#include "dimension.hpp"

namespace csm_units {

using Katal = Unit<CatalyticActivity, "kat">;

// Unit Cast for Base katal
template <>
[[nodiscard]] constexpr auto UnitCast(CatalyticActivity &&input) noexcept
    -> Katal {
  return Katal(input.data);
}

// Unit Cast for Unit katal
template <>
[[nodiscard]] constexpr auto UnitCast(Katal &&input) noexcept
    -> CatalyticActivity {
  return CatalyticActivity(input.data);
}

namespace literals {

constexpr auto operator""_kat(long double data) noexcept {
  return Katal(static_cast<double>(data));
}

constexpr auto operator""_kat(unsigned long long data) noexcept {
  return Katal(static_cast<double>(data));
}

}  // namespace literals

}  // namespace csm_units