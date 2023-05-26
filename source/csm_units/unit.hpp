/**  \file units.hpp
 *   \brief This file defines a derived unit of any dimension and any system.
 *
 * The system refers to what standard the data is in. For example, the
 * International System of Units (SI) is a system in this sense. This file
 * contains many using statements for common units. As well as Unit Casting so
 * that a any defined unit is able to convert to a base unit in SI and back to
 * derived unit when needed. To define a new unit all that needs to be done is
 * the creation of two UnitCast functions that cast from that unit to the base
 * and from the base to that unit.
 */

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

  constexpr explicit(false) Unit(SI new_base) noexcept
      : data(UnitCast<Unit>(std::forward<SI>(new_base)).data) {}

  template <StringLiteral UN, Arithmetic D>
  constexpr explicit(false) Unit(Unit<SI, UN, D> new_unit) noexcept
      : data(UnitCast<Unit>(
                 UnitCast<SI>(std::forward<decltype(new_unit)>(new_unit)))
                 .data) {}

  Data data;

  constexpr auto operator+=(const Base &rhs) noexcept -> auto & {
    auto temp = UnitCast<Base>(std::forward<Unit>(*this));
    temp = temp + rhs;
    data = UnitCast<Unit>(std::forward<Base>(temp)).data;
    return *this;
  }

  constexpr auto operator-=(const Base &rhs) noexcept -> auto & {
    auto temp = UnitCast<Base>(std::forward<Unit>(*this));
    temp = temp - rhs;
    data = UnitCast<Unit>(std::forward<Base>(temp)).data;
    return *this;
  }
};

// Base Dimensions
// using Length = UnitBase<Exponents<1, 0, 0, 0, 0, 0, 0>, double>;
// using Mass = UnitBase<Exponents<0, 1, 0, 0, 0, 0, 0>, double>;
// using Time = UnitBase<Exponents<0, 0, 1, 0, 0, 0, 0>, double>;
using ElectrCurrent = UnitBase<Exponents<0, 0, 0, 1, 0, 0, 0>, double>;
using Temperature = UnitBase<Exponents<0, 0, 0, 0, 1, 0, 0>, double>;
using Amount = UnitBase<Exponents<0, 0, 0, 0, 0, 1, 0>, double>;
using Luminosity = UnitBase<Exponents<0, 0, 0, 0, 0, 0, 1>, double>;

// Derived Dimensions
// using InvLength = UnitBase<Exponents<-1, 0, 0, 0, 0, 0, 0>, double>;
using Pressure = UnitBase<Exponents<-1, 1, -2, 0, 0, 0, 0>, double>;
using Force = UnitBase<Exponents<1, 1, -2, 0, 0, 0, 0>, double>;
using Area = UnitBase<Exponents<2, 0, 0, 0, 0, 0, 0>, double>;
using Volume = UnitBase<Exponents<3, 0, 0, 0, 0, 0, 0>, double>;
using Accel = UnitBase<Exponents<1, 0, -2, 0, 0, 0, 0>, double>;
using Density = UnitBase<Exponents<-3, 1, 0, 0, 0, 0, 0>, double>;
using Energy = UnitBase<Exponents<2, 1, -2, 0, 0, 0, 0>, double>;
using SqrElectrCurrent = UnitBase<Exponents<0, 0, 0, 2, 0, 0, 0>, double>;
using SqrAmount = UnitBase<Exponents<0, 0, 0, 0, 0, 2, 0>, double>;
using SqrLuminosity = UnitBase<Exponents<0, 0, 0, 0, 0, 0, 2>, double>;
using Luminance = UnitBase<Exponents<-2, 0, 0, 0, 0, 0, 1>, double>;

