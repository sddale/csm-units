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

template <IsRatio Length = std::ratio<1>, IsRatio Mass = std::ratio<0>,
          IsRatio Time = std::ratio<0>, IsRatio Current = std::ratio<0>,
          IsRatio Temperature = std::ratio<0>, IsRatio Amount = std::ratio<0>,
          IsRatio Luminosity = std::ratio<0>>
struct Dimension {
  using L = Length;
  using M = Mass;
  using T = Time;
  using C = Current;
  using TP = Temperature;
  using A = Amount;
  using LM = Luminosity;
};

template <int Length = 1, int Mass = 0, int Time = 0, int Current = 0,
          int Temperature = 0, int Amount = 0, int Luminosity = 0>
using DimensionInt =
    Dimension<std::ratio<Length>, std::ratio<Mass>, std::ratio<Time>,
              std::ratio<Current>, std::ratio<Temperature>, std::ratio<Amount>,
              std::ratio<Luminosity>>;

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
  using type = Dimension<L, M, T, C, TP, A, LM>;
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
  using type = Dimension<L, M, T, C, TP, A, LM>;
};

template <IsDimension D, IsRatio R>
class DimensionMultiply {
  using L = typename std::ratio_multiply<typename D::L, R>::type;
  using M = typename std::ratio_multiply<typename D::M, R>::type;
  using T = typename std::ratio_multiply<typename D::T, R>::type;
  using C = typename std::ratio_multiply<typename D::C, R>::type;
  using TP = typename std::ratio_multiply<typename D::TP, R>::type;
  using A = typename std::ratio_multiply<typename D::A, R>::type;
  using LM = typename std::ratio_multiply<typename D::LM, R>::type;

 public:
  using type = Dimension<L, M, T, C, TP, A, LM>;
};

}  // namespace detail

template <IsDimension D1, IsDimension D2>
using DimensionAdd = typename detail::DimensionAdd<D1, D2>::type;

template <IsDimension D1, IsDimension D2>
using DimensionSubtract = typename detail::DimensionSubtract<D1, D2>::type;

template <IsDimension D, IsRatio R>
using DimensionMultiply = typename detail::DimensionMultiply<D, R>::type;

template <IsDimension D>
using DimensionFlip = Dimension<
    std::ratio<-D::L::num, D::L::den>, std::ratio<-D::M::num, D::M::den>,
    std::ratio<-D::T::num, D::T::den>, std::ratio<-D::C::num, D::C::den>,
    std::ratio<-D::TP::num, D::TP::den>, std::ratio<-D::A::num, D::A::den>,
    std::ratio<-D::LM::num, D::LM::den>>;

}  // namespace csm_units
