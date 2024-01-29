// replace std::ratio to avoid overflowing LL from conversions such as nm3
#pragma once
#include <csm_units/concepts.hpp>
#include <ratio>

#ifndef CSMUNITS_VALUE_TYPE
#define CSMUNITS_VALUE_TYPE double
#endif

namespace csm_units {

template <IsRatio Mag, int Order = 0>
class SciNo {
  template <int n>
  struct StaticAbs {
    constexpr static int value = n < 0 ? -n : n;
  };

 public:
  constexpr static auto ord = [] {
    constexpr auto num = StaticAbs<Mag::num / Mag::den>::value;
    if constexpr (Mag::num == 0) {
      return 0;
    } else if constexpr (num >= 10) {
      return SciNo<std::ratio_multiply<Mag, std::ratio<1, 10>>, Order>::ord + 1;
    } else if constexpr (num < 1) {
      return SciNo<std::ratio_multiply<Mag, std::ratio<10, 1>>, Order>::ord - 1;
    } else {
      return Order;
    }
  }();
  constexpr static auto mag = [] {
    if constexpr (ord > Order) {
      return SciNo<std::ratio_multiply<Mag, std::ratio<1, 10>>, Order>::mag;
    } else if constexpr (ord < Order) {
      return SciNo<std::ratio_multiply<Mag, std::ratio<10, 1>>, Order>::mag;
    } else {
      return Mag();
    }
  }();

  using MagType = decltype(mag);
};

namespace detail {

template <IsSciNo L, IsSciNo R>
struct SciNoMultiply {
  using type =
      SciNo<std::ratio_multiply<typename L::MagType, typename R::MagType>,
            L::ord + R::ord>;
};

template <IsSciNo L, IsSciNo R>
struct SciNoDivide {
  using type =
      SciNo<std::ratio_divide<typename L::MagType, typename R::MagType>,
            L::ord - R::ord>;
};

template <IsSciNo L, IsSciNo R>
struct SciNoEqual
    : std::bool_constant<
          std::ratio_equal_v<typename L::MagType, typename R::MagType> and
          L::ord == R::ord> {};

template <IsSciNo L, IsSciNo R>
struct SciNoNotEqual
    : std::bool_constant<
          std::ratio_not_equal_v<typename L::MagType, typename R::MagType> or
          L::ord != R::ord> {};

template <IsSciNo S>
class SciNoDecimal {
  template <int N>
  [[nodiscard]] constexpr static auto StaticPow() noexcept {
    if constexpr (N > 0) {
      return 10 * StaticPow<N - 1>();
    } else if constexpr (N < 0) {
      return 1 / StaticPow<-N>();
    } else {
      return 1.0;
    }
  }

 public:
  constexpr static auto value =
      static_cast<CSMUNITS_VALUE_TYPE>(S::MagType::num) / S::MagType::den *
      StaticPow<S::ord>();
};

}  // namespace detail

template <IsSciNo L, IsSciNo R>
using SciNoMultiply = detail::SciNoMultiply<L, R>::type;

template <IsSciNo L, IsSciNo R>
using SciNoDivide = detail::SciNoDivide<L, R>::type;

template <IsSciNo L, IsSciNo R>
constexpr auto SciNoEqual = detail::SciNoEqual<L, R>::value;

template <IsSciNo L, IsSciNo R>
constexpr auto SciNoNotEqual = detail::SciNoNotEqual<L, R>::value;

template <IsSciNo S>
constexpr auto SciNoDecimal = detail::SciNoDecimal<S>::value;

}  // namespace csm_units