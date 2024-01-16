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

using KilogramsMeterPerSecond = Unit<Definition<Momentum>{}>;

namespace literals {

constexpr auto kgmpers =  // NOLINT(readability-identifier-length)
    KilogramsMeterPerSecond::def;

constexpr auto operator""_kgmpers(long double data) noexcept {
  return KilogramsMeterPerSecond(
      static_cast<KilogramsMeterPerSecond::ValueType>(data));
}

constexpr auto operator""_kgmpers(unsigned long long data) noexcept {
  return KilogramsMeterPerSecond(
      static_cast<KilogramsMeterPerSecond::ValueType>(data));
}

}  // namespace literals

}  // namespace csm_units