// SI Units
// using Meter = Unit<Length, "m", double>;  // ---- Length
using SqMeter = Unit<Area, "m2", double>;
using CubeMeter = Unit<Volume, "m3", double>;
// using CentiMeter = Unit<Length, "cm", double>;
// using MilliMeter = Unit<Length, "mm", double>;
// using KiloMeter = Unit<Length, "km", double>;
// using InvMeter = Unit<InvLength, "inv_m", double>;
// using Gram = Unit<Mass, "g", double>;  // ---- Mass
// using Kilogram = Unit<Mass, "kg", double>;
// using Second = Unit<Time, "s", double>;           // ---- Time
using Ampere = Unit<ElectrCurrent, "A", double>;  // ---- ElectrCurrent
using Coulomb = Unit<ElectrCurrent, "C", double>;
using Milliampere = Unit<ElectrCurrent, "mA", double>;
using SqrAmpere = Unit<SqrElectrCurrent, "A2", double>;
using SqrMilliamp = Unit<SqrElectrCurrent, "mA2", double>;
using Kelvin = Unit<Temperature, "K", double>;  // ---- Temperature
using Fahrenheit = Unit<Temperature, "F", double>;
using Celsius = Unit<Temperature, "C", double>;
using Mole = Unit<Amount, "mol", double>;  // ---- Amount
using Kilomole = Unit<Amount, "kmol", double>;
using SqrMole = Unit<SqrAmount, "mol2", double>;
using SqrKilomole = Unit<SqrAmount, "kmol2", double>;
using Candela = Unit<Luminosity, "cd", double>;  // ---- Luminosity
using SqrCandela = Unit<SqrLuminosity, "cd2", double>;

// Other Units
using Pascal = Unit<Pressure, "Pa", double>;  // ---- Misc.
using Newton = Unit<Force, "N", double>;
using Psi = Unit<Pressure, "psi", double>;
using Bar = Unit<Pressure, "bar", double>;
using Atm = Unit<Pressure, "Atm", double>;
using MPerS2 = Unit<Accel, "m/s2", double>;
using KgPerM3 = Unit<Density, "kg/m3", double>;
using KgPerL = Unit<Density, "kg/L", double>;
// using Inch = Unit<Length, "in", double>;
// using Feet = Unit<Length, "ft", double>;
// using Yard = Unit<Length, "yd", double>;
// using Miles = Unit<Length, "miles", double>;
using SqFt = Unit<Area, "ft2", double>;
using Liter = Unit<Volume, "L", double>;
// using Minutes = Unit<Time, "min", double>;
// using Hours = Unit<Time, "hour", double>;
using CdPerM2 = Unit<Luminance, "cd/m2", double>;

// // Unit Cast for Base g to Unit kg
// // Conversion Equation: 1000 g = 1 kg
// template <>
// [[nodiscard]] constexpr auto UnitCast(Mass &&input) noexcept -> Kilogram {
//   return Kilogram(input.data);
// }

// // Unit Cast for Unit kg to Base g
// // Conversion Equation: 1000 g = 1 kg
// template <>
// [[nodiscard]] constexpr auto UnitCast(Kilogram &&input) noexcept -> Mass {
//   return Mass(input.data);
// }

// // Unit Cast for Base g to Unit g
// template <>
// [[nodiscard]] constexpr auto UnitCast(Mass &&input) noexcept -> Gram {
//   return Gram(input.data * 1000);
// }

// // Unit Cast for Unit g to Base g
// template <>
// [[nodiscard]] constexpr auto UnitCast(Gram &&input) noexcept -> Mass {
//   return Mass(input.data / 1000);
// }

// // Unit Cast for Unit s to Base s
// template <>
// [[nodiscard]] constexpr auto UnitCast(Second &&input) noexcept -> Time {
//   return Time(input.data);
// }

// // Unit Cast for Base s to Unit s
// template <>
// [[nodiscard]] constexpr auto UnitCast(Time &&input) noexcept -> Second {
//   return Second(input.data);
// }

// // Unit Cast for Unit min to Base s
// template <>
// [[nodiscard]] constexpr auto UnitCast(Minutes &&input) noexcept -> Time {
//   return Time(input.data * 60);
// }

