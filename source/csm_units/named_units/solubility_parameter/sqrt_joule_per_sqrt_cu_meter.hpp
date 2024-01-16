/**  \file si_solubility_parameter.hpp
 *   \brief This file is used to define the Solubility Parameter SI unit J^(1/2)
 * / m^(3/2).
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Hildebrand_solubility_parameter">J^(1/2)
 * / m^(3/2)</a> if needed.
 */

#pragma once

#include "../../definition.hpp"
#include "../../unit.hpp"
#include "dimension.hpp"

namespace csm_units {

using SqrtJoulesPerSqrtCuMeter = Unit<Definition<SolubilityParameter>{}>;

namespace literals {

constexpr auto SqrtJperSqrtm3 =  // NOLINT(readability-identifier-length)
    SqrtJoulesPerSqrtCuMeter::def;

constexpr auto operator""_SqrtJperSqrtm3(long double data) noexcept {
  return SqrtJoulesPerSqrtCuMeter(
      static_cast<SqrtJoulesPerSqrtCuMeter::ValueType>(data));
}

constexpr auto operator""_SqrtJperSqrtm3(unsigned long long data) noexcept {
  return SqrtJoulesPerSqrtCuMeter(
      static_cast<SqrtJoulesPerSqrtCuMeter::ValueType>(data));
}

}  // namespace literals

}  // namespace csm_units