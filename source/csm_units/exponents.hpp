#pragma once

#include <ratio>

#include "source/csm_units/derived.hpp"

namespace csm_units {
// template <int num_l, int num_m, int num_t, int den_l, int den_m, int den_t>
// struct Exponents {};

// template <class T, class T2>
// struct ExponentsAddClass;
/*

template <template <typename, typename, typename, typename, typename, typename>
          class Exponent,
          class num_l, class num_m, class num_t, class den_l, class den_m,
          class den_t,
          template <typename, typename, typename, typename, typename, typename>
          class Exponent2,
          class num_l2, class num_m2, class num_t2, class den_l2, class den_m2,
          class den_t2>
struct ExponentsAddClass<
    Exponent<num_l, num_m, num_t, den_l, den_m, den_t>,
    Exponent2<num_l2, num_m2, num_t2, den_l2, den_m2, den_t2>> {
  using type = Exponents<
      std::ratio_add<std::ratio<num_l, den_l>, std::ratio<num_l2, den_l2>>::num,
      std::ratio_add<std::ratio<num_m, den_m>, std::ratio<num_m2, den_m2>>::num,
      std::ratio_add<std::ratio<num_t, den_t>, std::ratio<num_t2, den_t2>>::num,
      std::ratio_add<std::ratio<num_l, den_l>, std::ratio<num_l2, den_l2>>::den,
      std::ratio_add<std::ratio<num_m, den_m>, std::ratio<num_m2, den_m2>>::den,
      std::ratio_add<std::ratio<num_t, den_t>,
                     std::ratio<num_t2, den_t2>>::den>;
};

template <template <typename, typename, typename, typename, typename, typename>
          class Exponent,
          int num_l, int num_m, int num_t, int den_l, int den_m, int den_t,
          template <typename, typename, typename, typename, typename, typename>
          class Exponent2,
          int num_l2, int num_m2, int num_t2, int den_l2, int den_m2,
          int den_t2>
using ExponentsAdd = ExponentsAddClass<
    std::ratio_add<std::ratio<num_l, den_l>, std::ratio<num_l2, den_l2>>::num,
    std::ratio_add<std::ratio<num_m, den_m>, std::ratio<num_m2, den_m2>>::num,
    std::ratio_add<std::ratio<num_t, den_t>, std::ratio<num_t2, den_t2>>::num,
    std::ratio_add<std::ratio<num_l, den_l>, std::ratio<num_l2, den_l2>>::den,
    std::ratio_add<std::ratio<num_m, den_m>, std::ratio<num_m2, den_m2>>::den,
    std::ratio_add<std::ratio<num_t, den_t>, std::ratio<num_t2, den_t2>>::den>;

*/

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
template <class E1, class E2>
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

template <class E1, class E2>
using ExponentsAdd = typename detail::ExponentsAdd<E1, E2>::type;

}  // namespace csm_units