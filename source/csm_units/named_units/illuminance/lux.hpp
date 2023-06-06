#pragma once

#include "../../unit.hpp"
#include "../../unitcast.hpp"
#include "dimension.hpp"

namespace csm_units {

using Lux = Unit<Illuminance, "lx", double>;

template <>
[[nodiscard]] constexpr auto UnitCast(Illuminance &&input) noexcept -> Lux {
  return Lux(input.data);
}

// Unit Cast for Unit Newton
template <>
[[nodiscard]] constexpr auto UnitCast(Lux &&input) noexcept -> Illuminance {
  return Illuminance(input.data);
}

}  // namespace csm_units