#pragma once

#include "../../unit.hpp"
#include "../../unitcast.hpp"
#include "dimension.hpp"

namespace csm_units {

using Farad = Unit<Capacitance, "F", double>;

// Unit Cast for Base farad
template <>
[[nodiscard]] constexpr auto UnitCast(Capacitance &&input) noexcept -> Farad {
  return Farad(input.data);
}

// Unit Cast for Unit farad
template <>
[[nodiscard]] constexpr auto UnitCast(Farad &&input) noexcept -> Capacitance {
  return Capacitance(input.data);
}

namespace literals {

constexpr auto operator""_F(long double data) noexcept {
  return Farad(static_cast<double>(data));
}

}  // namespace literals

}  // namespace csm_units