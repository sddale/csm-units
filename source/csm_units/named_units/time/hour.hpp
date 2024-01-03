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
#include "dimension.hpp"

namespace csm_units {

namespace definition {

using Hour =
    Definition<Time, std::ratio<1>, std::ratio<1>, std::ratio<1, 3600>>;

}

using Hour = Unit<definition::Hour>;

namespace literals {

constexpr auto hr =  // NOLINT(readability-identifier-length)
    definition::Hour();

constexpr auto operator""_hr(long double data) noexcept {
  return Hour(static_cast<Hour::type>(data));
}

constexpr auto operator""_hr(unsigned long long data) noexcept {
  return Hour(static_cast<Hour::type>(data));
}

}  // namespace literals

}  // namespace csm_units