#pragma once

#include <concepts>
#include <csm_units/concepts.hpp>
#include <ratio>
#include <vector>

namespace csm_units {

template <int LN, int MN, int TN, int LD = 1, int MD = 1, int TD = 1>
struct Exponents {
  using L = std::ratio<LN, LD>;
  using M = std::ratio<MN, MD>;
  using T = std::ratio<TN, TD>;
};

namespace detail {

template <ExpType E1, ExpType E2>
class ExponentsAdd {
  template <int num, int den>
  using ratio = std::ratio<num, den>;

  using L = typename std::ratio_add<typename E1::L, typename E2::L>::type;
  using M = typename std::ratio_add<typename E1::M, typename E2::M>::type;
  using T = typename std::ratio_add<typename E1::T, typename E2::T>::type;

 public:
  using type = Exponents<L::num, M::num, T::num, L::den, M::den, T::den>;
};

template <ExpType E1, ExpType E2>
class ExponentsSubtract {
  template <int num, int den>
  using ratio = std::ratio<num, den>;

  using L = typename std::ratio_subtract<typename E1::L, typename E2::L>::type;
  using M = typename std::ratio_subtract<typename E1::M, typename E2::M>::type;
  using T = typename std::ratio_subtract<typename E1::T, typename E2::T>::type;

 public:
  using type = Exponents<L::num, M::num, T::num, L::den, M::den, T::den>;
};

}  // namespace detail

template <ExpType E1, ExpType E2>
using ExponentsAdd = typename detail::ExponentsAdd<E1, E2>::type;

template <ExpType E1, ExpType E2>
using ExponentsSubtract = typename detail::ExponentsSubtract<E1, E2>::type;

template <ExpType E>
using ExponentsFlip = Exponents<-E::L::num, -E::M::num, -E::T::num, E::L::den,
                                E::M::den, E::T::den>;

}  // namespace csm_units