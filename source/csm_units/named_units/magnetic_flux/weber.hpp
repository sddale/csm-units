#pragma once

#include "../../unit.hpp"
#include "../../unitcast.hpp"
#include "dimension.hpp"

namespace csm_units {

using Weber = Unit<MagneticFlux, "Wb", double>;

// Unit Cast for Base weber
template <>
[[nodiscard]] constexpr auto UnitCast(MagneticFlux &&input) noexcept -> Weber {
  return Weber(input.data);
}

// Unit Cast for Unit weber
template <>
[[nodiscard]] constexpr auto UnitCast(Weber &&input) noexcept -> MagneticFlux {
  return MagneticFlux(input.data);
}

namespace literals {

constexpr auto operator""_Wb(long double data) noexcept {
  return Weber(static_cast<double>(data));
}

}  // namespace literals

}  // namespace csm_units