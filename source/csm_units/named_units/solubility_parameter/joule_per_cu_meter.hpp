/**  \file si_sqr_solubility_parameter.hpp
 *   \brief This file is used to define the Square Solubility Parameter SI unit
 * Joules Per Cubic Meter.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Hildebrand_solubility_parameter">Joules
 * Per Cubic Meter</a> if needed.
 */

#pragma once

#include "../../definition.hpp"
#include "../../unit.hpp"
#include "sqrt_joule_per_sqrt_cu_meter.hpp"

namespace csm_units {

using JoulesPerCuMeter =
    Unit<literals::SqrtJperSqrtcm3 * literals::SqrtJperSqrtcm3>;

namespace literals {

constexpr auto Jpercm3 =  // NOLINT(readability-identifier-length)
    JoulesPerCuMeter::def;

constexpr auto operator""_Jpercm3(long double data) noexcept {
  return JoulesPerCuMeter(static_cast<JoulesPerCuMeter::ValueType>(data));
}

constexpr auto operator""_Jpercm3(unsigned long long data) noexcept {
  return JoulesPerCuMeter(static_cast<JoulesPerCuMeter::ValueType>(data));
}

}  // namespace literals

}  // namespace csm_units