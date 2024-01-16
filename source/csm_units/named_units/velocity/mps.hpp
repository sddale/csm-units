/**  \file mps.hpp
 *   \brief This file is used to define the Velocity SI unit Meters Per Second.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Metre_per_second">Meters Per Second</a>
 * if needed.
 */

#pragma once

#include "../../definition.hpp"
#include "../../unit.hpp"
#include "dimension.hpp"

namespace csm_units {

using MeterPerSecond = Unit<Definition<Velocity>{}>;

namespace literals {

constexpr auto mps =  // NOLINT(readability-identifier-length)
    MeterPerSecond::def;

constexpr auto operator""_mps(long double data) noexcept {
  return MeterPerSecond(static_cast<MeterPerSecond::ValueType>(data));
}

constexpr auto operator""_mps(unsigned long long data) noexcept {
  return MeterPerSecond(static_cast<MeterPerSecond::ValueType>(data));
}

}  // namespace literals

}  // namespace csm_units