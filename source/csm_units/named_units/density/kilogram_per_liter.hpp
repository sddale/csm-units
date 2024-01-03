/**  \file kg_per_liter.hpp
 *   \brief This file is used to define the unit Kilogram Per Liter derived from
 * the base dimension for Density.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Kilogram_per_cubic_metre">Kilogram Per
 * Cubic Meter</a> if needed. Kilogram Per Liter having a close description to
 * this.
 */

#pragma once

#include "../../definition.hpp"
#include "../../unit.hpp"
#include "dimension.hpp"

namespace csm_units {

namespace definition {

using KilogramPerLiter = Definition<Density, std::deca>;  // Liter = dm3

}

using KilogramPerLiter = Unit<definition::KilogramPerLiter>;

namespace literals {

constexpr auto kgperL =  // NOLINT(readability-identifier-length)
    definition::KilogramPerLiter();

constexpr auto operator""_kgperL(long double data) noexcept {
  return KilogramPerLiter(static_cast<KilogramPerLiter::type>(data));
}

constexpr auto operator""_kgperL(unsigned long long data) noexcept {
  return KilogramPerLiter(static_cast<KilogramPerLiter::type>(data));
}

}  // namespace literals

}  // namespace csm_units