// // Unit Cast for Base s to Unit min
// template <>
// [[nodiscard]] constexpr auto UnitCast(Time &&input) noexcept -> Minutes {
//   return Minutes(input.data / 60);
// }

// // Unit Cast for Unit min to Base s
// template <>
// [[nodiscard]] constexpr auto UnitCast(Hours &&input) noexcept -> Time {
//   return Time(input.data * 3600);
// }

// // Unit Cast for Base s to Unit min
// template <>
// [[nodiscard]] constexpr auto UnitCast(Time &&input) noexcept -> Hours {
//   return Hours(input.data / 3600);
// }

// // Unit cast for Base m to Unit m
// template <>
// [[nodiscard]] constexpr auto UnitCast(Length &&input) noexcept -> Meter {
//   return Meter(input.data);
// }

// // Unit Cast for Unit m to Base m
// template <>
// [[nodiscard]] constexpr auto UnitCast(Meter &&input) noexcept -> Length {
//   return Length(input.data);
// }

// // Unit cast for Base m to Unit cm
// // Conversion Equation: 1 m = 100 cm
// template <>
// [[nodiscard]] constexpr auto UnitCast(Length &&input) noexcept -> CentiMeter
// {
//   return CentiMeter(input.data * 100);
// }

// // Unit Cast for Unit cm to Base m
// // Conversion Equation: 1 m = 100 cm
// template <>
// [[nodiscard]] constexpr auto UnitCast(CentiMeter &&input) noexcept -> Length
// {
//   return Length(input.data / 100);
// }

// // Unit cast for Base m to Unit mm
// // Conversion Equation: 1 m = 1000 mm
// template <>
// [[nodiscard]] constexpr auto UnitCast(Length &&input) noexcept -> MilliMeter
// {
//   return MilliMeter(input.data * 1000);
// }

// // Unit Cast for Unit mm to Base m
// // Conversion Equation: 1 m = 1000 mm
// template <>
// [[nodiscard]] constexpr auto UnitCast(MilliMeter &&input) noexcept -> Length
// {
//   return Length(input.data / 1000);
// }

// // Unit cast for Base m to Unit km
// // Conversion Equation: 1000 m = 1 km
// template <>
// [[nodiscard]] constexpr auto UnitCast(Length &&input) noexcept -> KiloMeter {
//   return KiloMeter(input.data / 1000);
// }

// // Unit Cast for Unit km to Base m
// // Conversion Equation: 1000 m = 1 km
// template <>
// [[nodiscard]] constexpr auto UnitCast(KiloMeter &&input) noexcept -> Length {
//   return Length(input.data * 1000);
// }

// // Unit Cast for Base m to Unit in
// // Conversion Equation: 1 m = 39.3701 in
// template <>
// [[nodiscard]] constexpr auto UnitCast(Length &&input) noexcept -> Inch {
//   return Inch(input.data * 39.3701);
// }

// // Unit Cast for Unit in to Base m
// // Conversion Equation: 1 m = 39.3701 in
// template <>
// [[nodiscard]] constexpr auto UnitCast(Inch &&input) noexcept -> Length {
//   return Length(input.data / 39.3701);
// }

// // Unit Cast for Base m to Unit ft
// // Conversion Equation: 1 m = 3.28084 ft
// template <>
// [[nodiscard]] constexpr auto UnitCast(Length &&input) noexcept -> Feet {
//   return Feet(input.data * 3.28084);
// }

// // Unit Cast for Unit ft to Base m
// // Conversion Equation: 1 m = 3.28084 ft
// template <>
// [[nodiscard]] constexpr auto UnitCast(Feet &&input) noexcept -> Length {
//   return Length(input.data / 3.28084);
// }

// // Unit Cast for Base m to Unit yard
// // Conversion Equation: 1 m = 1.09361 yard
// template <>
// [[nodiscard]] constexpr auto UnitCast(Length &&input) noexcept -> Yard {
//   return Yard(input.data * 1.09361);
// }

