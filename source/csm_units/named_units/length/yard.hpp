/**  \file yard.hpp
 *   \brief This file is used to define the unit Yards derived from the
 * base dimension for Length.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Yard">Yards</a> if needed.
 */

#pragma once

#include "../../definition.hpp"
#include "../../unit.hpp"
#include "foot.hpp"

namespace csm_units {

using Yard = Unit<literals::ft * std::ratio<1, 3>()>;

namespace literals {

constexpr auto yd =  // NOLINT(readability-identifier-length)
    Yard::def;

constexpr auto operator""_yd(long double data) noexcept {
  return Yard(static_cast<Yard::ValueType>(data));
}

constexpr auto operator""_yd(unsigned long long data) noexcept {
  return Yard(static_cast<Yard::ValueType>(data));
}

}  // namespace literals

}  // namespace csm_units