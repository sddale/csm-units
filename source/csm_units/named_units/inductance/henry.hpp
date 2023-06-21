/**  \file henry.hpp
 *   \brief This file is used to define the Inductance SI unit Henry.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Henry_(unit)">Henry</a> if needed.
 */

#pragma once

#include "../../unit.hpp"
#include "../../unitcast.hpp"
#include "dimension.hpp"

namespace csm_units {

using Henry = Unit<Inductance, "H", double>;

// Unit Cast for Unit Henry
template <>
[[nodiscard]] constexpr auto UnitCast(Inductance &&input) noexcept -> Henry {
  return Henry(input.data);
}

// Unit Cast for Unit Henry
template <>
[[nodiscard]] constexpr auto UnitCast(Henry &&input) noexcept -> Inductance {
  return Inductance(input.data);
}

namespace literals {

constexpr auto operator""_H(long double data) noexcept {
  return Henry(static_cast<double>(data));
}

}  // namespace literals

}  // namespace csm_units