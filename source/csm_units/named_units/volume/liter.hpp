#pragma once

#include "../../unit.hpp"
#include "../../unitcast.hpp"
#include "dimension.hpp"

namespace csm_units {

using Liter = Unit<Volume, "L", double>;

// Unit Cast for base
template <>
[[nodiscard]] constexpr auto UnitCast(Volume &&input) noexcept -> Liter {
  return Liter(input.data * 1000);
}

// Unit Cast for Unit Liter
template <>
[[nodiscard]] constexpr auto UnitCast(Liter &&input) noexcept -> Volume {
  return Volume(input.data / 1000);
}

}  // namespace csm_units