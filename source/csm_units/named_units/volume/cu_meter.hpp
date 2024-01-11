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

using CuMeter = Unit<Definition<Volume>{}>;

namespace literals {

constexpr auto m3 =  // NOLINT(readability-identifier-length)
    CuMeter::def;

constexpr auto operator""_m3(long double data) noexcept {
  return CuMeter(static_cast<CuMeter::ValueType>(data));
}

constexpr auto operator""_m3(unsigned long long data) noexcept {
  return CuMeter(static_cast<CuMeter::ValueType>(data));
}

}  // namespace literals

}  // namespace csm_units