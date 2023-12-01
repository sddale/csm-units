/**  \file mps.hpp
 *   \brief This file is used to define the Velocity SI unit Meters Per Second.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Metre_per_second">Meters Per Second</a>
 * if needed.
 */

#pragma once

#include "../../unit.hpp"
#include "dimension.hpp"

namespace csm_units {

using MeterPerSecond = Unit<Velocity, "m/s", double>;

// Unit Cast for Unit m/s
template <>
[[nodiscard]] constexpr auto UnitCast(Velocity input) noexcept
    -> MeterPerSecond {
  return MeterPerSecond(input.data);
}

// Unit Cast for Unit m/s
template <>
[[nodiscard]] constexpr auto UnitCast(MeterPerSecond input) noexcept
    -> Velocity {
  return Velocity(input.data);
}

namespace literals {

constexpr auto operator""_mps(long double data) noexcept {
  return MeterPerSecond(static_cast<double>(data));
}

constexpr auto operator""_mps(unsigned long long data) noexcept {
  return MeterPerSecond(static_cast<double>(data));
}

}  // namespace literals

}  // namespace csm_units