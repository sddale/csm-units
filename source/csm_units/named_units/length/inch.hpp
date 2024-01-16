/**  \file inch.hpp
 *   \brief This file is used to define the unit Inch derived from the
 * base dimension for Length.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Inch">Inch</a> if needed.
 */

#pragma once

#include "../../definition.hpp"
#include "../../unit.hpp"
#include "foot.hpp"

namespace csm_units {

using Inch = Unit<literals::ft * std::ratio<12>()>;

namespace literals {

constexpr auto in =  // NOLINT(readability-identifier-length)
    Inch::def;

constexpr auto operator""_in(long double data) noexcept {
  return Inch(static_cast<Inch::ValueType>(data));
}

constexpr auto operator""_in(unsigned long long data) noexcept {
  return Inch(static_cast<Inch::ValueType>(data));
}

}  // namespace literals

}  // namespace csm_units