#pragma once

#include "../../unit.hpp"
#include "../../unitcast.hpp"
#include "dimension.hpp"

namespace csm_units {

using Siemens = Unit<Conductance, "S", double>;

// Unit Cast for Base Siemens
template <>
[[nodiscard]] constexpr auto UnitCast(Conductance &&input) noexcept -> Siemens {
  return Siemens(input.data);
}
template <>
[[nodiscard]] constexpr auto UnitCast(Siemens &&input) noexcept -> Conductance {
  return Conductance(input.data);
}

constexpr auto operator""_S(long double data) noexcept {
  return Siemens(static_cast<double>(data));
}

}  // namespace csm_units