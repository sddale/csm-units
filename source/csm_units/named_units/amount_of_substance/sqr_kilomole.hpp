#pragma once

#include "../../unit.hpp"
#include "../../unitcast.hpp"
#include "dimension.hpp"

namespace csm_units {

using SqrKilomole = Unit<SqrAmount, "kmol2", double>;

template <>
[[nodiscard]] constexpr auto UnitCast(SqrAmount &&input) noexcept
    -> SqrKilomole {
  return SqrKilomole(input.data / 1000000);
}

template <>
[[nodiscard]] constexpr auto UnitCast(SqrKilomole &&input) noexcept
    -> SqrAmount {
  return SqrAmount(input.data * 1000000);
}

}  // namespace csm_units