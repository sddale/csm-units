/**  \file kilogram_meters_per_second.hpp
 *   \brief This file is used to define the Momentum SI unit Kilogram Meter Per
 * Second.
 *
 */

#pragma once

#include "../../definition.hpp"
#include "../../unit.hpp"
#include "dimension.hpp"

namespace csm_units {

namespace definition {

using KilogramMeterPerSecond = Definition<Momentum>;

}

using KilogramMeterPerSecond = Unit<definition::KilogramMeterPerSecond>;

namespace literals {

constexpr auto kgmpers =  // NOLINT(readability-identifier-length)
    definition::KilogramMeterPerSecond();

constexpr auto operator""_kgmpers(long double data) noexcept {
  return KilogramMeterPerSecond(
      static_cast<KilogramMeterPerSecond::type>(data));
}

constexpr auto operator""_kgmpers(unsigned long long data) noexcept {
  return KilogramMeterPerSecond(
      static_cast<KilogramMeterPerSecond::type>(data));
}

}  // namespace literals

}  // namespace csm_units