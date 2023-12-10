// /**  \file unit.hpp
//  *   \brief This file defines a derived unit of any dimension and any system.
//  *
//  * The system refers to what standard the data is in. For example, the
//  * International System of Units (SI) is a system in this sense. To define a
//  new
//  * unit please refer ot the instructions in the \link unitcast.hpp \endlink
//  * file.
//  */

#pragma once

#include <compare>
#include <csm_units/concepts.hpp>
#include <gcem.hpp>

#include "definition.hpp"
#include "exponents.hpp"

#ifndef CSMUNITS_VALUE_TYPE
#define CSMUNITS_VALUE_TYPE double
#endif

namespace csm_units {

template <IsDefinition Def, IsArithmetic Data = CSMUNITS_VALUE_TYPE,
          IsRatio ZeroPoint = std::ratio<0>>
class Unit {
 public:
  using def = Def;
  using type = Data;
  using zero_point = ZeroPoint;

  constexpr explicit Unit(Data input = std::declval<type>())
      : data((input + static_cast<type>(ZeroPoint::num) / ZeroPoint::den) *
             def::ToSI()){};

  template <SameDimAs<Unit> U>
    requires std::same_as<zero_point, typename U::zero_point>
  constexpr explicit(false) Unit(U input) : data(input.data) {}

  [[nodiscard]] constexpr auto Get() const {
    return data * Def::Get() -
           static_cast<type>(ZeroPoint::num) / ZeroPoint::den;
  }
  [[nodiscard]] constexpr auto SI() const {
    return data - static_cast<type>(ZeroPoint::num) / ZeroPoint::den;
  }

  Data data;  // magnitude in si

  template <SameDimAs<Unit> U>
  constexpr friend auto operator<=>(const Unit& lhs, const U& rhs) noexcept
      -> std::strong_ordering {
    return std::strong_order(lhs.data, rhs.data);
  }
  template <SameDimAs<Unit> U>
  constexpr friend auto operator==(const Unit& lhs, const U& rhs) noexcept
      -> bool {
    return lhs.data == rhs.data;
  }

  template <SameDimAs<Unit> U>
  constexpr auto operator-=(const U& rhs) noexcept -> auto& {
    data -= static_cast<type>(rhs.data);
    return *this;
  }
  constexpr friend auto operator-(Unit lhs) noexcept {
    lhs.data = -1 * lhs.data;
    return lhs;
  }
  template <SameDimAs<Unit> U>
  constexpr friend auto operator-(Unit lhs, const U& rhs) noexcept {
    lhs -= rhs;
    return lhs;
  }

  template <SameDimAs<Unit> U>
  constexpr auto operator+=(const U& rhs) noexcept -> auto& {
    data += static_cast<type>(rhs.data);
    return *this;
  }

  template <SameDimAs<Unit> U>
  constexpr friend auto operator+(Unit lhs, const U& rhs) noexcept {
    lhs += rhs;
    return lhs;
  }

  template <IsUnit U>
    requires std::same_as<typename U::def::dim,
                          ExponentsFlip<typename def::dim>>
  constexpr friend auto operator*(Unit lhs, U rhs) noexcept {
    return lhs.data * rhs.data;
  }

  template <IsUnit U>
  constexpr friend auto operator*(Unit lhs, const U& rhs) noexcept {
    using result_type =
        decltype(std::declval<type&>() * std::declval<typename U::type&>());
    return Unit<typename Unit::def::template Multiply<typename U::def>,
                result_type>(lhs.data * rhs.data);
  }
  constexpr auto operator*=(IsArithmetic auto rhs) noexcept -> auto& {
    data *= rhs;
    return *this;
  }
  constexpr friend auto operator*(Unit lhs, IsArithmetic auto rhs) noexcept {
    lhs *= rhs;
    return lhs;
  }

  template <SameDimAs<Unit> U>
  constexpr friend auto operator/(Unit lhs, U rhs) noexcept {
    return lhs.data / rhs.data;
  }
  template <IsUnit U>
  constexpr friend auto operator/(Unit lhs, const U& rhs) noexcept {
    using result_type =
        decltype(std::declval<type&>() / std::declval<typename U::type&>());
    return Unit<typename Unit::def::template Divide<typename U::def>,
                result_type>(lhs.data / rhs.data);
  }
  constexpr auto operator/=(IsArithmetic auto rhs) noexcept -> auto& {
    data /= rhs;
    return *this;
  }
  constexpr friend auto operator/(Unit lhs, IsArithmetic auto rhs) noexcept {
    lhs /= rhs;
    return lhs;
  }
};

template <IsDefinition D>
constexpr auto operator*(IsArithmetic auto lhs, D /*rhs*/) {
  return Unit<D, decltype(lhs)>(lhs);
}
template <IsDefinition DL, IsDefinition DR>
constexpr auto operator*(DL /*lhs*/, DR /*rhs*/) {
  return Unit<typename DR::template Multiply<DL>>(1.0);
}
template <IsUnit U, IsDefinition D>
constexpr auto operator*(U lhs, D /*rhs*/) {
  return Unit<typename D::template Multiply<typename U::def>, typename U::type>(
      lhs.data);
}
template <IsDefinition D>
constexpr auto operator/(IsArithmetic auto lhs, D /*rhs*/) {
  return Unit<typename D::InverseDef, decltype(lhs)>(lhs);
}
template <IsDefinition DL, IsDefinition DR>
constexpr auto operator/(DL /*lhs*/, DR /*rhs*/) {
  return Unit<typename DR::template Divide<DL>>(1.0);
}
template <IsUnit U, IsDefinition D>
constexpr auto operator/(U lhs, D /*rhs*/) {
  return Unit<typename D::template Divide<typename U::def>, typename U::type>(
      lhs.data);
}

}  // namespace csm_units