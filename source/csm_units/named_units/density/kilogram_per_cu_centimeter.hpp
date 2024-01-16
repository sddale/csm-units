/**  \file kilogram_per_cu_centimeter.hpp
 *   \brief This file is used to define the unit Kilogram Per Cubic Centimeter
 * derived from the base dimension for Density.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Kilogram_per_cubic_metre">Kilogram Per
 * Cubic Meter</a> if needed. Kilogram Per Cubic Centimeter having a close
 * description to this.
 */

#pragma once

#include "../../definition.hpp"
#include "../../unit.hpp"
#include "../mass/kilogram.hpp"
#include "../volume/cu_centimeter.hpp"

namespace csm_units {

using KilogramsPerCuCentimeter = Unit<literals::kg / literals::cm3>;

namespace literals {

constexpr auto kgpercm3 =  // NOLINT(readability-identifier-length)
    KilogramsPerCuCentimeter::def;

constexpr auto operator""_kgpercm3(long double data) noexcept {
  return KilogramsPerCuCentimeter(
      static_cast<KilogramsPerCuCentimeter::ValueType>(data));
}

constexpr auto operator""_kgpercm3(unsigned long long data) noexcept {
  return KilogramsPerCuCentimeter(
      static_cast<KilogramsPerCuCentimeter::ValueType>(data));
}

}  // namespace literals

}  // namespace csm_units