/**  \file definition.hpp
 *   \brief This file defines a more verbose version of user defined definition.
 *
 * Allows for the combination of user defined literal with different binary
 * arithmetic operators to create a unit from scratch. Then defining a decimal
 * number with that unit.
 */

#pragma once

#include <csm_units/concepts.hpp>
#include <gcem.hpp>
#include <ratio>

#include "dimension.hpp"

#ifndef CSMUNITS_VALUE_TYPE
#define CSMUNITS_VALUE_TYPE double
#endif

namespace csm_units {

template <IsDimension D, IsRatio ConvLen = std::ratio<1>,
          IsRatio ConvMass = std::ratio<1>, IsRatio ConvTime = std::ratio<1>,
          IsRatio ConvElec = std::ratio<1>, IsRatio ConvTemper = std::ratio<1>,
          IsRatio ConvAmount = std::ratio<1>, IsRatio ConvLight = std::ratio<1>>
class Definition {
 public:
  using dim = D;
  using conv_len = ConvLen;
  using conv_mass = ConvMass;
  using conv_time = ConvTime;
  using conv_elec = ConvElec;
  using conv_temper = ConvTemper;
  using conv_amount = ConvAmount;
  using conv_light = ConvLight;

  [[nodiscard]] consteval static auto Get() noexcept {
    return Convert<conv_len, typename dim::L>().value *
           Convert<conv_mass, typename dim::M>().value *
           Convert<conv_time, typename dim::T>().value *
           Convert<conv_elec, typename dim::C>().value *
           Convert<conv_temper, typename dim::TP>().value *
           Convert<conv_amount, typename dim::A>().value *
           Convert<conv_light, typename dim::LM>().value;
  }
  [[nodiscard]] consteval static auto ToSI() noexcept {
    return InvConvert<conv_len, typename dim::L>().value *
           InvConvert<conv_mass, typename dim::M>().value *
           InvConvert<conv_time, typename dim::T>().value *
           InvConvert<conv_elec, typename dim::C>().value *
           InvConvert<conv_temper, typename dim::TP>().value *
           InvConvert<conv_amount, typename dim::A>().value *
           InvConvert<conv_light, typename dim::LM>().value;
  }

  template <IsRatio RL, IsRatio RR, IsRatio Pow>
  struct Selector {
    using val = RL;
  };

  template <IsRatio RL, IsRatio RR>
  struct Selector<RL, RR, std::ratio<0>> {
    using val = std::ratio<1, 1>;
  };

  template <IsRatio RL, IsRatio Pow>
    requires(!std::same_as<Pow, std::ratio<0>>)
  struct Selector<RL, std::ratio<1>, Pow> {
    using val = RL;
  };

  template <IsRatio RR, IsRatio Pow>
    requires(!std::same_as<Pow, std::ratio<0>>)
  struct Selector<std::ratio<1>, RR, Pow> {
    using val = RR;
  };

  template <IsRatio Pow>
    requires(!std::same_as<Pow, std::ratio<0>>)
  struct Selector<std::ratio<1>, std::ratio<1>, Pow> {
    using val = std::ratio<1>;
  };

  template <IsDefinition A>
  struct Multiply_ {
   private:
    using dimension = DimensionAdd<typename A::dim, dim>;

   public:
    using val =
        Definition<DimensionAdd<typename A::dim, dim>,
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
  template <IsDefinition A>
  using Multiply = Multiply_<A>::val;

  template <IsDefinition A>
  struct Divide_ {
   private:
    using dimension = DimensionAdd<typename A::dim, dim>;

   public:
    using val =
        Definition<DimensionSubtract<typename A::dim, dim>,
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
  template <IsDefinition A>
  using Divide = Divide_<A>::val;

  using InverseDef =
      Definition<DimensionFlip<dim>, conv_len, conv_mass, conv_time,
                 conv_temper, conv_elec, conv_amount, conv_light>;

 private:
  template <IsRatio R1, IsRatio R2>
  struct Convert {
    constexpr static auto value =
        gcem::pow(static_cast<CSMUNITS_VALUE_TYPE>(R1::num) / R1::den,
                  static_cast<CSMUNITS_VALUE_TYPE>(R2::num) / R2::den);
  };

