/**  \file farad.hpp
 *   \brief This file is used to define the Capacitance SI unit Farad.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Farad">Farad</a> if needed.
 */

#pragma once

#include "../../definition.hpp"
#include "../../unit.hpp"
#include "dimension.hpp"

namespace csm_units {

using Farad = Unit<Definition<Capacitance>{}>;

namespace literals {

constexpr auto F =  // NOLINT(readability-identifier-length)
    Farad::def;

constexpr auto operator""_F(long double data) noexcept {
  return Farad(static_cast<Farad::ValueType>(data));
}

constexpr auto operator""_F(unsigned long long data) noexcept {
  return Farad(static_cast<Farad::ValueType>(data));
}

}  // namespace literals

}  // namespace csm_units