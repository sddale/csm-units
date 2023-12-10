/**  \file literals.hpp
 *   \brief This file defines a more verbose version of user defined literals.
 *
 * Allows for the combination of user defined literal with different binary
 * arithmetic operators to create a unit from scratch. Then defining a decimal
 * number with that unit.
 */

#pragma once

#include <csm_units/concepts.hpp>
#include <gcem.hpp>
#include <ratio>

#include "exponents.hpp"

#ifndef CSMUNITS_VALUE_TYPE
#define CSMUNITS_VALUE_TYPE double
#endif

namespace csm_units {

using concepts::Arithmetic;
using concepts::ExpType;

template <ExpType Dimension, concepts::Ratio ConvLen = std::ratio<1>,
          concepts::Ratio ConvMass = std::ratio<1>,
          concepts::Ratio ConvTime = std::ratio<1>,
          concepts::Ratio ConvElec = std::ratio<1>,
          concepts::Ratio ConvTemper = std::ratio<1>,
          concepts::Ratio ConvAmount = std::ratio<1>,
          concepts::Ratio ConvLight = std::ratio<1>>
class Definition {
 public:
  using dim = Dimension;
  using conv_len = ConvLen;
  using conv_mass = ConvMass;
  using conv_time = ConvTime;
  using conv_elec = ConvElec;
  using conv_temper = ConvTemper;
  using conv_amount = ConvAmount;
  using conv_light = ConvLight;

  constexpr static auto Get() {
    return Convert<conv_len, typename dim::L>().value *
           Convert<conv_mass, typename dim::M>().value *
           Convert<conv_time, typename dim::T>().value *
           Convert<conv_elec, typename dim::C>().value *
           Convert<conv_temper, typename dim::TP>().value *
           Convert<conv_amount, typename dim::A>().value *
           Convert<conv_light, typename dim::LM>().value;
  }
  constexpr static auto ToSI() {
    return InvConvert<conv_len, typename dim::L>().value *
           InvConvert<conv_mass, typename dim::M>().value *
           InvConvert<conv_time, typename dim::T>().value *
           InvConvert<conv_elec, typename dim::C>().value *
           InvConvert<conv_temper, typename dim::TP>().value *
           InvConvert<conv_amount, typename dim::A>().value *
           InvConvert<conv_light, typename dim::LM>().value;
  }

  // constexpr friend auto operator*(Arithmetic auto lhs, Definition /*rhs*/) {
  //   return Unit<Definition, decltype(lhs)>(lhs);
  // }
  // template <concepts::Definition D>
  // constexpr friend auto operator*(D /*lhs*/, Definition /*rhs*/) {
  //   return Unit<Multiply<D>>(1.0);
  // }
  // template <concepts::Definition D, Arithmetic Data>
  // constexpr friend auto operator*(Unit<D, Data> lhs, Definition /*rhs*/) {
  //   return Unit<Multiply<D>, Data>(lhs.data);
  // }
  // constexpr friend auto operator/(Arithmetic auto lhs, Definition /*rhs*/) {
  //   return Unit<InverseDef, decltype(lhs)>(lhs);
  // }
  // template <concepts::Definition D>
  // constexpr friend auto operator/(D /*lhs*/, Definition /*rhs*/) {
  //   return Unit<Divide<D>>(1.0);
  // }
  // template <concepts::Definition D, Arithmetic Data>
  // constexpr friend auto operator/(Unit<D, Data> lhs, Definition /*rhs*/) {
  //   return Unit<Divide<D>, Data>(lhs.data);
  // }

  template <concepts::Ratio RL, concepts::Ratio RR, concepts::Ratio Pow>
  struct Selector {
    using val = RL;
  };

  template <concepts::Ratio RL, concepts::Ratio RR>
  struct Selector<RL, RR, std::ratio<0>> {
    using val = std::ratio<1, 1>;
  };

