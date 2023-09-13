/**  \file candela.hpp
 *   \brief This file is used to define the Luminosity SI unit Candela.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Candela">Candela</a> if needed.
 */

#pragma once

#include "../../unit.hpp"
#include "../../unitcast.hpp"
#include "dimension.hpp"

namespace csm_units {

using Candela = Unit<Luminosity, "cd", double>;

// Unit Cast for Unit Candela
template <>
[[nodiscard]] constexpr auto UnitCast(Luminosity &&input) noexcept -> Candela {
  return Candela(input.data);
}

// Unit Cast for Unit Candela
template <>
[[nodiscard]] constexpr auto UnitCast(Candela &&input) noexcept -> Luminosity {
  return Luminosity(input.data);
}

namespace literals {

// luminosity - candela
constexpr auto operator""_cd(long double data) noexcept {
  return Candela(static_cast<double>(data));
}

constexpr auto operator""_cd(unsigned long long data) noexcept {
  return Candela(static_cast<double>(data));
}

}  // namespace literals

}  // namespace csm_units