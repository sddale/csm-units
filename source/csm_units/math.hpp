/**  \file math.hpp
 *   \brief This file defines simple math functions on Unit objects
 */

#pragma once

#include <csm_units/concepts.hpp>

namespace csm_units {

namespace detail {

template <int N>
struct UnitPow {
  static_assert(N > 0,
                "Unit power function only accepts non-negative integers.");

  [[nodiscard]] constexpr static auto Calc(IsUnit auto&& unit) noexcept {
    return unit * UnitPow<N - 1>::Calc(std::forward<decltype(unit)>(unit));
  }
};

template <>
struct UnitPow<0> {
  [[nodiscard]] constexpr static auto Calc(IsUnit auto&& /*unit*/) noexcept {
    return 1.0;
  }
};

}  // namespace detail

// Unit to positive integer power
template <int N>
[[nodiscard]] constexpr auto UnitPow(IsUnit auto&& unit) noexcept {
  return detail::UnitPow<N>::Calc(std::forward<decltype(unit)>(unit));
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