/**  \file ampere.hpp
 *   \brief This file is used to define the Electric Current SI unit Ampere.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Ampere">Ampere</a> if needed.
 */

#pragma once

#include "../../unit.hpp"
#include "../../unitcast.hpp"
#include "dimension.hpp"

namespace csm_units {

using Ampere = Unit<ElectrCurrent, "A", double>;

// Unit Cast for Unit Ampere
template <>
[[nodiscard]] constexpr auto UnitCast(ElectrCurrent &&input) noexcept
    -> Ampere {
  return Ampere(input.data);
}

// Unit Cast for Unit Ampere
template <>
[[nodiscard]] constexpr auto UnitCast(Ampere &&input) noexcept
    -> ElectrCurrent {
  return ElectrCurrent(input.data);
}

namespace literals {

// current - ampere
constexpr auto operator""_A(long double data) noexcept {
  return Ampere(static_cast<double>(data));
}

}  // namespace literals

}  // namespace csm_units