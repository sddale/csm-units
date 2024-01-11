/**  \file second.hpp
 *   \brief This file is used to define the Time SI unit Second.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Second">Second</a> if needed.
 */

#pragma once

#include "../../definition.hpp"
#include "../../unit.hpp"
#include "dimension.hpp"

namespace csm_units {

using Second = Unit<Definition<Time>{}>;

namespace literals {

constexpr auto s =  // NOLINT(readability-identifier-length)
    Second::def;

constexpr auto operator""_s(long double data) noexcept {
  return Second(static_cast<Second::ValueType>(data));
}

constexpr auto operator""_s(unsigned long long data) noexcept {
  return Second(static_cast<Second::ValueType>(data));
}

}  // namespace literals

}  // namespace csm_units