// // Unit Cast for Unit yard to Base m
// // Conversion Equation: 1 m = 1.09361 yard
// template <>
// [[nodiscard]] constexpr auto UnitCast(Yard &&input) noexcept -> Length {
//   return Length(input.data / 1.09361);
// }

// // Unit Cast for Base m to Unit miles
// // Conversion Equation: 1609.34 m = 1 miles
// template <>
// [[nodiscard]] constexpr auto UnitCast(Length &&input) noexcept -> Miles {
//   return Miles(input.data / 1609.34);
// }

// // Unit Cast for Unit miles to Base m
// // Conversion Equation: 1609.34 m = 1 miles
// template <>
// [[nodiscard]] constexpr auto UnitCast(Miles &&input) noexcept -> Length {
//   return Length(input.data * 1609.34);
// }

// // Unit Cast for Base invlength to Unit invm
// template <>
// [[nodiscard]] constexpr auto UnitCast(InvLength &&input) noexcept -> InvMeter
// {
//   return InvMeter(input.data);
// }

// // Unit Cast for Unit invm to Base invlength
// template <>
// [[nodiscard]] constexpr auto UnitCast(InvMeter &&input) noexcept -> InvLength
// {
//   return InvLength(input.data);
// }

// Unit Cast for Base Pascals to Unit Pascals
// Conversion Equation: Pascals = Pascals
template <>
[[nodiscard]] constexpr auto UnitCast(Pressure &&input) noexcept -> Pascal {
  return Pascal(input.data);
}

// Unit Cast for Unit Pascals to Base Pascals
// Conversion Equation: Pascals = Pascals
template <>
[[nodiscard]] constexpr auto UnitCast(Pascal &&input) noexcept -> Pressure {
  return Pressure(input.data);
}

// Unit Cast for Base Pascals to Unit psi
// Conversion Equation: 1 psi = 6894.76 pascals
template <>
[[nodiscard]] constexpr auto UnitCast(Pressure &&input) noexcept -> Psi {
  return Psi(input.data / 6894.76);
}

// Unit Cast for Unit psi to Base Pascals
// Conversion Equation: 1 psi = 6894.76 pascals
template <>
[[nodiscard]] constexpr auto UnitCast(Psi &&input) noexcept -> Pressure {
  return Pressure(input.data * 6894.76);
}

// Unit Cast for Base Pascals to Unit Bar
// Conversion Equation: 1 bar = 100,000 pascals
template <>
[[nodiscard]] constexpr auto UnitCast(Pressure &&input) noexcept -> Bar {
  return Bar(input.data / 100000);
}

// Unit Cast for Unit Bar to Base Pascals
// Conversion Equation: 1 bar = 100,000 pascals
template <>
[[nodiscard]] constexpr auto UnitCast(Bar &&input) noexcept -> Pressure {
  return Pressure(input.data * 100000);
}

// Unit Cast for Base Pascals to Unit Atm
// Conversion Equation: 1 atm = 101,325 pascals
template <>
[[nodiscard]] constexpr auto UnitCast(Pressure &&input) noexcept -> Atm {
  return Atm(input.data / 101325);
}

// Unit Cast for Unit Bar to Base Pascals
// Conversion Equation: 1 bar = 101,325 pascals
template <>
[[nodiscard]] constexpr auto UnitCast(Atm &&input) noexcept -> Pressure {
  return Pressure(input.data * 101325);
}

// Unit Cast for Base Newton
template <>
[[nodiscard]] constexpr auto UnitCast(Force &&input) noexcept -> Newton {
  return Newton(input.data);
}
template <>
[[nodiscard]] constexpr auto UnitCast(Newton &&input) noexcept -> Force {
  return Force(input.data);
}

// Unit Cast for Base m2
template <>
[[nodiscard]] constexpr auto UnitCast(Area &&input) noexcept -> SqMeter {
  return SqMeter(input.data);
}

