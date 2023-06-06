#pragma once

#include "../../unit.hpp"
#include "../../unitcast.hpp"
#include "dimension.hpp"

namespace csm_units {

using Mole = Unit<Amount, "mol", double>;

// Unit Cast for Unit Mol
template <>
[[nodiscard]] constexpr auto UnitCast(Amount &&input) noexcept -> Mole {
  return Mole(input.data);
}

// Unit Cast for Unit Mole
template <>
[[nodiscard]] constexpr auto UnitCast(Mole &&input) noexcept -> Amount {
  return Amount(input.data);
}

}  // namespace csm_units