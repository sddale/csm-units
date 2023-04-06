#pragma once

#include <csm_units/concepts.hpp>

#include "unitbase.hpp"
#include "unitcast.hpp"
#include "util.hpp"

namespace csm_units {

template <UnitBaseType Base, StringLiteral Unit_Name, Arithmetic Data>
class Unit {
 public:
  using SI = Base;
  constexpr explicit Unit(Data value = 0.0) noexcept : data(value) {}

  constexpr Unit(SI new_base) noexcept : data(UnitCast<Unit>(new_base).data) {}

  template <StringLiteral UN, Arithmetic D>
  constexpr Unit(Unit<SI, UN, D> new_unit) noexcept
      : data(UnitCast<Unit>(UnitCast<SI>(new_unit)).data) {}

  Data data;
};

// Base Dimensions
using Length = UnitBase<Exponents<1, 0, 0, 0, 0, 0, 0>, double>;
using Mass = UnitBase<Exponents<0, 1, 0, 0, 0, 0, 0>, double>;
using Time = UnitBase<Exponents<0, 0, 1, 0, 0, 0, 0>, double>;
using ElectrCurrent = UnitBase<Exponents<0, 0, 0, 1, 0, 0, 0>, double>;
using Temperature = UnitBase<Exponents<0, 0, 0, 0, 1, 0, 0>, double>;
using Amount = UnitBase<Exponents<0, 0, 0, 0, 0, 1, 0>, double>;
using Luminosity = UnitBase<Exponents<0, 0, 0, 0, 0, 0, 1>, double>;

// Derived Dimensions
using Pressure = UnitBase<Exponents<-1, 1, -2, 0, 0, 0, 0>, double>;
using Force = UnitBase<Exponents<1, 1, -2, 0, 0, 0, 0>, double>;
using Area = UnitBase<Exponents<2, 0, 0, 0, 0, 0, 0>, double>;
using Accel = UnitBase<Exponents<1, 0, -2, 0, 0, 0, 0>, double>;

// SI Units
using Meter = Unit<Length, "m", double>;
using SqMeter = Unit<Length, "m2", double>;
using Gram = Unit<Mass, "g", double>;
using Kilogram = Unit<Mass, "kg", double>;
using Second = Unit<Time, "s", double>;
using Ampere = Unit<ElectrCurrent, "A", double>;
using Kelvin = Unit<Temperature, "K", double>;
using Mole = Unit<Amount, "mol", double>;
using Candela = Unit<Luminosity, "cd", double>;
using Pascal = Unit<Pressure, "Pa", double>;
using Newton = Unit<Force, "N", double>;

// Other Units
using Psi = Unit<Pressure, "psi", double>;
using Bar = Unit<Pressure, "bar", double>;
using Atm = Unit<Pressure, "Atm", double>;
using MPerS2 = Unit<Accel, "m/s2", double>;

// Unit Cast for Base g to Unit kg
// Conversion Equation: 1000 g = 1 kg
template <>
constexpr auto UnitCast(Mass input) -> Kilogram {
  return Kilogram(input.data);
}

// Unit Cast for Unit kg to Base g
// Conversion Equation: 1000 g = 1 kg
template <>
constexpr auto UnitCast(Kilogram input) -> Mass {
  return Mass(input.data);
}

template <>
constexpr auto UnitCast(Mass input) -> Gram {
  return Gram(input.data * 1000);
}

// Unit Cast for Unit kg to Base g
// Conversion Equation: 1000 g = 1 kg
template <>
constexpr auto UnitCast(Gram input) -> Mass {
  return Mass(input.data / 1000);
}

template <>
constexpr auto UnitCast(Time input) -> Second {
  return Second(input.data);
}

// Unit Cast for Unit kg to Base g
// Conversion Equation: 1000 g = 1 kg
template <>
constexpr auto UnitCast(Second input) -> Time {
  return Time(input.data);
}

template <>
constexpr auto UnitCast(Length input) -> Meter {
  return Meter(input.data);
}

// Unit Cast for Unit kg to Base g
// Conversion Equation: 1000 g = 1 kg
template <>
constexpr auto UnitCast(Meter input) -> Length {
  return Length(input.data);
}

// Unit Cast for Base Pascals to Unit Pascals
// Conversion Equation: Pascals = Pascals
template <>
constexpr auto UnitCast(Pressure input) -> Pascal {
  return Pascal(input.data);
}

// Unit Cast for Unit Pascals to Base Pascals
// Conversion Equation: Pascals = Pascals
template <>
constexpr auto UnitCast(Pascal input) -> Pressure {
  return Pressure(input.data);
}

// Unit Cast for Base Pascals to Unit psi
// Conversion Equation: 1 psi = 6894.76 pascals
template <>
constexpr auto UnitCast(Pressure input) -> Psi {
  return Psi(input.data / 6894.76);
}

// Unit Cast for Unit psi to Base Pascals
// Conversion Equation: 1 psi = 6894.76 pascals
template <>
constexpr auto UnitCast(Psi input) -> Pressure {
  return Pressure(input.data * 6894.76);
}

// Unit Cast for Base Newton
template <>
constexpr auto UnitCast(Force input) -> Newton {
  return Newton(input.data);
}
template <>
constexpr auto UnitCast(Newton input) -> Force {
  return Force(input.data);
}

// Unit Cast for Base m2
template <>
constexpr auto UnitCast(Area input) -> SqMeter {
  return SqMeter(input.data);
}

// Unit Cast for Unit Newton
template <>
constexpr auto UnitCast(SqMeter input) -> Area {
  return Area(input.data);
}

// Unit Cast for Base mps2
template <>
constexpr auto UnitCast(Accel input) -> MPerS2 {
  return MPerS2(input.data);
}

// Unit Cast for Unit Newton
template <>
constexpr auto UnitCast(MPerS2 input) -> Accel {
  return Accel(input.data);
}

// String Literal Operators
// length - meter
constexpr auto operator""_m(long double data) noexcept {
  return Unit<UnitBase<Exponents<1, 0, 0, 0, 0, 0, 0>, double>, "m", double>(
      static_cast<double>(data));
}

// mass - kilogram
constexpr auto operator""_kg(long double data) noexcept {
  return Unit<UnitBase<Exponents<0, 1, 0, 0, 0, 0, 0>, double>, "kg", double>(
      static_cast<double>(data));
}

// time - second
constexpr auto operator""_s(long double data) noexcept {
  return Unit<UnitBase<Exponents<0, 0, 1, 0, 0, 0, 0>, double>, "s", double>(
      static_cast<double>(data));
}

// current - ampere
constexpr auto operator""_A(long double data) noexcept {
  return Unit<UnitBase<Exponents<0, 0, 0, 1, 0, 0, 0>, double>, "A", double>(
      static_cast<double>(data));
}

// temperature - kelvin
constexpr auto operator""_K(long double data) noexcept {
  return Unit<UnitBase<Exponents<0, 0, 0, 0, 1, 0, 0>, double>, "K", double>(
      static_cast<double>(data));
}

// amount - mole
constexpr auto operator""_mol(long double data) noexcept {
  return Unit<UnitBase<Exponents<0, 0, 0, 0, 0, 1, 0>, double>, "mol", double>(
      static_cast<double>(data));
}

// luminosity - candela
constexpr auto operator""_cd(long double data) noexcept {
  return Unit<UnitBase<Exponents<0, 0, 0, 0, 0, 0, 1>, double>, "cd", double>(
      static_cast<double>(data));
}

// template <class DST, class SRC>
// auto Cast(SRC /*input*/) -> DST;

// template <>
// auto Cast(Foo2 input) -> Foo1;

// class Foo2 {
//  public:
//   constexpr explicit Foo2(double value = 0.0) noexcept : data(value) {}

//   // constexpr Foo2(Foo1 thing) noexcept { data = Cast<Foo2>(thing).data; }

//   double data;

//   friend constexpr auto operator+(Foo2 lhs, Foo2 rhs) {
//     return Foo2(Cast<Foo1>(lhs) + rhs);
//   }
// };

// class Foo1 {
//  public:
//   constexpr explicit Foo1(double value = 0.0) noexcept : data(value) {}
//   constexpr Foo1(Foo2 thing) noexcept { data = (Cast<Foo1>(thing).data); }

//   double data;

//   friend constexpr auto operator+(Foo1 lhs, Foo1 rhs) {
//     return Foo1(lhs.data + rhs.data);
//   }
// };

// template <>
// auto Cast(Foo2 input) -> Foo1 {
//   return Foo1(input);
// }

}  // namespace csm_units