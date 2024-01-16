/**  \file cu_centimeter_per_mole.hpp
 *   \brief This file is used to define the unit Cubic Centimeter Per Mole from
 * the base dimension for Molar Volume.
 *
 */

#pragma once

#include "../../definition.hpp"
#include "../../unit.hpp"
#include "../amount_of_substance/mole.hpp"
#include "../volume/cu_centimeter.hpp"

namespace csm_units {

using CuCentimetersPerMole = Unit<literals::cm3 / literals::mol>;

namespace literals {

constexpr auto cm3permole =  // NOLINT(readability-identifier-length)
    CuCentimetersPerMole::def;

constexpr auto operator""_cm3permole(long double data) noexcept {
  return CuCentimetersPerMole(
      static_cast<CuCentimetersPerMole::ValueType>(data));
}

constexpr auto operator""_cm3permole(unsigned long long data) noexcept {
  return CuCentimetersPerMole(
      static_cast<CuCentimetersPerMole::ValueType>(data));
}

}  // namespace literals

}  // namespace csm_units