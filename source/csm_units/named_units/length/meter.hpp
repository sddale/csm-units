/**  \file meter.hpp
 *   \brief This file is used to define the Length SI unit Meter.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Metre">Meter</a> if needed.
 */

#pragma once

#include "../../definition.hpp"
#include "../../unit.hpp"
#include "dimension.hpp"

namespace csm_units {

namespace definition {

using Meter = Definition<Length>;

}

using Meter = Unit<definition::Meter>;

namespace literals {

constexpr auto m =  // NOLINT(readability-identifier-length)
    definition::Meter();

constexpr auto operator""_m(long double data) noexcept {
  return Meter(static_cast<Meter::type>(data));
}

constexpr auto operator""_m(unsigned long long data) noexcept {
  return Meter(static_cast<Meter::type>(data));
}

}  // namespace literals

}  // namespace csm_units