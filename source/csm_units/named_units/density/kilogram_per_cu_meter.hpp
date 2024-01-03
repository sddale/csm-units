/**  \file kg_per_cubic_m.hpp
 *   \brief This file is used to define the Density SI unit Kilogram Per Cubic
 * Meter.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Kilogram_per_cubic_metre#:~:text=The%20kilogram%20per%20cubic%20metre,by%20volume%20in%20cubic%20metres.">Kilogram
 * Per Cubic Meter</a> if needed.
 */

#pragma once

#include "../../definition.hpp"
#include "../../unit.hpp"
#include "dimension.hpp"

namespace csm_units {

namespace definition {

using KilogramPerCuMeter = Definition<Density>;

}

using KilogramPerCuMeter = Unit<definition::KilogramPerCuMeter>;

namespace literals {

constexpr auto kgperm3 =  // NOLINT(readability-identifier-length)
    definition::KilogramPerCuMeter();

constexpr auto operator""_kgperm3(long double data) noexcept {
  return KilogramPerCuMeter(static_cast<KilogramPerCuMeter::type>(data));
}

constexpr auto operator""_kgperm3(unsigned long long data) noexcept {
  return KilogramPerCuMeter(static_cast<KilogramPerCuMeter::type>(data));
}

}  // namespace literals

}  // namespace csm_units