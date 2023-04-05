#pragma once

#include <csm_units/concepts.hpp>
#include <ratio>
#include <type_traits>
#include <utility>

#include "exponents.hpp"
#include "unitcast.hpp"

namespace csm_units {

// compound - compoud alias
// compound - base alias
template <ExpType Powers, Arithmetic Data>
class UnitBase {
 public:
  using Dimensions = Powers;
  constexpr explicit UnitBase(Data value = 0) noexcept : data(value) {
    static_assert(Powers::L::num != 0 or Powers::M::num != 0 or
                      Powers::T::num != 0 or Powers::C::num != 0 or
                      Powers::TP::num != 0 or Powers::A::num != 0 or
                      Powers::LM::num != 0,
                  "You defined all exponents equal to zero. Use an "
                  "arithmetictype instead");
  }

  template <class U>
  constexpr UnitBase(U convert) noexcept
      : data(UnitCast<UnitBase>(convert).data) {}

  // copy constructor
  constexpr UnitBase(const UnitBase& other) noexcept = default;

  // move constructor
  constexpr UnitBase(UnitBase&& other) noexcept = default;

  Data data;

  // quick stab at Flip member function
  constexpr auto Flip() noexcept {
    return UnitBase<ExponentsFlip<Powers>, Data>(std::move(1 / data));
  }

  // / operator overloads

  // compound / compound for two of the same unit
  friend constexpr auto operator/(UnitBase lhs, UnitBase rhs) noexcept {
    return lhs.data / rhs.data;
  }

  // compound / compound
  template <ExpType Powers2>  // second object
  friend constexpr auto operator/(UnitBase lhs,
                                  UnitBase<Powers2, Data> rhs) noexcept {
    return UnitBase<ExponentsSubtract<Powers, Powers2>, Data>(lhs.data /
                                                              rhs.data);
  }

  template <UnitType Other>  // second object
  friend constexpr auto operator/(UnitBase lhs, Other rhs) noexcept {
    return lhs / UnitBase(rhs);
  }

  // NOLINTBEGIN(bugprone-move-forwarding-reference) Factory requires std move

  // compound /= double
  constexpr auto operator/=(Arithmetic auto rhs) noexcept -> auto& {
    data /= rhs;
    return *this;
  }

  // compound / double
  friend constexpr auto operator/(UnitBase lhs, Arithmetic auto rhs) noexcept {
    lhs /= rhs;
    return lhs;
  }

  // double / compound
  friend constexpr auto operator/(Arithmetic auto lhs, UnitBase rhs) noexcept {
    return (UnitBase<ExponentsFlip<Powers>, decltype(lhs)>(lhs / rhs.data));
  }

  // * operator overloads
  friend constexpr auto operator*(
      UnitBase lhs, UnitBase<ExponentsFlip<Powers>, Data> rhs) noexcept {
    return lhs.data * rhs.data;
  }

  // compound * compound
  template <ExpType Powers2>  // second object
  friend constexpr auto operator*(UnitBase lhs,
                                  UnitBase<Powers2, Data> rhs) noexcept {
    return UnitBase<ExponentsAdd<Powers, Powers2>, Data>(lhs.data * rhs.data);
  }

  template <UnitType Other>  // second object
  friend constexpr auto operator*(UnitBase lhs, Other rhs) noexcept {
    return lhs * UnitBase(rhs);
  }

  // compoud *= double
  constexpr auto operator*=(Arithmetic auto rhs) noexcept -> auto& {
    data *= rhs;
    return *this;
  }

  // compound * double
  friend constexpr auto operator*(UnitBase lhs, Arithmetic auto rhs) noexcept {
    lhs *= rhs;
    return lhs;
  }

  // double * compound
  friend constexpr auto operator*(Arithmetic auto lhs, UnitBase rhs) noexcept {
    return (UnitBase(lhs * rhs.data));
  }

  // + operator overloads

  constexpr auto operator+=(const UnitBase& rhs) noexcept -> auto& {
    data += rhs.data;
    return *this;
  }

  // compound + compound
  friend constexpr auto operator+(UnitBase lhs, const UnitBase& rhs) noexcept {
    lhs += rhs;
    return lhs;
  }

  // - operator overloads
  constexpr auto operator-=(const UnitBase& rhs) noexcept -> auto& {
    data -= rhs.data;
    return *this;
  }

  // compound - compound
  friend constexpr auto operator-(UnitBase lhs, const UnitBase& rhs) noexcept {
    lhs -= rhs;
    return lhs;
  }
};

// constexpr auto UnitCast(
//     Unit<UnitBase<Exponents<0, 1, 0, 0, 0, 0, 0>, double>, "kg", double>
//         convert_from,
//     UnitBase<Exponents<0, 1, 0, 0, 0, 0, 0>, double> /*convert_to*/)
//     -> UnitBase<Exponents<0, 1, 0, 0, 0, 0, 0>, double> {
//   return UnitBase<Exponents<0, 1, 0, 0, 0, 0, 0>, double>(convert_from.data *
//                                                           1000);
// }

// NOLINTEND(bugprone-move-forwarding-reference)

}  // namespace csm_units