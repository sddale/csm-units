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
  const double K_CONSTANT = 273.15;
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
using CentiMeter = Unit<Length, "cm", double>;
using MilliMeter = Unit<Length, "mm", double>;
using KiloMeter = Unit<Length, "km", double>;

using Gram = Unit<Mass, "g", double>;
using Kilogram = Unit<Mass, "kg", double>;

using Second = Unit<Time, "s", double>;

using Ampere = Unit<ElectrCurrent, "A", double>;
using Coulomb = Unit<ElectrCurrent, "C", double>;
using Milliampere = Unit<ElectrCurrent, "mA", double>;

using Kelvin = Unit<Temperature, "K", double>;
using Fahrenheit = Unit<Temperature, "F", double>;
using Celsius = Unit<Temperature, "C", double>;

using Mole = Unit<Amount, "mol", double>;
using Kilomole = Unit<Amount, "kmol", double>;

using Candela = Unit<Luminosity, "cd", double>;
using Pascal = Unit<Pressure, "Pa", double>;
using Newton = Unit<Force, "N", double>;

// Other Units
using Psi = Unit<Pressure, "psi", double>;
using Bar = Unit<Pressure, "bar", double>;
using Atm = Unit<Pressure, "Atm", double>;
using MPerS2 = Unit<Accel, "m/s2", double>;
using Inch = Unit<Length, "in", double>;
using Feet = Unit<Length, "ft", double>;
using Yard = Unit<Length, "yd", double>;
using Miles = Unit<Length, "miles", double>;

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

// Unit Cast for Base g to Unit g
template <>
constexpr auto UnitCast(Mass input) -> Gram {
  return Gram(input.data * 1000);
}

// Unit Cast for Unit g to Base g
template <>
constexpr auto UnitCast(Gram input) -> Mass {
  return Mass(input.data / 1000);
}

// Unit Cast for Unit s to Base s
template <>
constexpr auto UnitCast(Second input) -> Time {
  return Time(input.data);
}

// Unit Cast for Base s to Unit s
template <>
constexpr auto UnitCast(Time input) -> Second {
  return Second(input.data);
}

// Unit cast for Base m to Unit m
template <>
constexpr auto UnitCast(Length input) -> Meter {
  return Meter(input.data);
}

// Unit Cast for Unit m to Base m
template <>
constexpr auto UnitCast(Meter input) -> Length {
  return Length(input.data);
}

// Unit cast for Base m to Unit cm
// Conversion Equation: 1 m = 100 cm
template <>
constexpr auto UnitCast(Length input) -> CentiMeter {
  return CentiMeter(input.data * 100);
}

// Unit Cast for Unit cm to Base m
// Conversion Equation: 1 m = 100 cm
template <>
constexpr auto UnitCast(CentiMeter input) -> Length {
  return Length(input.data / 100);
}

// Unit cast for Base m to Unit mm
// Conversion Equation: 1 m = 1000 mm
template <>
constexpr auto UnitCast(Length input) -> MilliMeter {
  return MilliMeter(input.data * 1000);
}

// Unit Cast for Unit mm to Base m
// Conversion Equation: 1 m = 1000 mm
template <>
constexpr auto UnitCast(MilliMeter input) -> Length {
  return Length(input.data / 1000);
}

// Unit cast for Base m to Unit km
// Conversion Equation: 1000 m = 1 km
template <>
constexpr auto UnitCast(Length input) -> KiloMeter {
  return KiloMeter(input.data / 1000);
}

// Unit Cast for Unit km to Base m
// Conversion Equation: 1000 m = 1 km
template <>
constexpr auto UnitCast(KiloMeter input) -> Length {
  return Length(input.data * 1000);
}

// Unit Cast for Base m to Unit in
// Conversion Equation: 1 m = 39.3701 in
template <>
constexpr auto UnitCast(Length input) -> Inch {
  return Inch(input.data * 39.3701);
}

// Unit Cast for Unit in to Base m
// Conversion Equation: 1 m = 39.3701 in
template <>
constexpr auto UnitCast(Inch input) -> Length {
  return Length(input.data / 39.3701);
}

