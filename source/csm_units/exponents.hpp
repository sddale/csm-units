/**  \file exponents.hpp
 *   \brief This file defines what SI dimension a unit will be.
 *
 * The first seven parameters are the numerator for the Length, Mass, Time,
 * Electrical Current, Thermodynamic Temperature, Amount of a Substance, and
 * the Luminous Intensity in that order. Then the next seven are the denominator
 * allowing for decimal powers for each unit. The decimal is default to be one
 * if not give a value.
 */

#pragma once

#include <csm_units/concepts.hpp>
#include <ratio>

namespace csm_units {

template <int LN, int MN, int TN, int CN, int TPN, int AN, int LMN, int LD = 1,
          int MD = 1, int TD = 1, int CD = 1, int TPD = 1, int AD = 1,
          int LMD = 1>
struct Exponents {
  using L = std::ratio<LN, LD>;
  using M = std::ratio<MN, MD>;
  using T = std::ratio<TN, TD>;
  using C = std::ratio<CN, CD>;
  using TP = std::ratio<TPN, TPD>;
  using A = std::ratio<AN, AD>;
  using LM = std::ratio<LMN, LMD>;
};

namespace detail {

template <ExpType E1, ExpType E2>
class ExponentsAdd {
  template <int num, int den>
  using ratio = std::ratio<num, den>;

  using L = typename std::ratio_add<typename E1::L, typename E2::L>::type;
  using M = typename std::ratio_add<typename E1::M, typename E2::M>::type;
  using T = typename std::ratio_add<typename E1::T, typename E2::T>::type;
  using C = typename std::ratio_add<typename E1::C, typename E2::C>::type;
  using TP = typename std::ratio_add<typename E1::TP, typename E2::TP>::type;
  using A = typename std::ratio_add<typename E1::A, typename E2::A>::type;
  using LM = typename std::ratio_add<typename E1::LM, typename E2::LM>::type;

 public:
  using type =
      Exponents<L::num, M::num, T::num, C::num, TP::num, A::num, LM::num,
                L::den, M::den, T::den, C::den, TP::den, A::den, LM::den>;
};

template <ExpType E1, ExpType E2>
class ExponentsSubtract {
  template <int num, int den>
  using ratio = std::ratio<num, den>;

  using L = typename std::ratio_subtract<typename E1::L, typename E2::L>::type;
  using M = typename std::ratio_subtract<typename E1::M, typename E2::M>::type;
  using T = typename std::ratio_subtract<typename E1::T, typename E2::T>::type;
  using C = typename std::ratio_subtract<typename E1::C, typename E2::C>::type;
  using TP =
      typename std::ratio_subtract<typename E1::TP, typename E2::TP>::type;
  using A = typename std::ratio_subtract<typename E1::A, typename E2::A>::type;
  using LM =
      typename std::ratio_subtract<typename E1::LM, typename E2::LM>::type;

 public:
  using type =
      Exponents<L::num, M::num, T::num, C::num, TP::num, A::num, LM::num,
                L::den, M::den, T::den, C::den, TP::den, A::den, LM::den>;
};

}  // namespace detail

template <ExpType E1, ExpType E2>
using ExponentsAdd = typename detail::ExponentsAdd<E1, E2>::type;

template <ExpType E1, ExpType E2>
using ExponentsSubtract = typename detail::ExponentsSubtract<E1, E2>::type;

template <ExpType E>
using ExponentsFlip =
    Exponents<-E::L::num, -E::M::num, -E::T::num, -E::C::num, -E::TP::num,
              -E::A::num, -E::LM::num, E::L::den, E::M::den, E::T::den,
              E::C::den, E::TP::den, E::A::den, E::LM::den>;

}  // namespace csm_units