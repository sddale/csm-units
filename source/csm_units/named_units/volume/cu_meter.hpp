/**  \file cubic_meter.hpp
 *   \brief This file is used to define the Volume SI unit Cubic Meter.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Cubic_metre">Cubic Meter</a> if needed.
 */

#pragma once

#include "../../definition.hpp"
#include "../../unit.hpp"
#include "dimension.hpp"

namespace csm_units {

namespace definition {

using CuMeter = Definition<Volume>;

}

using CuMeter = Unit<definition::CuMeter>;

namespace literals {

constexpr auto m3 =  // NOLINT(readability-identifier-length)
    definition::CuMeter();

constexpr auto operator""_m3(long double data) noexcept {
  return CuMeter(static_cast<CuMeter::ValueType>(data));
}

constexpr auto operator""_m3(unsigned long long data) noexcept {
  return CuMeter(static_cast<CuMeter::ValueType>(data));
}

}  // namespace literals

}  // namespace csm_units