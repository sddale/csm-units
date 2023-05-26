#pragma once

#include "../../unit.hpp"
#include "../../unitcast.hpp"
#include "dimension.hpp"

namespace csm_units {

using Ampere = Unit<ElectrCurrent, "A", double>;

// Unit Cast for Unit Ampere
template <>
[[nodiscard]] constexpr auto UnitCast(ElectrCurrent &&input) noexcept
    -> Ampere {
  return Ampere(input.data);
}

// Unit Cast for Unit Ampere
template <>
[[nodiscard]] constexpr auto UnitCast(Ampere &&input) noexcept
    -> ElectrCurrent {
  return ElectrCurrent(input.data);
}

}  // namespace csm_units