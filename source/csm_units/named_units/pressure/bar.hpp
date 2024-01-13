/**  \file bar.hpp
 *   \brief This file is used to define the unit Bar derived from the base
 * dimension for Pressure.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Bar_(unit)">Bar</a> if needed.
 */

#pragma once

#include "../../definition.hpp"
#include "../../unit.hpp"
#include "pascal.hpp"

namespace csm_units {

using Bar = Unit<literals::Pa * std::ratio<1, 100000>()>;

namespace literals {

constexpr auto bar =  // NOLINT(readability-identifier-length)
    Bar::def;

constexpr auto operator""_bar(long double data) noexcept {
  return Bar(static_cast<Bar::ValueType>(data));
}

constexpr auto operator""_bar(unsigned long long data) noexcept {
  return Bar(static_cast<Bar::ValueType>(data));
}

}  // namespace literals

}  // namespace csm_units