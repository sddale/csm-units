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

using Watt = Unit<Definition<Power>{}>;

namespace literals {

constexpr auto W =  // NOLINT(readability-identifier-length)
    Watt::def;

constexpr auto operator""_W(long double data) noexcept {
  return Watt(static_cast<Watt::ValueType>(data));
}

constexpr auto operator""_W(unsigned long long data) noexcept {
  return Watt(static_cast<Watt::ValueType>(data));
}

}  // namespace literals

}  // namespace csm_units