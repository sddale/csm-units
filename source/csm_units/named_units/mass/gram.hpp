/**  \file gram.hpp
 *   \brief This file is used to define the unit Gram derived from the base
 * dimension for Mass.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Gram">Gram</a> if needed.
 */
#pragma once

#include "../../definition.hpp"
#include "../../unit.hpp"
#include "dimension.hpp"

namespace csm_units {

namespace definition {

using Gram = Definition<Mass, NoConv, std::milli>;

}

using Gram = Unit<definition::Gram>;

namespace literals {

constexpr auto g =  // NOLINT(readability-identifier-length)
    definition::Gram();

constexpr auto operator""_g(long double data) noexcept {
  return Gram(static_cast<Gram::type>(data));
}

constexpr auto operator""_g(unsigned long long data) noexcept {
  return Gram(static_cast<Gram::type>(data));
}

}  // namespace literals

}  // namespace csm_units