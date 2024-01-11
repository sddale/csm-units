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
#include "dimension.hpp"

namespace csm_units {

namespace definition {

using Foot = Definition<Length, std::ratio<82021, 25000>>;

}

using Foot = Unit<definition::Foot>;

namespace literals {

constexpr auto ft =  // NOLINT(readability-identifier-length)
    definition::Foot();

constexpr auto operator""_ft(long double data) noexcept {
  return Foot(static_cast<Foot::ValueType>(data));
}

constexpr auto operator""_ft(unsigned long long data) noexcept {
  return Foot(static_cast<Foot::ValueType>(data));
}

}  // namespace literals

}  // namespace csm_units