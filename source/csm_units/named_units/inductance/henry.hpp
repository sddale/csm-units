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

namespace definition {

using Henry = Definition<Inductance>;

}

using Henry = Unit<definition::Henry>;

namespace literals {

constexpr auto H =  // NOLINT(readability-identifier-length)
    Henry::def;

constexpr auto operator""_H(long double data) noexcept {
  return Henry(static_cast<Henry::ValueTypeeType>(data));
}

constexpr auto operator""_H(unsigned long long data) noexcept {
  return Henry(static_cast<Henry::ValueTypeeType>(data));
}

}  // namespace literals

}  // namespace csm_units
