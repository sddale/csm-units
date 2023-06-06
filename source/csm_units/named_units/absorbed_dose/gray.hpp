#pragma once

#include "../../unit.hpp"
#include "../../unitcast.hpp"
#include "dimension.hpp"

namespace csm_units {

using Gray = Unit<AbsorbedDose, "Gy", double>;

// Unit Cast for Base Gray
template <>
[[nodiscard]] constexpr auto UnitCast(AbsorbedDose &&input) noexcept -> Gray {
  return Gray(input.data);
}
template <>
[[nodiscard]] constexpr auto UnitCast(Gray &&input) noexcept -> AbsorbedDose {
  return AbsorbedDose(input.data);
}

}  // namespace csm_units