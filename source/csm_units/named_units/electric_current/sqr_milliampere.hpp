/**  \file sqr_milliampere.hpp
 *   \brief This file is used to define the unit Square Milliammpere derived
 * from the base dimension for Amount of a Substance.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/?title=Milliampere&redirect=no">Milliampere</a>
 * if needed.
 */

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