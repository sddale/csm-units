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

#ifndef CSMUNITS_VALUE_TYPE
#define CSMUNITS_VALUE_TYPE double
#endif

namespace csm_units {

namespace detail {

// Simple implementation via Heron's method
template <class T>
struct Sqrt {
  constexpr auto operator()(T input) noexcept {
    constexpr auto abs = [](auto&& n) { return n < 0 ? -n : n; };
    auto value = T{1};
    while (abs(value * value - input) > 1e-12) {
      value = 0.5 * (value + input / value);
    }
    return value;
  }
};

// Simple implementation via Newton's method
template <class T>
struct Cbrt {
  constexpr auto operator()(T input) noexcept {
    constexpr auto abs = [](auto&& n) { return n < 0 ? -n : n; };
    auto value = T{1};
    while (abs(value * value * value - input) > 1e-12) {
      value = 1. / 3 * (2 * value + input / (value * value));
    }
    return value;
  }
};

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
template <IsUnit U, class SqrRootF = detail::Sqrt<CSMUNITS_VALUE_TYPE>>
[[nodiscard]] constexpr auto UnitSqrt(U&& unit) noexcept {
  static_assert(
      SciNoEqual<typename U::DefType::ConvType, SciNo<std::ratio<1, 1>, 0>>,
      "Sqrt input unit requires conversion factor == 1");
  return Unit<Definition<
      DimensionMultiply<typename U::DefType::DimenType, std::ratio<1, 2>>>{}>(
      SqrRootF()(unit.data));
}

// Unit cubic root
template <IsUnit U, class CbRootF = detail::Cbrt<CSMUNITS_VALUE_TYPE>>
[[nodiscard]] constexpr auto UnitCbrt(U&& unit) noexcept {
  static_assert(
      SciNoEqual<typename U::DefType::ConvType, SciNo<std::ratio<1, 1>, 0>>,
      "Cbrt input unit requires conversion factor == 1");
  return Unit<Definition<
      DimensionMultiply<typename U::DefType::DimenType, std::ratio<1, 3>>>{}>(
      CbRootF()(unit.data));
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