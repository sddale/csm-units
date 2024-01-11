/**  \file henry.hpp
 *   \brief This file is used to define the Inductance SI unit Henry.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Henry_(unit)">Henry</a> if needed.
 */

#pragma once

#include "../../definition.hpp"
#include "../../unit.hpp"
#include "dimension.hpp"

namespace csm_units {

using Henry = Unit<Definition<Inductance>{}>;

namespace literals {

constexpr auto H =  // NOLINT(readability-identifier-length)
    Henry::def;

constexpr auto operator""_H(long double data) noexcept {
  return Henry(static_cast<Henry::ValueType>(data));
}

constexpr auto operator""_H(unsigned long long data) noexcept {
  return Henry(static_cast<Henry::ValueType>(data));
}

}  // namespace literals

}  // namespace csm_units
