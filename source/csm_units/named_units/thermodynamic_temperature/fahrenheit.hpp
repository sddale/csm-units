#pragma once

#include "../../unit.hpp"
#include "../../unitcast.hpp"
#include "dimension.hpp"

namespace csm_units {

using Fahrenheit = Unit<Temperature, "F", double>;

// Unit Cast for Base K to Unit F
template <>
[[nodiscard]] constexpr auto UnitCast(Temperature &&input) noexcept
    -> Fahrenheit {
  return Fahrenheit((input.data - 273.15) * 1.8 + 32);
}

// Unit Cast for Unit F to Base K
template <>
[[nodiscard]] constexpr auto UnitCast(Fahrenheit &&input) noexcept
    -> Temperature {
  return Temperature((input.data - 32) * 5 / 9 + 273.15);
}

}  // namespace csm_units