#pragma once

#include "../../unit.hpp"
#include "../../unitcast.hpp"
#include "dimension.hpp"

namespace csm_units {

using InvMeter = Unit<InvLength, "inv_m", double>;

// Unit Cast for Base invlength to Unit invm
template <>
[[nodiscard]] constexpr auto UnitCast(InvLength &&input) noexcept -> InvMeter {
  return InvMeter(input.data);
}

// Unit Cast for Unit invm to Base invlength
template <>
[[nodiscard]] constexpr auto UnitCast(InvMeter &&input) noexcept -> InvLength {
  return InvLength(input.data);
}

namespace literals {

constexpr auto operator""_inv_m(long double data) noexcept {
  return InvMeter(static_cast<double>(data));
}

}  // namespace literals

}  // namespace csm_units