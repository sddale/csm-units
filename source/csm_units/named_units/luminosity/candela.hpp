/**  \file candela.hpp
 *   \brief This file is used to define the Luminosity SI unit Candela.
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

using Candela = Definition<Luminosity>;

}

using Candela = Unit<definition::Candela>;

namespace literals {

constexpr auto cd =  // NOLINT(readability-identifier-length)
    definition::Candela();

constexpr auto operator""_cd(long double data) noexcept {
  return Candela(static_cast<Candela::type>(data));
}

constexpr auto operator""_cd(unsigned long long data) noexcept {
  return Candela(static_cast<Candela::type>(data));
}

}  // namespace literals

}  // namespace csm_units