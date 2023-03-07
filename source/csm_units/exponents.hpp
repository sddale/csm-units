#pragma once

#include <concepts>
#include <csm_units/concepts.hpp>
#include <ratio>
#include <vector>

#include "derived.hpp"

namespace csm_units {

template <int LN, int MN, int TN, int LD = 1, int MD = 1, int TD = 1>
struct Exponents {
  constexpr static int l_num = LN;
  constexpr static int l_den = LD;
  constexpr static int m_num = MN;
  constexpr static int m_den = MD;
  constexpr static int t_num = TN;
  constexpr static int t_den = TD;
};

namespace detail {

template <ExpType E1, ExpType E2>
class ExponentsAdd {
  template <int num, int den>
  using ratio = std::ratio<num, den>;

  using L = typename std::ratio_add<ratio<E1::l_num, E1::l_den>,
                                    ratio<E2::l_num, E2::l_den>>::type;
  using M = typename std::ratio_add<ratio<E1::m_num, E1::m_den>,
                                    ratio<E2::m_num, E2::m_den>>::type;
  using T = typename std::ratio_add<ratio<E1::t_num, E1::t_den>,
                                    ratio<E2::t_num, E2::t_den>>::type;

 public:
  using type = Exponents<L::num, M::num, T::num, L::den, M::den, T::den>;
};

}  // namespace detail

template <ExpType E1, ExpType E2>
using ExponentsAdd = typename detail::ExponentsAdd<E1, E2>::type;

}  // namespace csm_units