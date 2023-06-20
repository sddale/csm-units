#pragma once

#include "../../unit.hpp"
#include "../../unitcast.hpp"
#include "dimension.hpp"

namespace csm_units {

using SqrMole = Unit<SqrAmount, "mol2", double>;

template <>
[[nodiscard]] constexpr auto UnitCast(SqrAmount &&input) noexcept -> SqrMole {
  return SqrMole(input.data);
}

template <>
[[nodiscard]] constexpr auto UnitCast(SqrMole &&input) noexcept -> SqrAmount {
  return SqrAmount(input.data);
}

namespace literals {

constexpr auto operator""_mol2(long double data) noexcept {
  return SqrMole(static_cast<double>(data));
}

}  // namespace literals

}  // namespace csm_units