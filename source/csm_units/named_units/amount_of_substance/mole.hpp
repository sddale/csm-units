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

// amount - mole
constexpr auto operator""_mol(long double data) noexcept {
  return Unit<UnitBase<Exponents<0, 0, 0, 0, 0, 1, 0>, double>, "mol", double>(
      static_cast<double>(data));
}

}  // namespace csm_units