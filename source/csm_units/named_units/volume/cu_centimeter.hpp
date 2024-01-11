/**  \file cubic_meter.hpp
 *   \brief This file is used to define the unit Cubic Centimeter from the base
 * dimension for Volume.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Cubic_centimetre">Cubic Centimeter</a> if
 * needed.
 */

#pragma once

#include "../../definition.hpp"
#include "../../unit.hpp"
#include "../length/centimeter.hpp"

namespace csm_units {

using CuCentimeter = Unit<literals::cm * literals::cm * literals::cm>;

namespace literals {

constexpr auto cm3 =  // NOLINT(readability-identifier-length)
    CuCentimeter::def;

constexpr auto operator""_cm3(long double data) noexcept {
  return CuCentimeter(static_cast<CuCentimeter::ValueType>(data));
}

constexpr auto operator""_cm3(unsigned long long data) noexcept {
  return CuCentimeter(static_cast<CuCentimeter::ValueType>(data));
}

}  // namespace literals

}  // namespace csm_units