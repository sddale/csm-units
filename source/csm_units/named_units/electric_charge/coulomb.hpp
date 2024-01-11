/**  \file coulomb.hpp
 *   \brief This file is used to define the Electric Charge SI unit Coulomb.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Coulomb">Coulomb</a> if needed.
 */

#pragma once

#include "../../definition.hpp"
#include "../../unit.hpp"
#include "dimension.hpp"

namespace csm_units {

namespace definition {

using Coulomb = Definition<ElectricCharge>;

}

using Coulomb = Unit<definition::Coulomb>;

namespace literals {

constexpr auto C =  // NOLINT(readability-identifier-length)
    Coulomb::def;

constexpr auto operator""_C(long double data) noexcept {
  return Coulomb(static_cast<Coulomb::ValueType>(data));
}

constexpr auto operator""_C(unsigned long long data) noexcept {
  return Coulomb(static_cast<Coulomb::ValueType>(data));
}

}  // namespace literals

}  // namespace csm_units