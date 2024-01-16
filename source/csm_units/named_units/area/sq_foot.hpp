/**  \file sq_foot.hpp
 *   \brief This file is used to define the unit Square Foot derived from the
 * base dimension for Area.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Square_foot">Square Foot</a> if needed.
 */

#pragma once

#include "../../definition.hpp"
#include "../../unit.hpp"
#include "../length/foot.hpp"

namespace csm_units {

using SqFoot = Unit<literals::ft * literals::ft>;

namespace literals {

constexpr auto ft2 =  // NOLINT(readability-identifier-length)
    SqFoot::def;

constexpr auto operator""_ft2(long double data) noexcept {
  return SqFoot(static_cast<SqFoot::ValueType>(data));
}

constexpr auto operator""_ft2(unsigned long long data) noexcept {
  return SqFoot(static_cast<SqFoot::ValueType>(data));
}

}  // namespace literals

}  // namespace csm_units