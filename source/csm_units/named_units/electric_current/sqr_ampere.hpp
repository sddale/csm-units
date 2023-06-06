#pragma once

#include "../../unit.hpp"
#include "../../unitcast.hpp"
#include "dimension.hpp"

namespace csm_units {

using SqrAmpere = Unit<SqrElectrCurrent, "A2", double>;

template <>
[[nodiscard]] constexpr auto UnitCast(SqrElectrCurrent &&input) noexcept
    -> SqrAmpere {
  return SqrAmpere(input.data);
}

template <>
[[nodiscard]] constexpr auto UnitCast(SqrAmpere &&input) noexcept
    -> SqrElectrCurrent {
  return SqrElectrCurrent(input.data);
}

}  // namespace csm_units