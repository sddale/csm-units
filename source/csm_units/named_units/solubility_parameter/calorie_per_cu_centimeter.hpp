/**  \file calorie_per_cu_centimeter.hpp
 *   \brief This file is used to define the unit (small) calorie Per Cubic
 * Centimeter derived from the base dimension for Square Solubility Parameter.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Hildebrand_solubility_parameter">calorie
 * Per Cubic Centimeter</a> if needed.
 */

#pragma once

#include "../../definition.hpp"
#include "../../unit.hpp"
#include "joule_per_cu_meter.hpp"

namespace csm_units {

using CaloriesPerCuCM = Unit<literals::Jperm3 * std::ratio<1, 4184000>()>;

namespace literals {

constexpr auto calpercm3 =  // NOLINT(readability-identifier-length)
    CaloriesPerCuCM::def;

constexpr auto operator""_calpercm3(long double data) noexcept {
  return CaloriesPerCuCM(static_cast<CaloriesPerCuCM::ValueType>(data));
}

constexpr auto operator""_calpercm3(unsigned long long data) noexcept {
  return CaloriesPerCuCM(static_cast<CaloriesPerCuCM::ValueType>(data));
}

}  // namespace literals

}  // namespace csm_units
