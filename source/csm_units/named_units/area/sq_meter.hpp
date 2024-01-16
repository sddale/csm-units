/**  \file sq_meter.hpp
 *   \brief This file is used to define the Area SI unit Square Meter.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Square_metre">Square Meter</a> if needed.
 */

#pragma once

#include "../../definition.hpp"
#include "../../unit.hpp"
#include "dimension.hpp"

namespace csm_units {

using SqMeter = Unit<Definition<Area>{}>;

namespace literals {

constexpr auto m2 =  // NOLINT(readability-identifier-length)
    SqMeter::def;

constexpr auto operator""_m2(long double data) noexcept {
  return SqMeter(static_cast<SqMeter::ValueType>(data));
}

constexpr auto operator""_m2(unsigned long long data) noexcept {
  return SqMeter(static_cast<SqMeter::ValueType>(data));
}

}  // namespace literals

}  // namespace csm_units