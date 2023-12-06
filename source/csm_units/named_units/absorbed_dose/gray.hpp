/**  \file gray.hpp
 *   \brief This file is used to define the Absorbed Dose SI unit Gray.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Gray_(unit)">Gray</a> if needed.
 */

#pragma once

#include "../../unit.hpp"
#include "dimension.hpp"

namespace csm_units {

using Gray = Unit<AbsorbedDose, "Gy">;

// Unit Cast for Base Gray
template <>
[[nodiscard]] constexpr auto UnitCast(AbsorbedDose &&input) noexcept -> Gray {
  return Gray(input.data);
}
template <>
[[nodiscard]] constexpr auto UnitCast(Gray &&input) noexcept -> AbsorbedDose {
  return AbsorbedDose(input.data);
}

namespace literals {

constexpr auto operator""_Gy(long double data) noexcept {
  return Gray(static_cast<double>(data));
}

constexpr auto operator""_Gy(unsigned long long data) noexcept {
  return Gray(static_cast<double>(data));
}

}  // namespace literals

}  // namespace csm_units