  template <concepts::Ratio RL, concepts::Ratio Pow>
    requires(!std::same_as<Pow, std::ratio<0>>)
  struct Selector<RL, std::ratio<1>, Pow> {
    using val = RL;
  };

  template <concepts::Ratio RR, concepts::Ratio Pow>
    requires(!std::same_as<Pow, std::ratio<0>>)
  struct Selector<std::ratio<1>, RR, Pow> {
    using val = RR;
  };

  template <concepts::Ratio Pow>
    requires(!std::same_as<Pow, std::ratio<0>>)
  struct Selector<std::ratio<1>, std::ratio<1>, Pow> {
    using val = std::ratio<1>;
  };

  template <concepts::Definition A>
  struct Multiply_ {
   private:
    using dimension = ExponentsAdd<typename A::dim, dim>;

   public:
    using val =
        Definition<ExponentsAdd<typename A::dim, dim>,
                   typename Selector<typename A::conv_len, conv_len,
                                     typename dimension::L>::val,
                   typename Selector<typename A::conv_mass, conv_mass,
                                     typename dimension::M>::val,
                   typename Selector<typename A::conv_time, conv_time,
                                     typename dimension::T>::val,
                   typename Selector<typename A::conv_elec, conv_elec,
                                     typename dimension::C>::val,
                   typename Selector<typename A::conv_temper, conv_temper,
                                     typename dimension::TP>::val,
                   typename Selector<typename A::conv_amount, conv_amount,
                                     typename dimension::A>::val,
                   typename Selector<typename A::conv_light, conv_light,
                                     typename dimension::LM>::val>;
  };
  template <concepts::Definition A>
  using Multiply = Multiply_<A>::val;

  template <concepts::Definition A>
  struct Divide_ {
   private:
    using dimension = ExponentsAdd<typename A::dim, dim>;

   public:
    using val =
        Definition<ExponentsSubtract<typename A::dim, dim>,
                   typename Selector<typename A::conv_len, conv_len,
                                     typename dimension::L>::val,
                   typename Selector<typename A::conv_mass, conv_mass,
                                     typename dimension::M>::val,
                   typename Selector<typename A::conv_time, conv_time,
                                     typename dimension::T>::val,
                   typename Selector<typename A::conv_elec, conv_elec,
                                     typename dimension::C>::val,
                   typename Selector<typename A::conv_temper, conv_temper,
                                     typename dimension::TP>::val,
                   typename Selector<typename A::conv_amount, conv_amount,
                                     typename dimension::A>::val,
                   typename Selector<typename A::conv_light, conv_light,
                                     typename dimension::LM>::val>;
  };
  template <concepts::Definition A>
  using Divide = Divide_<A>::val;

  using InverseDef =
      Definition<ExponentsFlip<dim>, conv_len, conv_mass, conv_time, conv_elec,
                 conv_temper, conv_amount, conv_light>;

 private:
  template <concepts::Ratio R1, concepts::Ratio R2>
  struct Convert {
    constexpr static auto value =
        gcem::pow(static_cast<double>(R1::num) / R1::den,
                  static_cast<double>(R2::num) / R2::den);
  };

