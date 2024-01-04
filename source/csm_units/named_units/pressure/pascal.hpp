/**  \file pascal.hpp
 *   \brief This file is used to define the Pressure SI unit Pascal.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Pascal_(unit)">Pascal</a> if needed.
 */

#pragma once

#include "../../definition.hpp"
#include "../../unit.hpp"
#include "dimension.hpp"

namespace csm_units {

namespace definition {

using Pascal = Definition<Pressure>;

}

using Pascal = Unit<definition::Pascal>;

namespace literals {

constexpr auto Pa =  // NOLINT(readability-identifier-length)
    definition::Pascal();

constexpr auto operator""_Pa(long double data) noexcept {
  return Pascal(static_cast<Pascal::type>(data));
}

constexpr auto operator""_Pa(unsigned long long data) noexcept {
  return Pascal(static_cast<Pascal::type>(data));
}

}  // namespace literals

}  // namespace csm_units