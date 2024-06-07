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

// Simple implementation of real number to integer power
template <int N, class T>
struct Pow {
  constexpr auto operator()(T input) noexcept {
    if constexpr (N >= 0) {
      auto result = T{1};
      for (int i = 0; i < N; ++i) {
        result *= input;
      }
      return result;
    } else {
      return 1.0 / Pow<-N, T>()(input);
    }
  }
};

// Simple implementation via Newton's method for nth root
template <int N, class T>
struct Root {
  constexpr auto operator()(T input) noexcept {
    constexpr auto abs = [](auto&& n) { return n < 0 ? -n : n; };
    auto value = T{1};
    const auto coeffs = std::pair{static_cast<double>(N - 1) / N,
                                  static_cast<double>(input) / N};
    while (abs(Pow<N, T>()(value) - input) > 1e-12) {
      value = coeffs.first * value + coeffs.second / Pow<N - 1, T>()(value);
    }
    return value;
  }
};

}  // namespace detail

// Unit to real power (via std::ratio exponent)
// Specify root algo via RootF. Requires operator() overload for calling.
template <IsRatio pow, IsUnit U,
          class RootF = detail::Root<pow::den, typename U::ValueType>>
  requires requires { RootF()(typename U::ValueType{1}); }
[[nodiscard]] constexpr auto UnitPow(U&& unit) noexcept {
  if constexpr (pow::num == 0) {
    return typename U::ValueType{1};
  } else if constexpr (pow::num < 0) {
    return 1.0 / UnitPow<std::ratio<-1 * pow::num, pow::den>>(
                     std::forward<decltype(unit)>(unit));
  } else {  // Take x^(1/den)^num
    using Dimen = typename U::DefType::DimenType;
    using Data = typename U::ValueType;
    using Result = Unit<Definition<DimensionMultiply<Dimen, pow>>{}, Data>;
    return Result(detail::Pow<pow::num, Data>()(RootF()(unit.data)));
  }
}

// Alias for unit to integer power
template <int N>
[[nodiscard]] constexpr auto UnitPow(IsUnit auto&& unit) noexcept {
  return UnitPow<std::ratio<N>>(std::forward<decltype(unit)>(unit));
}

// Alias for unit square root
[[nodiscard]] constexpr auto UnitSqrt(IsUnit auto&& unit) noexcept {
  return UnitPow<std::ratio<1, 2>>(std::forward<decltype(unit)>(unit));
}

// Alias for unit cubic root
[[nodiscard]] constexpr auto UnitCbrt(IsUnit auto&& unit) noexcept {
  return UnitPow<std::ratio<1, 3>>(std::forward<decltype(unit)>(unit));
}

// Alias for unit square
[[nodiscard]] constexpr auto UnitSquare(IsUnit auto&& unit) noexcept {
  return UnitPow<2>(std::forward<decltype(unit)>(unit));
}

// Alias for unit cube
[[nodiscard]] constexpr auto UnitCube(IsUnit auto&& unit) noexcept {
  return UnitPow<3>(std::forward<decltype(unit)>(unit));
}

}  // namespace csm_units