// Unit Cast for Unit m2
template <>
[[nodiscard]] constexpr auto UnitCast(SqMeter &&input) noexcept -> Area {
  return Area(input.data);
}

// Unit Cast for Base area to ft2
template <>
[[nodiscard]] constexpr auto UnitCast(Area &&input) noexcept -> SqFt {
  return SqFt(input.data * 10.764);
}

// Unit Cast for Unit ft2 to base area
template <>
[[nodiscard]] constexpr auto UnitCast(SqFt &&input) noexcept -> Area {
  return Area(input.data / 10.764);
}

// Unit Cast for base m3
template <>
[[nodiscard]] constexpr auto UnitCast(Volume &&input) noexcept -> CubeMeter {
  return CubeMeter(input.data);
}

// Unit Cast for Unit m3
template <>
[[nodiscard]] constexpr auto UnitCast(CubeMeter &&input) noexcept -> Volume {
  return Volume(input.data);
}

// Unit Cast for base
template <>
[[nodiscard]] constexpr auto UnitCast(Volume &&input) noexcept -> Liter {
  return Liter(input.data * 1000);
}

// Unit Cast for Unit Liter
template <>
[[nodiscard]] constexpr auto UnitCast(Liter &&input) noexcept -> Volume {
  return Volume(input.data / 1000);
}

// Unit Cast for Base mps2
template <>
[[nodiscard]] constexpr auto UnitCast(Accel &&input) noexcept -> MPerS2 {
  return MPerS2(input.data);
}

// Unit Cast for Unit Newton
template <>
[[nodiscard]] constexpr auto UnitCast(MPerS2 &&input) noexcept -> Accel {
  return Accel(input.data);
}

// Unit Cast for Unit Ampere
template <>
[[nodiscard]] constexpr auto UnitCast(ElectrCurrent &&input) noexcept
    -> Ampere {
  return Ampere(input.data);
}

// Unit Cast for Unit Ampere
template <>
[[nodiscard]] constexpr auto UnitCast(Ampere &&input) noexcept
    -> ElectrCurrent {
  return ElectrCurrent(input.data);
}

// base A -> Unit mA
template <>
[[nodiscard]] constexpr auto UnitCast(ElectrCurrent &&input) noexcept
    -> Milliampere {
  return Milliampere(input.data * 1000);
}

// Unit mA -> Base A
template <>
[[nodiscard]] constexpr auto UnitCast(Milliampere &&input) noexcept
    -> ElectrCurrent {
  return ElectrCurrent(input.data / 1000);
}

template <>
[[nodiscard]] constexpr auto UnitCast(SqrElectrCurrent &&input) noexcept
    -> SqrAmpere {
  return SqrAmpere(input.data);
}

template <>
[[nodiscard]] constexpr auto UnitCast(SqrAmpere &&input) noexcept
    -> SqrElectrCurrent {
  return SqrElectrCurrent(input.data);
}

template <>
[[nodiscard]] constexpr auto UnitCast(SqrElectrCurrent &&input) noexcept
    -> SqrMilliamp {
  return SqrMilliamp(input.data * 1000000);
}

template <>
[[nodiscard]] constexpr auto UnitCast(SqrMilliamp &&input) noexcept
    -> SqrElectrCurrent {
  return SqrElectrCurrent(input.data / 1000000);
}

// Unit Cast for Unit Kelvin
template <>
[[nodiscard]] constexpr auto UnitCast(Temperature &&input) noexcept -> Kelvin {
  return Kelvin(input.data);
}

// Unit Cast for Unit Kelvin
template <>
[[nodiscard]] constexpr auto UnitCast(Kelvin &&input) noexcept -> Temperature {
  return Temperature(input.data);
}

// Unit Cast for Base K to Unit F
template <>
[[nodiscard]] constexpr auto UnitCast(Temperature &&input) noexcept
    -> Fahrenheit {
  return Fahrenheit((input.data - 273.15) * 1.8 + 32);
}

