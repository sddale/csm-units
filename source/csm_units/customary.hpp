#pragma once

#include "unit.hpp"

namespace csm_units {

class Foo2;

template <class convertTo>
constexpr auto Cast(Foo2 convertFrom) -> convertTo;

class Foo2 {
 public:
  constexpr explicit Foo2(double value = 0.0) noexcept : data(value){};

  double data;
};

class Foo1 {
 public:
  constexpr explicit Foo1(double value = 0.0) noexcept : data(value){};
  constexpr Foo1(Foo2 thing) noexcept { Cast<Foo1>(thing); };

  double data;

  friend constexpr auto operator+(Foo1 lhs, Foo1 rhs) {
    return Foo1(lhs.data + rhs.data);
  }
};

template <class convertTo>
constexpr auto Cast(Foo2 convertFrom) -> convertTo {
  return (convertTo(convertFrom.data));
}

}  // namespace csm_units