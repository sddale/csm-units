/**  \file cubic_meter.hpp
 *   \brief This file is used to define the unit Cubic Centimeter Per Mole from
 * the base dimension for MolarVolume.
 *
 */

#pragma once

#include "../../definition.hpp"
#include "../../unit.hpp"
#include "dimension.hpp"

namespace csm_units {

namespace definition {

using CuCentimeterPerMole = Definition<MolarVolume, std::centi>;

}

using CuCentimeterPerMole = Unit<definition::CuCentimeterPerMole>;

namespace literals {

constexpr auto m3permole =  // NOLINT(readability-identifier-length)
    definition::CuCentimeterPerMole();

constexpr auto operator""_m3permole(long double data) noexcept {
  return CuCentimeterPerMole(static_cast<CuCentimeterPerMole::type>(data));
}

constexpr auto operator""_m3permole(unsigned long long data) noexcept {
  return CuCentimeterPerMole(static_cast<CuCentimeterPerMole::type>(data));
}

}  // namespace literals

}  // namespace csm_units