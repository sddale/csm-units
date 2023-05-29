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

}  // namespace csm_units