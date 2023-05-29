#pragma once

#include "../../unit.hpp"
#include "../../unitcast.hpp"
#include "dimension.hpp"

namespace csm_units {

using MPerS2 = Unit<Accel, "m/s2", double>;

// Unit Cast for Base mps2
template <>
[[nodiscard]] constexpr auto UnitCast(Accel &&input) noexcept -> MPerS2 {
  return MPerS2(input.data);
}

// Unit Cast for Unit mps2
template <>
[[nodiscard]] constexpr auto UnitCast(MPerS2 &&input) noexcept -> Accel {
  return Accel(input.data);
}

}  // namespace csm_units