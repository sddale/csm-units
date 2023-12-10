/**  \file gray.hpp
 *   \brief This file is used to define the Absorbed Dose SI unit Gray.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Gray_(unit)">Gray</a> if needed.
 */

#pragma once

#include "../../definition.hpp"
#include "../../unit.hpp"
#include "dimension.hpp"

namespace csm_units {

using Gray = Unit<Definition<AbsorbedDose>>;

namespace literals {

constexpr auto operator""_Gy(long double data) noexcept {
  return Gray(static_cast<Gray::type>(data));
}

constexpr auto operator""_Gy(unsigned long long data) noexcept {
  return Gray(static_cast<Gray::type>(data));
}

}  // namespace literals

}  // namespace csm_units