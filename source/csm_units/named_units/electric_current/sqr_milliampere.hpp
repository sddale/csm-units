#pragma once

#include "../../unit.hpp"
#include "../../unitcast.hpp"
#include "dimension.hpp"

namespace csm_units {

using SqrMilliamp = Unit<SqrElectrCurrent, "mA2", double>;

template <>
[[nodiscard]] constexpr auto UnitCast(SqrElectrCurrent &&input) noexcept
    -> SqrMilliamp {
  return SqrMilliamp(input.data * 1000000);
}

template <>
[[nodiscard]] constexpr auto UnitCast(SqrMilliamp &&input) noexcept
    -> SqrElectrCurrent {
  return SqrElectrCurrent(input.data / 1000000);
}

}  // namespace csm_units