// Unit Cast for Unit F to Base K
template <>
[[nodiscard]] constexpr auto UnitCast(Fahrenheit &&input) noexcept
    -> Temperature {
  return Temperature((input.data - 32) * 5 / 9 + 273.15);
}

// Base K -> Unit C
template <>
[[nodiscard]] constexpr auto UnitCast(Temperature &&input) noexcept -> Celsius {
  return Celsius(input.data - 273.15);
}

// Unit C -> Base K
template <>
[[nodiscard]] constexpr auto UnitCast(Celsius &&input) noexcept -> Temperature {
  return Temperature(input.data + 273.15);
}

// Unit Cast for Unit Mol
template <>
[[nodiscard]] constexpr auto UnitCast(Amount &&input) noexcept -> Mole {
  return Mole(input.data);
}

// Unit Cast for Unit Mole
template <>
[[nodiscard]] constexpr auto UnitCast(Mole &&input) noexcept -> Amount {
  return Amount(input.data);
}

// Base Mole -> Kilomole unit
template <>
[[nodiscard]] constexpr auto UnitCast(Amount &&input) noexcept -> Kilomole {
  return Kilomole(input.data / 1000);
}

// unit kmol -> Base Mol
template <>
[[nodiscard]] constexpr auto UnitCast(Kilomole &&input) noexcept -> Amount {
  return Amount(input.data * 1000);
}

template <>
[[nodiscard]] constexpr auto UnitCast(SqrAmount &&input) noexcept -> SqrMole {
  return SqrMole(input.data);
}

template <>
[[nodiscard]] constexpr auto UnitCast(SqrMole &&input) noexcept -> SqrAmount {
  return SqrAmount(input.data);
}

template <>
[[nodiscard]] constexpr auto UnitCast(SqrAmount &&input) noexcept
    -> SqrKilomole {
  return SqrKilomole(input.data / 1000000);
}

template <>
[[nodiscard]] constexpr auto UnitCast(SqrKilomole &&input) noexcept
    -> SqrAmount {
  return SqrAmount(input.data * 1000000);
}

// Unit Cast for Unit Candela
template <>
[[nodiscard]] constexpr auto UnitCast(Luminosity &&input) noexcept -> Candela {
  return Candela(input.data);
}

// Unit Cast for Unit Candela
template <>
[[nodiscard]] constexpr auto UnitCast(Candela &&input) noexcept -> Luminosity {
  return Luminosity(input.data);
}

template <>
[[nodiscard]] constexpr auto UnitCast(Luminance &&input) noexcept -> CdPerM2 {
  return CdPerM2(input.data);
}

// Unit Cast for Unit Newton
template <>
[[nodiscard]] constexpr auto UnitCast(CdPerM2 &&input) noexcept -> Luminance {
  return Luminance(input.data);
}

template <>
[[nodiscard]] constexpr auto UnitCast(SqrLuminosity &&input) noexcept
    -> SqrCandela {
  return SqrCandela(input.data);
}

template <>
[[nodiscard]] constexpr auto UnitCast(SqrCandela &&input) noexcept
    -> SqrLuminosity {
  return SqrLuminosity(input.data);
}

// Unit Cast for Unit kg/m^3
template <>
[[nodiscard]] constexpr auto UnitCast(Density &&input) noexcept -> KgPerM3 {
  return KgPerM3(input.data);
}

// Unit Cast for Unit kg/m^3
template <>
[[nodiscard]] constexpr auto UnitCast(KgPerM3 &&input) noexcept -> Density {
  return Density(input.data);
}

// Unit Cast for Unit kg/L
template <>
[[nodiscard]] constexpr auto UnitCast(Density &&input) noexcept -> KgPerL {
  return KgPerL(input.data / 1000);
}

// Unit Cast for Unit kg/L
template <>
[[nodiscard]] constexpr auto UnitCast(KgPerL &&input) noexcept -> Density {
  return Density(input.data * 1000);
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

}  // namespace csm_units