/**  \file sqr_meter.hpp
 *   \brief This file is used to define the unit Square Meter derived from the
 * base dimension for Area.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Square_metre">Square Meter</a> if needed.
 */

#pragma once

#include "../../definition.hpp"
#include "../../unit.hpp"
#include "dimension.hpp"

namespace csm_units {

namespace definition {

using SqMeter = Definition<Area>;

}

using SqMeter = Unit<definition::SqMeter>;

namespace literals {

constexpr auto m2 =  // NOLINT(readability-identifier-length)
    definition::SqMeter();

constexpr auto operator""_m2(long double data) noexcept {
  return SqMeter(static_cast<SqMeter::ValueType>(data));
}

constexpr auto operator""_m2(unsigned long long data) noexcept {
  return SqMeter(static_cast<SqMeter::ValueType>(data));
}

}  // namespace literals

}  // namespace csm_units