#pragma once

#include "../../unit.hpp"
#include "../../unitcast.hpp"
#include "dimension.hpp"

namespace csm_units {

using Volt = Unit<Potential, "W", double>;

// Unit Cast for Base Volt
template <>
[[nodiscard]] constexpr auto UnitCast(Potential &&input) noexcept -> Volt {
  return Volt(input.data);
}
template <>
[[nodiscard]] constexpr auto UnitCast(Volt &&input) noexcept -> Potential {
  return Potential(input.data);
}

}  // namespace csm_units