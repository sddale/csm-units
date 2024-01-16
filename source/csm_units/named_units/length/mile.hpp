/**  \file mile.hpp
 *   \brief This file is used to define the unit Miles derived from the
 * base dimension for Length.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Mile">Miles</a> if needed.
 */

#pragma once

#include "../../definition.hpp"
#include "../../unit.hpp"
#include "foot.hpp"

namespace csm_units {

using Mile = Unit<literals::ft * std::ratio<1, 5280>()>;

namespace literals {

constexpr auto mi =  // NOLINT(readability-identifier-length)
    Mile::def;

constexpr auto operator""_mi(long double data) noexcept {
  return Mile(static_cast<Mile::ValueType>(data));
}

constexpr auto operator""_mi(unsigned long long data) noexcept {
  return Mile(static_cast<Mile::ValueType>(data));
}

}  // namespace literals

}  // namespace csm_units