#pragma once

#include "../../unit.hpp"
#include "../../unitcast.hpp"
#include "dimension.hpp"

namespace csm_units {

using Lumen = Unit<LuminousFlux, "lx", double>;

template <>
[[nodiscard]] constexpr auto UnitCast(LuminousFlux &&input) noexcept -> Lumen {
  return Lumen(input.data);
}

// Unit Cast for Unit Lumen
template <>
[[nodiscard]] constexpr auto UnitCast(Lumen &&input) noexcept -> LuminousFlux {
  return LuminousFlux(input.data);
}

}  // namespace csm_units