// Unit Cast for Base m to Unit ft
// Conversion Equation: 1 m = 3.28084 ft
template <>
constexpr auto UnitCast(Length input) -> Feet {
  return Feet(input.data * 3.28084);
}

// Unit Cast for Unit ft to Base m
// Conversion Equation: 1 m = 3.28084 ft
template <>
constexpr auto UnitCast(Feet input) -> Length {
  return Length(input.data / 3.28084);
}

// Unit Cast for Base m to Unit yard
// Conversion Equation: 1 m = 1.09361 yard
template <>
constexpr auto UnitCast(Length input) -> Yard {
  return Yard(input.data * 1.09361);
}

// Unit Cast for Unit yard to Base m
// Conversion Equation: 1 m = 1.09361 yard
template <>
constexpr auto UnitCast(Yard input) -> Length {
  return Length(input.data / 1.09361);
}

// Unit Cast for Base m to Unit miles
// Conversion Equation: 1609.34 m = 1 miles
template <>
constexpr auto UnitCast(Length input) -> Miles {
  return Miles(input.data / 1609.34);
}

// Unit Cast for Unit miles to Base m
// Conversion Equation: 1609.34 m = 1 miles
template <>
constexpr auto UnitCast(Miles input) -> Length {
  return Length(input.data * 1609.34);
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

// Unit Cast for Base Pascals to Unit Bar
// Conversion Equation: 1 bar = 100,000 pascals
template <>
constexpr auto UnitCast(Pressure input) -> Bar {
  return Bar(input.data / 100000);
}

// Unit Cast for Unit Bar to Base Pascals
// Conversion Equation: 1 bar = 100,000 pascals
template <>
constexpr auto UnitCast(Bar input) -> Pressure {
  return Pressure(input.data * 100000);
}

// Unit Cast for Base Pascals to Unit Atm
// Conversion Equation: 1 atm = 101,325 pascals
template <>
constexpr auto UnitCast(Pressure input) -> Atm {
  return Atm(input.data / 101325);
}

// Unit Cast for Unit Bar to Base Pascals
// Conversion Equation: 1 bar = 101,325 pascals
template <>
constexpr auto UnitCast(Atm input) -> Pressure {
  return Pressure(input.data * 101325);
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

// Unit Cast for Unit Ampere
template <>
constexpr auto UnitCast(ElectrCurrent input) -> Ampere {
  return Ampere(input.data);
}

// Unit Cast for Unit Ampere
template <>
constexpr auto UnitCast(Ampere input) -> ElectrCurrent {
  return ElectrCurrent(input.data);
}

// Unit Cast for Unit Kelvin
template <>
constexpr auto UnitCast(Temperature input) -> Kelvin {
  return Temperature(input.data);
}

// Unit Cast for Unit Kelvin
template <>
constexpr auto UnitCast(Kelvin input) -> Temperature {
  return Temperature(input.data);
}

// Unit Cast for Base K to Unit F
template <>
constexpr auto UnitCast(Temperature input) -> Fahrenheit {
  return Temperature((input.data - 273.15) * 1.8 + 32);
}

// Unit Cast for Unit F to Base K
template <>
constexpr auto UnitCast(Fahrenheit input) -> Temperature {
  return Temperature((input.data - 32) * 5 / 9 + 273.15);
}

// Base K -> Unit C
template <>
constexpr auto UnitCast(Temperature input) -> Celsius {
  return Temperature(input.data - 273.15);
}

// Unit C -> Base K
template <>
constexpr auto UnitCast(Celsius input) -> Temperature {
  return Temperature(input.data + 273.15);
}

// Unit Cast for Unit Mole
template <>
constexpr auto UnitCast(Amount input) -> Mole {
  return Mole(input.data);
}

// Unit Cast for Unit Mole
template <>
constexpr auto UnitCast(Mole input) -> Amount {
  return Amount(input.data);
}

// Unit Cast for Unit Candela
template <>
constexpr auto UnitCast(Luminosity input) -> Candela {
  return Candela(input.data);
}

// Unit Cast for Unit Ampere
template <>
constexpr auto UnitCast(Candela input) -> Luminosity {
  return Luminosity(input.data);
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