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

using Hertz = Unit<Definition<Frequency>{}>;

namespace literals {

constexpr auto Hz =  // NOLINT(readability-identifier-length)
    Hertz::def;

constexpr auto operator""_Hz(long double data) noexcept {
  return Hertz(static_cast<Hertz::ValueType>(data));
}

constexpr auto operator""_Hz(unsigned long long data) noexcept {
  return Hertz(static_cast<Hertz::ValueType>(data));
}

}  // namespace literals

}  // namespace csm_units