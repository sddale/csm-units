/**  \file sq_candela.hpp
 *   \brief This file is used to define the unit Square Candela derived from the
 * base dimension for Luminosity.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Candela">Candela</a> if needed. Square
 * Candela having a close description to this.
 */

#pragma once

#include "../../definition.hpp"
#include "../../unit.hpp"
#include "candela.hpp"

namespace csm_units {

using SqCandela = Unit<literals::cd * literals::cd>;

namespace literals {

constexpr auto cd2 =  // NOLINT(readability-identifier-length)
    SqCandela::def;

constexpr auto operator""_cd2(long double data) noexcept {
  return SqCandela(static_cast<SqCandela::ValueType>(data));
}

constexpr auto operator""_cd2(unsigned long long data) noexcept {
  return SqCandela(static_cast<SqCandela::ValueType>(data));
}

}  // namespace literals

}  // namespace csm_units