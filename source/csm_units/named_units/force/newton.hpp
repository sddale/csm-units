/**  \file newton.hpp
 *   \brief This file is used to define the Force SI unit Newton.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Newton_(unit)">Newton</a> if needed.
 */

#pragma once

#include "../../definition.hpp"
#include "../../unit.hpp"
#include "../length/meter.hpp"
#include "../mass/kilogram.hpp"
#include "../time/second.hpp"
#include "dimension.hpp"

namespace csm_units {

namespace definition {

using Newton =
    decltype(literals::kg * literals::m / (literals::s * literals::s));
static_assert(std::is_same_v<Newton::dim, Force>);

}  // namespace definition

using Newton = Unit<definition::Newton>;

namespace literals {

constexpr auto N =  // NOLINT(readability-identifier-length)
    Newton::def;

constexpr auto operator""_N(long double data) noexcept {
  return Newton(static_cast<Newton::ValueType>(data));
}

constexpr auto operator""_N(unsigned long long data) noexcept {
  return Newton(static_cast<Newton::ValueType>(data));
}

}  // namespace literals

}  // namespace csm_units
