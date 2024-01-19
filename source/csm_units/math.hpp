/**  \file math.hpp
 *   \brief This file defines simple math functions on Unit objects
 */

#pragma once

#include <csm_units/concepts.hpp>
#include <utility>

namespace csm_units {

// Unit to positive integer power
template <int N>
[[nodiscard]] constexpr auto UnitPow(IsUnit auto&& unit) noexcept {
  if constexpr (N > 0) {
    return unit * UnitPow<N - 1>(std::forward<decltype(unit)>(unit));
  } else if constexpr (N < 0) {
    return 1.0 / (UnitPow<-1 * N>(std::forward<decltype(unit)>(unit)));
  } else {
    return 1.0;
  }
}

// Alias for squaring a unit
using csm_units::IsUnit;
[[nodiscard]] constexpr auto UnitSquare(IsUnit auto&& unit) noexcept {
  return UnitPow<2>(std::forward<decltype(unit)>(unit));
}

// Alias for cubing a unit
[[nodiscard]] constexpr auto UnitCube(IsUnit auto&& unit) noexcept {
  return UnitPow<3>(std::forward<decltype(unit)>(unit));
}

}  // namespace csm_units