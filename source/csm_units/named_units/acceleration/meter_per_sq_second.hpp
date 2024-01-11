/**  \file mps2.hpp
 *   \brief This file is used to define the Acceleration SI unit Meters Per
 * Second Squared.
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

using MeterPerSqSecond = Unit<Definition<Acceleration>{}>;

namespace literals {

constexpr auto mps2 =  // NOLINT(readability-identifier-length)
    MeterPerSqSecond::def;

constexpr auto operator""_mps2(long double data) noexcept {
  return MeterPerSqSecond(static_cast<MeterPerSqSecond::ValueType>(data));
}

constexpr auto operator""_mps2(unsigned long long data) noexcept {
  return MeterPerSqSecond(static_cast<MeterPerSqSecond::ValueType>(data));
}

}  // namespace literals

}  // namespace csm_units