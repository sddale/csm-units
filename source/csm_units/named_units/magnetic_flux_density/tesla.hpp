/**  \file tesla.hpp
 *   \brief This file is used to define the Magnetic Flux Density SI unit Tesla.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Tesla_(unit)">Tesla</a> if needed.
 */

#pragma once

#include "../../definition.hpp"
#include "../../unit.hpp"
#include "dimension.hpp"

namespace csm_units {

using Tesla = Unit<Definition<MagneticFluxDensity>{}>;

namespace literals {

constexpr auto T =  // NOLINT(readability-identifier-length)
    Tesla::def;

constexpr auto operator""_T(long double data) noexcept {
  return Tesla(static_cast<Tesla::ValueType>(data));
}

constexpr auto operator""_T(unsigned long long data) noexcept {
  return Tesla(static_cast<Tesla::ValueType>(data));
}

}  // namespace literals

}  // namespace csm_units