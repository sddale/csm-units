#pragma once

#include "../../unit.hpp"
#include "../../unitcast.hpp"
#include "dimension.hpp"

namespace csm_units {

using Gram = Unit<Mass, "g", double>;

// Unit Cast for Base g to Unit g
template <>
[[nodiscard]] constexpr auto UnitCast(Mass &&input) noexcept -> Gram {
  return Gram(input.data * 1000);
}

// Unit Cast for Unit g to Base g
template <>
[[nodiscard]] constexpr auto UnitCast(Gram &&input) noexcept -> Mass {
  return Mass(input.data / 1000);
}

constexpr auto operator""_g(long double data) noexcept {
  return Gram(static_cast<double>(data));
}

}  // namespace csm_units