  template <concepts::Ratio R1, concepts::Ratio R2>
  using InvConvert = Convert<std::ratio<R1::den, R1::num>, R2>;
};

namespace literals {
// NOLINTBEGIN(readability-identifier-length)

constexpr auto Gy = Definition<Exponents<2, 0, -2, 0, 0, 0, 0>>();
constexpr auto Bq = Definition<Exponents<0, 0, -1, 0, 0, 0, 0>>();
constexpr auto mol = Definition<Exponents<0, 0, 0, 0, 0, 1, 0>>();
constexpr auto mol2 = Definition<Exponents<0, 0, 0, 0, 0, 2, 0>>();
constexpr auto m2 = Definition<Exponents<2, 0, 0, 0, 0, 0, 0>>();
constexpr auto F = Definition<Exponents<-2, -1, 4, 2, 0, 0, 0>>();
constexpr auto kat = Definition<Exponents<0, 0, -1, 0, 0, 1, 0>>();
constexpr auto S = Definition<Exponents<-2, -1, 3, 2, 0, 0, 0>>();
constexpr auto kgperm3 = Definition<Exponents<-3, 1, 0, 0, 0, 0, 0>>();
constexpr auto kgmpers = Definition<Exponents<1, 1, -1, 0, 0, 0, 0>>();
constexpr auto Sv = Definition<Exponents<2, 0, -2, 0, 0, 0, 0>>();
constexpr auto C = Definition<Exponents<0, 0, 1, 1, 0, 0, 0>>();
constexpr auto A = Definition<Exponents<0, 0, 0, 1, 0, 0, 0>>();
constexpr auto A2 = Definition<Exponents<0, 0, 0, 2, 0, 0, 0>>();
constexpr auto J = Definition<Exponents<2, 1, -2, 0, 0, 0, 0>>();
constexpr auto N = Definition<Exponents<1, 1, -2, 0, 0, 0, 0>>();
constexpr auto Hz = Definition<Exponents<0, 0, -1, 0, 0, 0, 0>>();
constexpr auto lx = Definition<Exponents<-2, 0, 0, 0, 0, 0, 1>>();
constexpr auto H = Definition<Exponents<1, 1, -2, 0, 0, 0, 0>>();
constexpr auto m = Definition<Exponents<1, 0, 0, 0, 0, 0, 0>>();
constexpr auto inv_m = Definition<Exponents<-1, 0, 0, 0, 0, 0, 0>>();
constexpr auto cd = Definition<Exponents<0, 0, 0, 0, 0, 0, 1>>();
constexpr auto cd2 = Definition<Exponents<0, 0, 0, 0, 0, 0, 2>>();
constexpr auto lm = Definition<Exponents<0, 0, 0, 0, 0, 0, 1>>();
constexpr auto Wb = Definition<Exponents<1, 1, -2, 1, 0, 0, 0>>();
constexpr auto T = Definition<Exponents<-1, 1, -2, 1, 0, 0, 0>>();
constexpr auto kg = Definition<Exponents<0, 1, 0, 0, 0, 0, 0>>();
constexpr auto V = Definition<Exponents<2, 1, -3, -1, 0, 0, 0>>();
constexpr auto W = Definition<Exponents<2, 1, -3, 0, 0, 0, 0>>();
constexpr auto Pa = Definition<Exponents<-1, 1, -2, 0, 0, 0, 0>>();
constexpr auto Pa2 = Definition<Exponents<-2, 2, -4, 0, 0, 0, 0>>();
constexpr auto Pa3 = Definition<Exponents<-3, 3, -6, 0, 0, 0, 0>>();
constexpr auto Pa4 = Definition<Exponents<-4, 4, -8, 0, 0, 0, 0>>();
constexpr auto ohm = Definition<Exponents<2, 1, -3, -2, 0, 0, 0>>();
constexpr auto K = Definition<Exponents<0, 0, 0, 0, 1, 0, 0>>();
constexpr auto K2 = Definition<Exponents<0, 0, 0, 0, 2, 0, 0>>();
constexpr auto K3 = Definition<Exponents<0, 0, 0, 0, 3, 0, 0>>();
constexpr auto K4 = Definition<Exponents<0, 0, 0, 0, 4, 0, 0>>();
constexpr auto s = Definition<Exponents<0, 0, 1, 0, 0, 0, 0>>();
constexpr auto m3 = Definition<Exponents<3, 0, 0, 0, 0, 0, 0>>();

// NOLINTEND(readability-identifier-length)

// constexpr auto mps = m / s;
// constexpr auto mps2 = m / s / s;

}  // namespace literals

}  // namespace csm_units