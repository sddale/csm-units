/**  \file sqr_candela.hpp
 *   \brief This file is used to define the unit Square Candela derived from the
 * base dimension for Luminosity.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Candela">Candela</a> if needed.
 */

#pragma once

#include "../../definition.hpp"
#include "../../unit.hpp"
#include "dimension.hpp"

namespace csm_units {

namespace definition {

using SqCandela = Definition<SqLuminosity>;

}

using SqCandela = Unit<definition::SqCandela>;

namespace literals {

constexpr auto cd2 =  // NOLINT(readability-identifier-length)
    definition::SqCandela();

constexpr auto operator""_cd2(long double data) noexcept {
  return SqCandela(static_cast<SqCandela::type>(data));
}

constexpr auto operator""_cd2(unsigned long long data) noexcept {
  return SqCandela(static_cast<SqCandela::type>(data));
}

}  // namespace literals

}  // namespace csm_units