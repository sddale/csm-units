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

using Meter = Unit<Definition<Length>{}>;

namespace literals {

constexpr auto m =  // NOLINT(readability-identifier-length)
    Meter::def;

constexpr auto operator""_m(long double data) noexcept {
  return Meter(static_cast<Meter::ValueType>(data));
}

constexpr auto operator""_m(unsigned long long data) noexcept {
  return Meter(static_cast<Meter::ValueType>(data));
}

}  // namespace literals

}  // namespace csm_units