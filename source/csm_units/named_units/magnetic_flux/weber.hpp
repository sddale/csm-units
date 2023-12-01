/**  \file weber.hpp
 *   \brief This file is used to define the Magnetic Flux SI unit Weber.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Weber_(unit)">Weber</a> if needed.
 */

#pragma once

#include "../../unit.hpp"
#include "../../unitcast.hpp"
#include "dimension.hpp"

namespace csm_units {

using Weber = Unit<MagneticFlux, "Wb", double>;

// Unit Cast for Base weber
template <>
[[nodiscard]] constexpr auto UnitCast(MagneticFlux input) noexcept -> Weber {
  return Weber(input.data);
}

// Unit Cast for Unit weber
template <>
[[nodiscard]] constexpr auto UnitCast(Weber input) noexcept -> MagneticFlux {
  return MagneticFlux(input.data);
}

namespace literals {

constexpr auto operator""_Wb(long double data) noexcept {
  return Weber(static_cast<double>(data));
}

constexpr auto operator""_Wb(unsigned long long data) noexcept {
  return Weber(static_cast<double>(data));
}

}  // namespace literals

}  // namespace csm_units