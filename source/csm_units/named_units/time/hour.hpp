/**  \file hour.hpp
 *   \brief This file is used to define the unit Hour derived from the base
 * dimension for Time.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Hour">Hour</a> if needed.
 */

#pragma once

#include "../../definition.hpp"
#include "../../unit.hpp"
#include "minute.hpp"

namespace csm_units {

using Hour = Unit<literals::min * std::ratio<1, 60>()>;

namespace literals {

constexpr auto hr =  // NOLINT(readability-identifier-length)
    Hour::def;

constexpr auto operator""_hr(long double data) noexcept {
  return Hour(static_cast<Hour::ValueType>(data));
}

constexpr auto operator""_hr(unsigned long long data) noexcept {
  return Hour(static_cast<Hour::ValueType>(data));
}

}  // namespace literals

}  // namespace csm_units