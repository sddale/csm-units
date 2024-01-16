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

using Pascal = Unit<Definition<Pressure>{}>;

namespace literals {

constexpr auto Pa =  // NOLINT(readability-identifier-length)
    Pascal::def;

constexpr auto operator""_Pa(long double data) noexcept {
  return Pascal(static_cast<Pascal::ValueType>(data));
}

constexpr auto operator""_Pa(unsigned long long data) noexcept {
  return Pascal(static_cast<Pascal::ValueType>(data));
}

}  // namespace literals

}  // namespace csm_units