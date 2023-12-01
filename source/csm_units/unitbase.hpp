/**  \file unitbase.hpp
 *   \brief This file defines a base unit in SI for the dimension given by the
 * powers template. The powers template is derived from the exponents class.
 *
 * For arithmetic to be able to be applied to a derived unit a conversion from a
 * to the SI version of the unit needs to be defined as explained in the
 * unit.hpp file.
 */

#pragma once

#include <csm_units/concepts.hpp>
#include <type_traits>

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
                  "arithmetic type instead");
  }

  template <UnitType U>
    requires std::is_same_v<typename U::SI, UnitBase>
  constexpr explicit(false) UnitBase(U convert) noexcept
      : data(UnitCast<UnitBase>(convert).data) {}

  constexpr auto operator<=>(const UnitBase& other) const noexcept {
    return data <=> other.data;
  }

  template <UnitType U>
  friend constexpr auto operator<=>(const UnitBase& lhs,
                                    const U& rhs) noexcept {
    return lhs <=> UnitBase(rhs);
  }

  constexpr auto operator==(const UnitBase& other) const noexcept
      -> bool = default;

  template <UnitType U>
  friend constexpr auto operator==(const UnitBase& lhs, const U& rhs) noexcept
      -> bool {
    return lhs == UnitBase(rhs);
  }

  // copy constructor
  constexpr UnitBase(const UnitBase& other) noexcept = default;

  // move constructor
  constexpr UnitBase(UnitBase&& other) noexcept = default;

  constexpr auto operator=(const UnitBase&) noexcept -> UnitBase& = default;
  constexpr auto operator=(UnitBase&&) noexcept -> UnitBase& = default;

  Data data;

  // Flip function
  constexpr auto Flip() noexcept {
    return UnitBase<ExponentsFlip<Powers>, Data>(data);
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
    return lhs / typename Other::SI(rhs);
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
    return (UnitBase<ExponentsFlip<Powers>, Data>(lhs / rhs.data));
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
    return lhs * typename Other::SI(rhs);
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
  // friend constexpr auto operator+(UnitBase lhs, const UnitBase& rhs) noexcept
  // {
  //   lhs.data = lhs.data + rhs.data;
  //   return lhs;
  // }

  // friend constexpr auto operator+(UnitBase lhs, UnitBase&& rhs) noexcept {
  //   lhs.data = lhs.data + rhs.data;
  //   return lhs;
  // }

  // - operator overloads

  constexpr auto operator-=(const UnitBase& rhs) noexcept -> auto& {
    data -= rhs.data;
    return *this;
  }

  // compound - compound
  friend constexpr auto operator-(UnitBase lhs, const UnitBase& rhs) noexcept {
    lhs.data = lhs.data - rhs.data;
    return lhs;
  }
};

// NOLINTEND(bugprone-move-forwarding-reference)

}  // namespace csm_units