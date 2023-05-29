#pragma once

#include "../../unit.hpp"
#include "../../unitcast.hpp"
#include "dimension.hpp"

namespace csm_units {

using Ohm = Unit<Resistance, "ohm", double>;

// Unit Cast for Base Ohm
template <>
[[nodiscard]] constexpr auto UnitCast(Resistance &&input) noexcept -> Ohm {
  return Ohm(input.data);
}
template <>
[[nodiscard]] constexpr auto UnitCast(Ohm &&input) noexcept -> Resistance {
  return Resistance(input.data);
}

}  // namespace csm_units