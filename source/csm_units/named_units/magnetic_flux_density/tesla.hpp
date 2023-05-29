#pragma once

#include "../../unit.hpp"
#include "../../unitcast.hpp"
#include "dimension.hpp"

namespace csm_units {

using Tesla = Unit<MagneticFluxDensity, "T", double>;

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

}  // namespace csm_units