/**  \file literals.hpp
 *   \brief This file defines a more verbose version of user defined literals.
 *
 * Allows for the combination of user defined literal with different binary
 * arithmetic operators to create a unit from scratch. Then defining a decimal
 * number with that unit.
 */

#pragma once

#include "../exponents.hpp"
#include "../unit.hpp"

namespace csm_units::literals {

template <ExpType E>
class Literal {
 public:
  constexpr Literal() = default;

  template <ExpType E2>
  constexpr auto operator*(Literal<E2> /*rhs*/) const {
    return Literal<ExponentsAdd<E, E2>>();
  }

  template <ExpType E2>
  constexpr auto operator/(Literal<E2> /*rhs*/) const {
    return Literal<ExponentsSubtract<E, E2>>();
  }

  // Derived factory of sorts
  friend constexpr auto operator<<=(double lhs, Literal /*rhs*/) {
    return UnitBase<E, double>(lhs);
  }
};

constexpr auto Gy = Literal<Exponents<2, 0, -2, 0, 0, 0, 0>>();
constexpr auto Bq = Literal<Exponents<0, 0, -1, 0, 0, 0, 0>>();
constexpr auto mol = Literal<Exponents<0, 0, 0, 0, 0, 1, 0>>();
constexpr auto mol2 = Literal<Exponents<0, 0, 0, 0, 0, 2, 0>>();
constexpr auto m2 = Literal<Exponents<2, 0, 0, 0, 0, 0, 0>>();
constexpr auto F = Literal<Exponents<-2, -1, 4, 2, 0, 0, 0>>();
constexpr auto kat = Literal<Exponents<0, 0, -1, 0, 0, 1, 0>>();
constexpr auto S = Literal<Exponents<-2, -1, 3, 2, 0, 0, 0>>();
constexpr auto kgperm3 = Literal<Exponents<-3, 1, 0, 0, 0, 0, 0>>();
constexpr auto Sv = Literal<Exponents<2, 0, -2, 0, 0, 0, 0>>();
constexpr auto C = Literal<Exponents<0, 0, 1, 1, 0, 0, 0>>();
constexpr auto A = Literal<Exponents<0, 0, 0, 1, 0, 0, 0>>();
constexpr auto A2 = Literal<Exponents<0, 0, 0, 2, 0, 0, 0>>();
constexpr auto J = Literal<Exponents<2, 1, -2, 0, 0, 0, 0>>();
constexpr auto N = Literal<Exponents<1, 1, -2, 0, 0, 0, 0>>();
constexpr auto Hz = Literal<Exponents<0, 0, -1, 0, 0, 0, 0>>();
constexpr auto lx = Literal<Exponents<-2, 0, 0, 0, 0, 0, 1>>();
constexpr auto H = Literal<Exponents<1, 1, -2, 0, 0, 0, 0>>();
constexpr auto m = Literal<Exponents<1, 0, 0, 0, 0, 0, 0>>();
constexpr auto inv_m = Literal<Exponents<-1, 0, 0, 0, 0, 0, 0>>();
constexpr auto cd = Literal<Exponents<0, 0, 0, 0, 0, 0, 1>>();
constexpr auto cd2 = Literal<Exponents<0, 0, 0, 0, 0, 0, 2>>();
constexpr auto lm = Literal<Exponents<0, 0, 0, 0, 0, 0, 1>>();
constexpr auto Wb = Literal<Exponents<1, 1, -2, 1, 0, 0, 0>>();
constexpr auto T = Literal<Exponents<-1, 1, -2, 1, 0, 0, 0>>();
constexpr auto g = Literal<Exponents<0, 1, 0, 0, 0, 0, 0>>();
constexpr auto V = Literal<Exponents<2, 1, -3, -1, 0, 0, 0>>();
constexpr auto W = Literal<Exponents<2, 1, -3, 0, 0, 0, 0>>();
constexpr auto Pa = Literal<Exponents<-1, 1, -2, 0, 0, 0, 0>>();
constexpr auto ohm = Literal<Exponents<2, 1, -3, -2, 0, 0, 0>>();
constexpr auto K = Literal<Exponents<0, 0, 0, 0, 1, 0, 0>>();
constexpr auto s = Literal<Exponents<0, 0, 1, 0, 0, 0, 0>>();
constexpr auto m3 = Literal<Exponents<3, 0, 0, 0, 0, 0, 0>>();

constexpr auto mps = m / s;
constexpr auto mps2 = m / s / s;

template <Literal L>
constexpr auto FromSymbols(double in) {
  return in <<= L;
}

}  // namespace csm_units::literals