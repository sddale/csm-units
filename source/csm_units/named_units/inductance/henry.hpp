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

constexpr auto s =  // NOLINT(readability-identifier-length)
    definition::Henry();

constexpr auto operator""_s(long double data) noexcept {
  return Henry(static_cast<Henry::type>(data));
}

constexpr auto operator""_s(unsigned long long data) noexcept {
  return Henry(static_cast<Henry::type>(data));
}

}  // namespace literals

}  // namespace csm_units
