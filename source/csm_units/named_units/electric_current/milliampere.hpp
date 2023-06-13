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

constexpr auto operator""_mA(long double data) noexcept {
  return Milliampere(static_cast<double>(data));
}

}  // namespace csm_units