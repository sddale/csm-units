/**  \file foot.hpp
 *   \brief This file is used to define the unit Foot derived from the
 * base dimension for Length.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Foot_(unit)">Foot</a> if needed.
 */

#pragma once

#include "../../definition.hpp"
#include "../../unit.hpp"
#include "meter.hpp"

namespace csm_units {

using Foot = Unit<literals::m * std::ratio<82021, 25000>{}>;

namespace literals {

constexpr auto ft =  // NOLINT(readability-identifier-length)
    Foot::def;

constexpr auto operator""_ft(long double data) noexcept {
  return Foot(static_cast<Foot::ValueType>(data));
}

constexpr auto operator""_ft(unsigned long long data) noexcept {
  return Foot(static_cast<Foot::ValueType>(data));
}

}  // namespace literals

}  // namespace csm_units