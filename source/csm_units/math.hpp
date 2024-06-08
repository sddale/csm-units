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
    const auto coeffs = std::pair<T, T>{static_cast<double>(N - 1) / N,
                                        static_cast<double>(input) / N};
    for (auto pow = Pow<N - 1, T>()(value); abs(pow * value - input) > 1e-12;) {
      value = coeffs.first * value + coeffs.second / pow;
      pow = Pow<N - 1, T>()(value);
    }
    return value;
  }
};

}  // namespace detail

// Unit to real power (via std::ratio exponent)
// Specify root algo via RootF. Requires operator() overload for calling.
// Function always return units of SI base i.e. UnitPow<2,cm> -> m^2
template <IsRatio N, IsUnit U,
          class RootF = detail::Root<N::den, typename U::ValueType>>
  requires requires { RootF()(typename U::ValueType{1}); }
[[nodiscard]] constexpr auto UnitPow(U&& unit) noexcept {
  if constexpr (N::num == 0) {
    return typename U::ValueType{1};
  } else if constexpr (N::num < 0) {
    return 1.0 / UnitPow<std::ratio<-1 * N::num, N::den>, U, RootF>(
                     std::forward<U>(unit));
  } else {  // Take x^(1/den)^num
    using Dimen = DimensionMultiply<typename U::DimenType, N>;
    using Data = U::ValueType;
    using BaseUnit = Unit<Definition<Dimen>{}, Data>;
    return BaseUnit(
        detail::Pow<N::num, Data>()(RootF()(std::forward<Data>(unit.data))));
  }
}

// Alias with two integer templates
template <int N, int D = 1>
[[nodiscard]] constexpr auto UnitPow(IsUnit auto&& unit) noexcept {
  return UnitPow<std::ratio<N, D>>(std::forward<decltype(unit)>(unit));
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