/**  \file hertz.hpp
 *   \brief This file is used to define the Frequency SI unit Hertz.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Hertz">Hertz</a> if needed.
 */

#pragma once

#include "../../definition.hpp"
#include "../../unit.hpp"
#include "dimension.hpp"

namespace csm_units {

namespace definition {

using Hertz = Definition<Frequency>;

}

using Hertz = Unit<definition::Hertz>;

namespace literals {

constexpr auto Hz =  // NOLINT(readability-identifier-length)
    definition::Hertz();

constexpr auto operator""_Hz(long double data) noexcept {
  return Hertz(static_cast<Hertz::type>(data));
}

constexpr auto operator""_Hz(unsigned long long data) noexcept {
  return Hertz(static_cast<Hertz::type>(data));
}

}  // namespace literals

}  // namespace csm_units