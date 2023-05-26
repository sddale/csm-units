#pragma once

#include "../../unit.hpp"
#include "../../unitcast.hpp"
#include "dimension.hpp"

namespace csm_units {

using Celsius = Unit<Temperature, "C", double>;

// Base K -> Unit C
template <>
[[nodiscard]] constexpr auto UnitCast(Temperature &&input) noexcept -> Celsius {
  return Celsius(input.data - 273.15);
}

// Unit C -> Base K
template <>
[[nodiscard]] constexpr auto UnitCast(Celsius &&input) noexcept -> Temperature {
  return Temperature(input.data + 273.15);
}

}  // namespace csm_units