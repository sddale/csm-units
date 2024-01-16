/**  \file kilogram_per_cu_meter.hpp
 *   \brief This file is used to define the Density SI unit Kilogram Per Cubic
 * Meter.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Kilogram_per_cubic_metre">Kilogram
 * Per Cubic Meter</a> if needed.
 */

#pragma once

#include "../../definition.hpp"
#include "../../unit.hpp"
#include "dimension.hpp"

namespace csm_units {

using KilogramPerCuMeter = Unit<Definition<Density>{}>;

namespace literals {

constexpr auto kgperm3 =  // NOLINT(readability-identifier-length)
    KilogramPerCuMeter::def;

constexpr auto operator""_kgperm3(long double data) noexcept {
  return KilogramPerCuMeter(static_cast<KilogramPerCuMeter::ValueType>(data));
}

constexpr auto operator""_kgperm3(unsigned long long data) noexcept {
  return KilogramPerCuMeter(static_cast<KilogramPerCuMeter::ValueType>(data));
}

}  // namespace literals

}  // namespace csm_units
