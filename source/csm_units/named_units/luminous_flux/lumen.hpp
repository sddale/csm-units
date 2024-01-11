/**  \file lumen.hpp
 *   \brief This file is used to define the Luminous Flux SI unit Lumen.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Lumen_(unit)">Lumen</a> if needed.
 */

#pragma once

#include "../../definition.hpp"
#include "../../unit.hpp"
#include "dimension.hpp"

namespace csm_units {

namespace definition {

using Lumen = Definition<LuminousFlux>;

}

using Lumen = Unit<definition::Lumen>;

namespace literals {

constexpr auto lm =  // NOLINT(readability-identifier-length)
    definition::Lumen();

constexpr auto operator""_lm(long double data) noexcept {
  return Lumen(static_cast<Lumen::ValueType>(data));
}

constexpr auto operator""_lm(unsigned long long data) noexcept {
  return Lumen(static_cast<Lumen::ValueType>(data));
}

}  // namespace literals

}  // namespace csm_units