#pragma once

#include "../../unit.hpp"
#include "../../unitcast.hpp"
#include "dimension.hpp"

namespace csm_units {

using Kilomole = Unit<Amount, "kmol", double>;

// Base Mole -> Kilomole unit
template <>
[[nodiscard]] constexpr auto UnitCast(Amount &&input) noexcept -> Kilomole {
  return Kilomole(input.data / 1000);
}

// unit kmol -> Base Mol
template <>
[[nodiscard]] constexpr auto UnitCast(Kilomole &&input) noexcept -> Amount {
  return Amount(input.data * 1000);
}

}  // namespace csm_units