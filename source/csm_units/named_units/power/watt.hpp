/**  \file watt.hpp
 *   \brief This file is used to define the Power SI unit Watt.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Watt">Watt</a> if needed.
 */

#pragma once

#include "../../definition.hpp"
#include "../../unit.hpp"
#include "dimension.hpp"

namespace csm_units {

namespace definition {

using Watt = Definition<Power>;

}

using Watt = Unit<definition::Watt>;

namespace literals {

constexpr auto W =  // NOLINT(readability-identifier-length)
    definition::Watt();

constexpr auto operator""_W(long double data) noexcept {
  return Watt(static_cast<Watt::type>(data));
}

constexpr auto operator""_W(unsigned long long data) noexcept {
  return Watt(static_cast<Watt::type>(data));
}

}  // namespace literals

}  // namespace csm_units