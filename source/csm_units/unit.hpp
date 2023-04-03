#pragma once

#include <csm_units/concepts.hpp>

#include "unitbase.hpp"

namespace csm_units {

template <size_t N>
struct StringLiteral {
  constexpr StringLiteral(const char (&str)[N]) { std::copy_n(str, N, value); }

  char value[N];
};

template <UnitBaseType SI, StringLiteral Unit_Name, Arithmetic Data>
class Unit {
 public:
  constexpr explicit Unit(Data value = 0.0) noexcept : data(value){};

  constexpr Unit(SI new_base) noexcept
      : data(UnitCast(new_base, Unit()).data){};

  Data data;

  friend constexpr auto operator+(Unit lhs, Unit rhs) noexcept {
    lhs.data += rhs.data;
    return lhs;
  }
};

// template <Unit<UnitBase<Exponents<0, 1, 0, 0, 0, 0, 0>, double>, "kg",
// double>
//               convert_to>
constexpr auto UnitCast(
    UnitBase<Exponents<0, 1, 0, 0, 0, 0, 0>, double> convert_from,
    Unit<UnitBase<Exponents<0, 1, 0, 0, 0, 0, 0>, double>, "kg", double>
    /*convert_to*/)
    -> Unit<UnitBase<Exponents<0, 1, 0, 0, 0, 0, 0>, double>, "kg", double> {
  return Unit<UnitBase<Exponents<0, 1, 0, 0, 0, 0, 0>, double>, "kg", double>(
      convert_from.data / 1000);
}

// user defined literals

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

// Aliases for basic units
template <int LP, int MP, int TP, int CP, int TPP, int AP, int LMP,
          StringLiteral Name>
using DBasic = Unit<UnitBase<Exponents<LP, MP, TP, CP, TPP, AP, LMP>, double>,
                    Name, double>;

using Meter = DBasic<1, 0, 0, 0, 0, 0, 0, "m">;
using Kilograms = DBasic<0, 1, 0, 0, 0, 0, 0, "kg">;
using Seconds = DBasic<0, 0, 1, 0, 0, 0, 0, "s">;
using Ampere = DBasic<0, 0, 0, 1, 0, 0, 0, "A">;
using Kelvin = DBasic<0, 0, 0, 0, 1, 0, 0, "K">;
using Mole = DBasic<0, 0, 0, 0, 0, 1, 0, "mol">;
using Candela = DBasic<0, 0, 0, 0, 0, 0, 1, "cd">;

// class Foo2;

// template <class convertTo>
// constexpr auto Cast(Foo2 convertFrom) -> convertTo;

// class Foo2 {
//  public:
//   constexpr explicit Foo2(double value = 0.0) noexcept : data(value){};

//   double data;
// };

// class Foo1 {
//  public:
//   constexpr explicit Foo1(double value = 0.0) noexcept : data(value){};
//   constexpr Foo1(Foo2 thing) noexcept : data(Cast<Foo1>(thing).data){};

//   double data;

//   friend constexpr auto operator+(Foo1 lhs, Foo1 rhs) {
//     return Foo1(lhs.data + rhs.data);
//   }
// };

// template <class convertTo>
// constexpr auto Cast(Foo2 convertFrom) -> convertTo {
//   return (convertTo(convertFrom.data));
// }

}  // namespace csm_units