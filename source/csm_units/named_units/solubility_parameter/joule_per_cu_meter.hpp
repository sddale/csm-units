/**  \file joule_per_cu_meter.hpp
 *   \brief This file is used to define the Square Solubility Parameter SI unit
 * Joule Per Cubic Meter.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Hildebrand_solubility_parameter">Joule
 * Per Cubic Meter</a> if needed.
 */

#pragma once

#include "../../definition.hpp"
#include "../../unit.hpp"
#include "sqrt_joule_per_sqrt_cu_meter.hpp"

namespace csm_units {

using JoulesPerCuMeter =
    Unit<literals::SqrtJperSqrtm3 * literals::SqrtJperSqrtm3>;

namespace literals {

constexpr auto Jperm3 =  // NOLINT(readability-identifier-length)
    JoulesPerCuMeter::def;

constexpr auto operator""_Jperm3(long double data) noexcept {
  return JoulesPerCuMeter(static_cast<JoulesPerCuMeter::ValueType>(data));
}

constexpr auto operator""_Jperm3(unsigned long long data) noexcept {
  return JoulesPerCuMeter(static_cast<JoulesPerCuMeter::ValueType>(data));
}

}  // namespace literals

}  // namespace csm_units