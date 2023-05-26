#pragma once

#include "../../unit.hpp"
#include "../../unitcast.hpp"
#include "dimension.hpp"

namespace csm_units {

using Kelvin = Unit<Temperature, "K", double>;  // ---- Temperature

// Unit Cast for Unit Kelvin
template <>
[[nodiscard]] constexpr auto UnitCast(Temperature &&input) noexcept -> Kelvin {
  return Kelvin(input.data);
}

// Unit Cast for Unit Kelvin
template <>
[[nodiscard]] constexpr auto UnitCast(Kelvin &&input) noexcept -> Temperature {
  return Temperature(input.data);
}

}  // namespace csm_units