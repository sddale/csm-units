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
#include "../mass/kilogram.hpp"
#include "../volume/liter.hpp"

namespace csm_units {

using KilogramPerLiter = Unit<literals::kg / literals::L>;

namespace literals {

constexpr auto kgperL =  // NOLINT(readability-identifier-length)
    KilogramPerLiter::def;

constexpr auto operator""_kgperL(long double data) noexcept {
  return KilogramPerLiter(static_cast<KilogramPerLiter::ValueType>(data));
}

constexpr auto operator""_kgperL(unsigned long long data) noexcept {
  return KilogramPerLiter(static_cast<KilogramPerLiter::ValueType>(data));
}

}  // namespace literals

}  // namespace csm_units