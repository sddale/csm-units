/**  \file dimension.hpp
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

template <int LN = 1, int MN = 0, int TN = 0, int CN = 0, int TPN = 0,
          int AN = 0, int LMN = 0, int LD = 1, int MD = 1, int TD = 1,
          int CD = 1, int TPD = 1, int AD = 1, int LMD = 1>
struct Dimension {
  using L = std::ratio<LN, LD>;
  using M = std::ratio<MN, MD>;
  using T = std::ratio<TN, TD>;
  using C = std::ratio<CN, CD>;
  using TP = std::ratio<TPN, TPD>;
  using A = std::ratio<AN, AD>;
  using LM = std::ratio<LMN, LMD>;
};

namespace detail {

template <IsDimension D1, IsDimension D2>
class DimensionAdd {
  using L = typename std::ratio_add<typename D1::L, typename D2::L>::type;
  using M = typename std::ratio_add<typename D1::M, typename D2::M>::type;
  using T = typename std::ratio_add<typename D1::T, typename D2::T>::type;
  using C = typename std::ratio_add<typename D1::C, typename D2::C>::type;
  using TP = typename std::ratio_add<typename D1::TP, typename D2::TP>::type;
  using A = typename std::ratio_add<typename D1::A, typename D2::A>::type;
  using LM = typename std::ratio_add<typename D1::LM, typename D2::LM>::type;

 public:
  using type =
      Dimension<L::num, M::num, T::num, C::num, TP::num, A::num, LM::num,
                L::den, M::den, T::den, C::den, TP::den, A::den, LM::den>;
};

template <IsDimension D1, IsDimension D2>
class DimensionSubtract {
  using L = typename std::ratio_subtract<typename D1::L, typename D2::L>::type;
  using M = typename std::ratio_subtract<typename D1::M, typename D2::M>::type;
  using T = typename std::ratio_subtract<typename D1::T, typename D2::T>::type;
  using C = typename std::ratio_subtract<typename D1::C, typename D2::C>::type;
  using TP =
      typename std::ratio_subtract<typename D1::TP, typename D2::TP>::type;
  using A = typename std::ratio_subtract<typename D1::A, typename D2::A>::type;
  using LM =
      typename std::ratio_subtract<typename D1::LM, typename D2::LM>::type;

 public:
  using type =
      Dimension<L::num, M::num, T::num, C::num, TP::num, A::num, LM::num,
                L::den, M::den, T::den, C::den, TP::den, A::den, LM::den>;
};

}  // namespace detail

template <IsDimension D1, IsDimension D2>
using DimensionAdd = typename detail::DimensionAdd<D1, D2>::type;

template <IsDimension D1, IsDimension D2>
using DimensionSubtract = typename detail::DimensionSubtract<D1, D2>::type;

template <IsDimension D>
using DimensionFlip =
    Dimension<-D::L::num, -D::M::num, -D::T::num, -D::C::num, -D::TP::num,
              -D::A::num, -D::LM::num, D::L::den, D::M::den, D::T::den,
              D::C::den, D::TP::den, D::A::den, D::LM::den>;

}  // namespace csm_units