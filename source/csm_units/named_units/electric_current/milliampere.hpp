/**  \file milliampere.hpp
 *   \brief This file is used to define the unit Milliampere derived from the
 * base dimension for Electric Current.
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

namespace literals {

constexpr auto operator""_mA(long double data) noexcept {
  return Milliampere(static_cast<double>(data));
}

}  // namespace literals

}  // namespace csm_units