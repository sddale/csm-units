#pragma once

#include "../../unit.hpp"
#include "../../unitcast.hpp"
#include "dimension.hpp"

namespace csm_units {

using Milliampere = Unit<ElectrCurrent, "mA", double>;

// base A -> Unit mA
template <>
[[nodiscard]] constexpr auto UnitCast(ElectrCurrent &&input) noexcept
    -> Milliampere {
  return Milliampere(input.data * 1000);
}

// Unit mA -> Base A
template <>
[[nodiscard]] constexpr auto UnitCast(Milliampere &&input) noexcept
    -> ElectrCurrent {
  return ElectrCurrent(input.data / 1000);
}

}  // namespace csm_units