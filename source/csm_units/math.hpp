/**  \file math.hpp
 *   \brief This file defines simple math functions on Unit objects
 */

#pragma once

#include <csm_units/concepts.hpp>
#include <utility>

#include "definition.hpp"
#include "dimension.hpp"
#include "sci_no.hpp"
#include "unit.hpp"

namespace csm_units {

namespace detail {

// Simple implementation of Heron's method
[[nodiscard]] constexpr auto Sqrt(auto&& value) noexcept {
  constexpr auto abs = [](auto&& n) { return n < 0 ? -n : n; };
  auto result = std::remove_cvref_t<decltype(value)>(1);
  while (abs(result * result - value) > 1e-12) {
    result = 0.5 * (result + value / result);
  }
  return result;
}

}  // namespace detail

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

// Unit square root
template <IsUnit U>
[[nodiscard]] constexpr auto UnitSqrt(U&& unit) noexcept {
  static_assert(
      SciNoEqual<typename U::DefType::ConvType, SciNo<std::ratio<1, 1>, 0>>,
      "Sqrt input unit requires conversion factor == 1");
  return Unit<Definition<
      DimensionMultiply<typename U::DefType::DimenType, std::ratio<1, 2>>>{}>(
      detail::Sqrt(unit.data));
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