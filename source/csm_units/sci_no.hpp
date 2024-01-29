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
  template <IsRatio R>
  [[nodiscard]] consteval static auto StaticLog10() noexcept -> int {
    constexpr int dec = R::num / R::den;
    constexpr int abs = dec < 0 ? -dec : dec;
    if constexpr ((abs >= 1 and abs < 10) or R::num == 0) {
      return 0;
    } else if constexpr (abs >= 10) {
      return StaticLog10<std::ratio_divide<R, std::ratio<10>>>() + 1;
    } else {
      return StaticLog10<std::ratio_multiply<R, std::ratio<10>>>() - 1;
    }
  }

  template <int N>
  [[nodiscard]] consteval static auto StaticPow10() noexcept {
    if constexpr (N > 0) {
      return std::ratio_divide<decltype(StaticPow10<N - 1>()),
                               std::ratio<10>>();
    } else if constexpr (N < 0) {
      return std::ratio_multiply<decltype(StaticPow10<N + 1>()),
                                 std::ratio<10>>();
    } else {
      return std::ratio<1>();
    }
  }

 public:
  constexpr static auto ord = Order + StaticLog10<Mag>();

  using MagType =
      std::ratio_multiply<Mag, decltype(StaticPow10<ord - Order>())>;
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
  [[nodiscard]] consteval static auto StaticPow10() noexcept {
    if constexpr (N > 0) {
      return 10 * StaticPow10<N - 1>();
    } else if constexpr (N < 0) {
      return 1 / StaticPow10<-N>();
    } else {
      return CSMUNITS_VALUE_TYPE(1);
    }
  }

 public:
  constexpr static auto value =
      static_cast<CSMUNITS_VALUE_TYPE>(S::MagType::num) / S::MagType::den *
      StaticPow10<S::ord>();
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