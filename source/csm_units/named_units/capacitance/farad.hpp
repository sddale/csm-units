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

namespace definition {

using Farad = Definition<Capacitance>;

}

using Farad = Unit<definition::Farad>;

namespace literals {

constexpr auto F =  // NOLINT(readability-identifier-length)
    definition::Farad();

constexpr auto operator""_F(long double data) noexcept {
  return Farad(static_cast<Farad::ValueType>(data));
}

constexpr auto operator""_F(unsigned long long data) noexcept {
  return Farad(static_cast<Farad::ValueType>(data));
}

}  // namespace literals

}  // namespace csm_units