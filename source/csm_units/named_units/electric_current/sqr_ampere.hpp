/**  \file sqr_ampere.hpp
 *   \brief This file is used to define the unit Square Ampere derived from the
 * base dimension for Electric Current.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Ampere">Ampere</a> if needed.
 */

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