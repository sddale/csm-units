#pragma once

#include <ratio>
#include <utility>

#include "converter.hpp"
#include "exponents.hpp"
#include "prefixes.hpp"

namespace csm_units {

// compound - compoud alias
// compound - base alias

template <ExpType Powers, class Converters, class Prefixes, Arithmetic Data>
class Unit {
 public:
  constexpr explicit Unit(Data value = 0) noexcept : data(value) {
    static_assert(Powers::L::num != 0 or Powers::M::num != 0 or
                      Powers::T::num != 0 or Powers::C::num != 0 or
                      Powers::TP::num != 0 or Powers::A::num != 0 or
                      Powers::LM::num != 0,
                  "You defined all exponents equal to zero. Use an arithmetic "
                  "type instead");
  }

  // copy constructor
  constexpr Unit(const Unit& other) noexcept = default;
  constexpr Unit(const BaseType auto& other) noexcept : data(other.data){};

  // move constructor
  constexpr Unit(Unit&& other) noexcept = default;

  Data data;

  // quick stab at Flip member function
  constexpr auto Flip() noexcept {
    return Unit<ExponentsFlip<Powers>, Converters, Prefixes, Data>(
        std::move(1 / data));
  }

  // / operator overloads

  // compound / compound for two of the same unit
  template <class Converters2, class Prefixes2>
  friend constexpr auto operator/(
      Unit lhs, Unit<Powers, Converters2, Prefixes2, Data> rhs) noexcept {
    return lhs.data / rhs.data;
  }

  // compound / compound
  template <ExpType Powers2, class Converters2,
            class Prefixes2>  // second object
  friend constexpr auto operator/(
      Unit lhs, Unit<Powers2, Converters2, Prefixes2, Data> rhs) noexcept {
    return (
        Unit<ExponentsSubtract<Powers, Powers2>, Converters, Prefixes, Data>(
            lhs.data / rhs.data));
  }

  // NOLINTBEGIN(bugprone-move-forwarding-reference) Factory requires std move
  // //  compound / base
  // friend constexpr auto operator/(Unit lhs, BaseType auto&& rhs) noexcept
  // {
  //   return lhs / unit::Factory::Make(std::move(rhs));
  // }

  // // base / compound
  // friend constexpr auto operator/(BaseType auto&& lhs, Unit rhs) noexcept
  // {
  //   return unit::Factory::Make(std::move(lhs)) / rhs;
  // }

  // compound /= double
  constexpr auto operator/=(Arithmetic auto rhs) noexcept -> auto& {
    data /= rhs;
    return *this;
  }

  // compound / double
  friend constexpr auto operator/(Unit lhs, Arithmetic auto rhs) noexcept {
    lhs /= rhs;
    return lhs;
  }

  // double / compound
  friend constexpr auto operator/(Arithmetic auto lhs, Unit rhs) noexcept {
    return (Unit<ExponentsFlip<Powers>, Converters, Prefixes, decltype(lhs)>(
        lhs / rhs.data));
  }

  // * operator overloads
  template <class Converters2, class Prefixes2>
  friend constexpr auto operator*(
      Unit lhs,
      Unit<ExponentsFlip<Powers>, Converters2, Prefixes2, Data> rhs) noexcept {
    return lhs.data * rhs.data;
  }

  // compound * compound
  template <ExpType Powers2, class Converters2,
            class Prefixes2>  // second object
  friend constexpr auto operator*(
      Unit lhs, Unit<Powers2, Converters2, Prefixes2, Data> rhs) noexcept {
    return (Unit<ExponentsAdd<Powers, Powers2>, Converters, Prefixes, Data>(
        lhs.data * rhs.data));
  }

  // // compound * base
  // friend constexpr auto operator*(Unit lhs, BaseType auto&& rhs) noexcept
  // {
  //   return lhs * unit::Factory::Make(std::move(rhs));
  // }

  // // base * compound
  // friend constexpr auto operator*(BaseType auto&& lhs, Unit rhs) noexcept
  // {
  //   return unit::Factory::Make(std::move(lhs)) * rhs;
  // }

