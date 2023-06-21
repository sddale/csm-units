/**  \file coulomb.hpp
 *   \brief This file is used to define the Electric Charge SI unit Coulomb.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Coulomb">Coulomb</a> if needed.
 */

#pragma once

#include "../../unit.hpp"
#include "../../unitcast.hpp"
#include "dimension.hpp"

namespace csm_units {

using Coulomb = Unit<ElectrCharge, "C", double>;

// Unit Cast for Unit Coulomb
template <>
[[nodiscard]] constexpr auto UnitCast(ElectrCharge &&input) noexcept
    -> Coulomb {
  return Coulomb(input.data);
}

// Unit Cast for Unit Coulomb
template <>
[[nodiscard]] constexpr auto UnitCast(Coulomb &&input) noexcept
    -> ElectrCharge {
  return ElectrCharge(input.data);
}

namespace literals {

constexpr auto operator""_C(long double data) noexcept {
  return Coulomb(static_cast<double>(data));
}

}  // namespace literals

}  // namespace csm_units