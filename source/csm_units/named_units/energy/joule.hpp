#pragma once

#include "../../unit.hpp"
#include "../../unitcast.hpp"
#include "dimension.hpp"

namespace csm_units {

using Joule = Unit<Energy, "J", double>;

// Unit Cast for Base Joule
template <>
[[nodiscard]] constexpr auto UnitCast(Energy &&input) noexcept -> Joule {
  return Joule(input.data);
}
template <>
[[nodiscard]] constexpr auto UnitCast(Joule &&input) noexcept -> Energy {
  return Energy(input.data);
}

constexpr auto operator""_J(long double data) noexcept {
  return Joule(static_cast<double>(data));
}

}  // namespace csm_units