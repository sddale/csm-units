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
class Derived;

// namespace derived {

// struct Factory {
//   template <class Conv, class Ratio, Arithmetic Data>
//   static auto Make(Base<DimLength, Conv, Ratio, Data>&& base) {
//     return Derived<Exponents<1, 0, 0>, Base<DimLength, Conv, Ratio, Data>,
//                    Base<DimMass>, Base<DimTime>, Data>(
//         std::forward<decltype(base)>(base));
//   }

//   template <class Conv, class Ratio, Arithmetic Data>
//   static auto Make(Base<DimTime, Conv, Ratio, Data>&& base) {
//     return Derived<Exponents<0, 0, 1>, Base<DimLength>, Base<DimMass>,
//                    Base<DimTime, Conv, Ratio, Data>, Data>(
//         std::forward<decltype(base)>(base));
//   }

//   template <class Conv, class Ratio, Arithmetic Data>
//   static auto Make(Base<DimMass, Conv, Ratio, Data>&& base) {
//     return Derived<Exponents<0, 1, 0>, Base<DimLength>,
//                    Base<DimMass, Conv, Ratio, Data>, Base<DimTime>, Data>(
//         std::forward<decltype(base)>(base));
//   }
// };

// }  // namespace derived

template <ExpType Powers, class Converters, class Prefixes, Arithmetic Data>
class Derived {
 public:
  constexpr explicit Derived(Data value = 0) noexcept : data(value) {
    static_assert(
        Powers::L::num != 0 or Powers::M::num != 0 or Powers::T::num != 0,
        "You defined all exponents equal to zero. Use an arithmetic "
        "type instead");
  }

  // copy constructor
  constexpr Derived(const Derived& other) noexcept = default;
  constexpr Derived(const BaseType auto& other) noexcept : data(other.data){};

  // move constructor
  constexpr Derived(Derived&& other) noexcept = default;

  // // NOLINTBEGIN(bugprone-forwarding-reference-overload) Factory requires std
  // // move
  // constexpr Derived(BaseType auto&& other) noexcept
  //     : data(std::move(other.data)) {}
  // // NOLINTEND(bugprone-forwarding-reference-overload)

  Data data;

  // quick stab at Flip member function
  constexpr auto Flip() noexcept {
    return Derived<ExponentsFlip<Powers>, Converters, Prefixes, Data>(
        std::move(1 / data));
  }

  // test operator overload for _K
  // friend constexpr long double operator""_M(long double) {
  //   Derived<Exponents<1, 0, 0>, Base<DimLength>, Base<DimMass>,
  //   Base<DimTime>,
  //           long double>(data);
  // }

  // / operator overloads

  // compound / compound for two of the same derived
  template <class Converters2, class Prefixes2>
  friend constexpr auto operator/(
      Derived lhs, Derived<Powers, Converters2, Prefixes2, Data> rhs) noexcept {
    return lhs.data / rhs.data;
  }

  // compound / compound
  template <ExpType Powers2, class Converters2,
            class Prefixes2>  // second object
  friend constexpr auto operator/(
      Derived lhs,
      Derived<Powers2, Converters2, Prefixes2, Data> rhs) noexcept {
    return (
        Derived<ExponentsSubtract<Powers, Powers2>, Converters, Prefixes, Data>(
            lhs.data / rhs.data));
  }

  // NOLINTBEGIN(bugprone-move-forwarding-reference) Factory requires std move
  // //  compound / base
  // friend constexpr auto operator/(Derived lhs, BaseType auto&& rhs) noexcept
  // {
  //   return lhs / derived::Factory::Make(std::move(rhs));
  // }

  // // base / compound
  // friend constexpr auto operator/(BaseType auto&& lhs, Derived rhs) noexcept
  // {
  //   return derived::Factory::Make(std::move(lhs)) / rhs;
  // }

  // compound /= double
  constexpr auto operator/=(Arithmetic auto rhs) noexcept -> auto& {
    data /= rhs;
    return *this;
  }

  // compound / double
  friend constexpr auto operator/(Derived lhs, Arithmetic auto rhs) noexcept {
    lhs /= rhs;
    return lhs;
  }

  // double / compound
  friend constexpr auto operator/(Arithmetic auto lhs, Derived rhs) noexcept {
    return (Derived<ExponentsFlip<Powers>, Converters, Prefixes, decltype(lhs)>(
        lhs / rhs.data));
  }

  // * operator overloads
  template <class Converters2, class Prefixes2, class Data2>
  friend constexpr auto operator*(
      Derived lhs, Derived<ExponentsFlip<Powers>, Converters2, Prefixes2, Data2>
                       rhs) noexcept {
    return lhs.data * rhs.data;
  }

  // compound * compound
  template <ExpType Powers2, class Converters2,
            class Prefixes2>  // second object
  friend constexpr auto operator*(
      Derived lhs,
      Derived<Powers2, Converters2, Prefixes2, Data> rhs) noexcept {
    return (Derived<ExponentsAdd<Powers, Powers2>, Converters, Prefixes, Data>(
        lhs.data * rhs.data));
  }

  // // compound * base
  // friend constexpr auto operator*(Derived lhs, BaseType auto&& rhs) noexcept
  // {
  //   return lhs * derived::Factory::Make(std::move(rhs));
  // }

  // // base * compound
  // friend constexpr auto operator*(BaseType auto&& lhs, Derived rhs) noexcept
  // {
  //   return derived::Factory::Make(std::move(lhs)) * rhs;
  // }

  // compoud *= double
  constexpr auto operator*=(Arithmetic auto rhs) noexcept -> auto& {
    data *= rhs;
    return *this;
  }

  // compound * double
  friend constexpr auto operator*(Derived lhs, Arithmetic auto rhs) noexcept {
    lhs *= rhs;
    return lhs;
  }

  // double * compound
  friend constexpr auto operator*(Arithmetic auto lhs, Derived rhs) noexcept {
    return (Derived(lhs * rhs.data));
  }

  // + operator overloads

  constexpr auto operator+=(const Derived& rhs) noexcept -> auto& {
    data += rhs.data;
    return *this;
  }

  // compound + compound
  friend constexpr auto operator+(Derived lhs, const Derived& rhs) noexcept {
    lhs += rhs;
    return lhs;
  }

  // - operator overloads

  constexpr auto operator-=(const Derived& rhs) noexcept -> auto& {
    data -= rhs.data;
    return *this;
  }

  // compound - compound
  friend constexpr auto operator-(Derived lhs, const Derived& rhs) noexcept {
    lhs -= rhs;
    return lhs;
  }
};

// NOLINTEND(bugprone-move-forwarding-reference)

// Aliases for basic units
template <int LP, int MP, int TP>
using DBasic = Derived<Exponents<LP, MP, TP>, Converters<>, Prefixes<>, double>;

using Meter = DBasic<1, 0, 0>;
using Seconds = DBasic<0, 0, 1>;
// using Kilograms =
//     Derived<Base<DimLength>, 0,
//             Base<DimMass, NoConverter, std::ratio<1000, 1>, double>, 1,
//             Base<DimTime>, 0, double>; // Kilograms can't be used like this
//             yet, because the test cases can't handle ratio yet
// using Mole = //cannot do this yet
// using Ampere = //cannot do this yet
// using Kelvin = //cannot do this yet
// using Candela = //cannot do this yet

}  // namespace csm_units