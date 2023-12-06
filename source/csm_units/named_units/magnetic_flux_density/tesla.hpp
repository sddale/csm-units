/**  \file tesla.hpp
 *   \brief This file is used to define the Magnetic Flux Density SI unit Tesla.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Tesla_(unit)">Tesla</a> if needed.
 */

#pragma once

#include "../../unit.hpp"
#include "dimension.hpp"

namespace csm_units {

using Tesla = Unit<MagneticFluxDensity, "T">;

// Unit Cast for Base tesla
template <>
[[nodiscard]] constexpr auto UnitCast(MagneticFluxDensity &&input) noexcept
    -> Tesla {
  return Tesla(input.data);
}

// Unit Cast for Unit tesla
template <>
[[nodiscard]] constexpr auto UnitCast(Tesla &&input) noexcept
    -> MagneticFluxDensity {
  return MagneticFluxDensity(input.data);
}

namespace literals {

constexpr auto operator""_T(long double data) noexcept {
  return Tesla(static_cast<double>(data));
}

constexpr auto operator""_T(unsigned long long data) noexcept {
  return Tesla(static_cast<double>(data));
}

}  // namespace literals

}  // namespace csm_units