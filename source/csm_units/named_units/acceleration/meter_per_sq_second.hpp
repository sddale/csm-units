/**  \file meter_per_sq_second.hpp
 *   \brief This file is used to define the Acceleration SI unit Meters Per
 * Squared Second.
 *
 *   The following wikipedia page can explain <a
 * href="https://simple.wikipedia.org/wiki/Metre_per_second_squared#:~:text=A%20metre%20per%20second%20squared,1%20m%2Fs%20every%20second.">Meters
 * Per Second Squared</a>  if needed.
 */

#pragma once

#include "../../definition.hpp"
#include "../../unit.hpp"
#include "dimension.hpp"

namespace csm_units {

using MetersPerSqSecond = Unit<Definition<Acceleration>{}>;

namespace literals {

constexpr auto mps2 =  // NOLINT(readability-identifier-length)
    MetersPerSqSecond::def;

constexpr auto operator""_mps2(long double data) noexcept {
  return MetersPerSqSecond(static_cast<MetersPerSqSecond::ValueType>(data));
}

constexpr auto operator""_mps2(unsigned long long data) noexcept {
  return MetersPerSqSecond(static_cast<MetersPerSqSecond::ValueType>(data));
}

}  // namespace literals

}  // namespace csm_units