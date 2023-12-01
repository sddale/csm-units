/**  \file sqr_candela.hpp
 *   \brief This file is used to define the unit Square Candela derived from the
 * base dimension for Luminosity.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Candela">Candela</a> if needed.
 */

#pragma once

#include "../../unit.hpp"
#include "../../unitcast.hpp"
#include "dimension.hpp"

namespace csm_units {

using SqrCandela = Unit<SqrLuminosity, "cd2", double>;

template <>
[[nodiscard]] constexpr auto UnitCast(SqrLuminosity input) noexcept
    -> SqrCandela {
  return SqrCandela(input.data);
}

template <>
[[nodiscard]] constexpr auto UnitCast(SqrCandela input) noexcept
    -> SqrLuminosity {
  return SqrLuminosity(input.data);
}

namespace literals {

constexpr auto operator""_cd2(long double data) noexcept {
  return SqrCandela(static_cast<double>(data));
}

constexpr auto operator""_cd2(unsigned long long data) noexcept {
  return SqrCandela(static_cast<double>(data));
}

}  // namespace literals

}  // namespace csm_units