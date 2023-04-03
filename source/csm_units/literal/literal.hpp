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

constexpr auto m = Literal<Exponents<1, 0, 0, 0, 0, 0, 0>>();
constexpr auto s = Literal<Exponents<0, 0, 1, 0, 0, 0, 0>>();
constexpr auto mps = m / s;

template <Literal L>
constexpr auto FromSymbols(double in) {
  return in <<= L;
}

// auto mps = 1.0 <<= (m / s);
// auto g0 = 0.0328084 <<= (ft/s/s);
}  // namespace csm_units::literals