  template <IsRatio R1, IsRatio R2>
  using InvConvert = Convert<std::ratio<R1::den, R1::num>, R2>;
};

namespace literals {
// NOLINTBEGIN(readability-identifier-length)

// constexpr auto Gy = Definition<Dimension<2, 0, -2, 0, 0, 0, 0>>();
// constexpr auto Bq = Definition<Dimension<0, 0, -1, 0, 0, 0, 0>>();
// constexpr auto mol = Definition<Dimension<0, 0, 0, 0, 0, 1, 0>>();
// constexpr auto mol2 = Definition<Dimension<0, 0, 0, 0, 0, 2, 0>>();
// constexpr auto m2 = Definition<Dimension<2, 0, 0, 0, 0, 0, 0>>();
// constexpr auto F = Definition<Dimension<-2, -1, 4, 2, 0, 0, 0>>();
// constexpr auto kat = Definition<Dimension<0, 0, -1, 0, 0, 1, 0>>();
// constexpr auto S = Definition<Dimension<-2, -1, 3, 2, 0, 0, 0>>();
// constexpr auto kgperm3 = Definition<Dimension<-3, 1, 0, 0, 0, 0, 0>>();
// constexpr auto kgmpers = Definition<Dimension<1, 1, -1, 0, 0, 0, 0>>();
// constexpr auto Sv = Definition<Dimension<2, 0, -2, 0, 0, 0, 0>>();
// constexpr auto C = Definition<Dimension<0, 0, 1, 1, 0, 0, 0>>();
// constexpr auto A = Definition<Dimension<0, 0, 0, 1, 0, 0, 0>>();
// constexpr auto A2 = Definition<Dimension<0, 0, 0, 2, 0, 0, 0>>();
// constexpr auto J = Definition<Dimension<2, 1, -2, 0, 0, 0, 0>>();
// constexpr auto N = Definition<Dimension<1, 1, -2, 0, 0, 0, 0>>();
// constexpr auto Hz = Definition<Dimension<0, 0, -1, 0, 0, 0, 0>>();
// constexpr auto lx = Definition<Dimension<-2, 0, 0, 0, 0, 0, 1>>();
// constexpr auto H = Definition<Dimension<1, 1, -2, 0, 0, 0, 0>>();
// constexpr auto m = Definition<Dimension<1, 0, 0, 0, 0, 0, 0>>();
// constexpr auto inv_m = Definition<Dimension<-1, 0, 0, 0, 0, 0, 0>>();
// constexpr auto cd = Definition<Dimension<0, 0, 0, 0, 0, 0, 1>>();
// constexpr auto cd2 = Definition<Dimension<0, 0, 0, 0, 0, 0, 2>>();
// constexpr auto lm = Definition<Dimension<0, 0, 0, 0, 0, 0, 1>>();
// constexpr auto Wb = Definition<Dimension<1, 1, -2, 1, 0, 0, 0>>();
// constexpr auto T = Definition<Dimension<-1, 1, -2, 1, 0, 0, 0>>();
// constexpr auto kg = Definition<Dimension<0, 1, 0, 0, 0, 0, 0>>();
// constexpr auto V = Definition<Dimension<2, 1, -3, -1, 0, 0, 0>>();
// constexpr auto W = Definition<Dimension<2, 1, -3, 0, 0, 0, 0>>();
// constexpr auto Pa = Definition<Dimension<-1, 1, -2, 0, 0, 0, 0>>();
// constexpr auto Pa2 = Definition<Dimension<-2, 2, -4, 0, 0, 0, 0>>();
// constexpr auto Pa3 = Definition<Dimension<-3, 3, -6, 0, 0, 0, 0>>();
// constexpr auto Pa4 = Definition<Dimension<-4, 4, -8, 0, 0, 0, 0>>();
// constexpr auto ohm = Definition<Dimension<2, 1, -3, -2, 0, 0, 0>>();
// constexpr auto K = Definition<Dimension<0, 0, 0, 0, 1, 0, 0>>();
// constexpr auto K2 = Definition<Dimension<0, 0, 0, 0, 2, 0, 0>>();
// constexpr auto K3 = Definition<Dimension<0, 0, 0, 0, 3, 0, 0>>();
// constexpr auto K4 = Definition<Dimension<0, 0, 0, 0, 4, 0, 0>>();
// constexpr auto m3 = Definition<Dimension<3, 0, 0, 0, 0, 0, 0>>();

// NOLINTEND(readability-identifier-length)

// constexpr auto mps = m / s;
// constexpr auto mps2 = m / s / s;

}  // namespace literals

}  // namespace csm_units