  // compoud *= double
  constexpr auto operator*=(Arithmetic auto rhs) noexcept -> auto& {
    data *= rhs;
    return *this;
  }

  // compound * double
  friend constexpr auto operator*(Unit lhs, Arithmetic auto rhs) noexcept {
    lhs *= rhs;
    return lhs;
  }

  // double * compound
  friend constexpr auto operator*(Arithmetic auto lhs, Unit rhs) noexcept {
    return (Unit(lhs * rhs.data));
  }

  // + operator overloads

  constexpr auto operator+=(const Unit& rhs) noexcept -> auto& {
    data += rhs.data;
    return *this;
  }

  // compound + compound
  friend constexpr auto operator+(Unit lhs, const Unit& rhs) noexcept {
    lhs += rhs;
    return lhs;
  }

  // - operator overloads

  constexpr auto operator-=(const Unit& rhs) noexcept -> auto& {
    data -= rhs.data;
    return *this;
  }

  // compound - compound
  friend constexpr auto operator-(Unit lhs, const Unit& rhs) noexcept {
    lhs -= rhs;
    return lhs;
  }

  constexpr static auto FromBase(double data) {
    return Converters::FromBase(data, Powers());
  }

  constexpr static auto ToBase(double data) {
    return Converters::ToBase(data, Powers());
  }
};

// NOLINTEND(bugprone-move-forwarding-reference)

// user defined literals

// length - meter
constexpr auto operator""_m(long double data) noexcept {
  return Unit<Exponents<1, 0, 0, 0, 0, 0, 0>, Converters<>, Prefixes<>, double>(
      static_cast<double>(data));
}

// mass - kilogram
constexpr auto operator""_kg(long double data) noexcept {
  return Unit<Exponents<0, 1, 0, 0, 0, 0, 0>, Converters<>, Prefixes<>, double>(
      static_cast<double>(data));
}

// time - second
constexpr auto operator""_s(long double data) noexcept {
  return Unit<Exponents<0, 0, 1, 0, 0, 0, 0>, Converters<>, Prefixes<>, double>(
      static_cast<double>(data));
}

// current - ampere
constexpr auto operator""_A(long double data) noexcept {
  return Unit<Exponents<0, 0, 0, 1, 0, 0, 0>, Converters<>, Prefixes<>, double>(
      static_cast<double>(data));
}

// temperature - kelvin
constexpr auto operator""_K(long double data) noexcept {
  return Unit<Exponents<0, 0, 0, 0, 1, 0, 0>, Converters<>, Prefixes<>, double>(
      static_cast<double>(data));
}

// amount - mole
constexpr auto operator""_mol(long double data) noexcept {
  return Unit<Exponents<0, 0, 0, 0, 0, 1, 0>, Converters<>, Prefixes<>, double>(
      static_cast<double>(data));
}

// luminosity - candela
constexpr auto operator""_cd(long double data) noexcept {
  return Unit<Exponents<0, 0, 0, 0, 0, 0, 1>, Converters<>, Prefixes<>, double>(
      static_cast<double>(data));
}

// Aliases for basic units
template <int LP, int MP, int TP, int CP, int TPP, int AP, int LMP>
using DBasic = Unit<Exponents<LP, MP, TP, CP, TPP, AP, LMP>, Converters<>,
                    Prefixes<>, double>;

using Meter = DBasic<1, 0, 0, 0, 0, 0, 0>;
using Seconds = DBasic<0, 0, 1, 0, 0, 0, 0>;
// using Kilograms =
//     Unit<Base<DimLength>, 0,
//             Base<DimMass, NoConverter, std::ratio<1000, 1>, double>, 1,
//             Base<DimTime>, 0, double>; // Kilograms can't be used like this
//             yet, because the test cases can't handle ratio yet
// using Mole = //cannot do this yet
// using Ampere = //cannot do this yet
// using Kelvin = //cannot do this yet
// using Candela = //cannot do this yet

}  // namespace csm_units