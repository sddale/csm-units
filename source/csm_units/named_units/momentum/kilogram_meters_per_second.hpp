/**  \file kilogram_meters_per_second.hpp
 *   \brief This file is used to define the Momentum SI unit Kilogram Meter Per
 * Second.
 *
 */

#pragma once

#include "../../unit.hpp"
#include "../../unitcast.hpp"
#include "dimension.hpp"

namespace csm_units {

using KilogramMeterPerSecond = Unit<Momentum, "kgm/s", double>;

template <>
[[nodiscard]] constexpr auto UnitCast(Momentum &&input) noexcept
    -> KilogramMeterPerSecond {
  return KilogramMeterPerSecond(input.data);
}

template <>
[[nodiscard]] constexpr auto UnitCast(KilogramMeterPerSecond &&input) noexcept
    -> Momentum {
  return Momentum(input.data);
}

namespace literals {

constexpr auto operator""_kgmps(long double data) noexcept {
  return KilogramMeterPerSecond(static_cast<double>(data));
}

constexpr auto operator""_kgmps(unsigned long long data) noexcept {
  return KilogramMeterPerSecond(static_cast<double>(data));
}

}  // namespace literals

}  // namespace csm_units