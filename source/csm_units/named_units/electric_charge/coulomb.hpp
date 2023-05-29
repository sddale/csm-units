#pragma once

#include "../../unit.hpp"
#include "../../unitcast.hpp"
#include "dimension.hpp"

namespace csm_units {

using Coulomb = Unit<ElectrCharge, "C", double>;

// Unit Cast for Unit Coulomb
template <>
[[nodiscard]] constexpr auto UnitCast(ElectrCharge &&input) noexcept
    -> Coulomb {
  return Coulomb(input.data);
}

// Unit Cast for Unit Coulomb
template <>
[[nodiscard]] constexpr auto UnitCast(Coulomb &&input) noexcept
    -> ElectrCharge {
  return ElectrCharge(input.data);
}

}  // namespace csm_units