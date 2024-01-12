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

#include "definition.hpp"
#include "dimension.hpp"

#ifndef CSMUNITS_VALUE_TYPE
#define CSMUNITS_VALUE_TYPE double
#endif

namespace csm_units {

// Def: specifier for the unit's dimensions and the  conversions to SI fo each
// dimension
// Data: storage ValueType such that sizeof(Data) = sizeof(Unit)
// ZeroPoint: 0 [unit] = std::ratio<N,D> [SI]
// i.e for Fahrenheit, ZeroPoint = ratio<45967, 180> = approx 255.372[Kelvin]
template <Definition definition, IsArithmetic Data = CSMUNITS_VALUE_TYPE>
class Unit {
 public:
  using DefType = decltype(definition);
  using ValueType = Data;
  using OriginType = typename DefType::OriginType;
  using DimenType = typename DefType::DimenType;

  constexpr static auto def = definition;

  // Build from arithmetic (i.e. double) value
  constexpr explicit Unit(ValueType input = ValueType(0.0)) noexcept
      : data((input +
              static_cast<ValueType>(OriginType::num) / OriginType::den) *
             DefType::ToSI()){};

  // Build from other unit of same dimension. Zero point is irrelevant.
  // Should be implicit to allow for conversions between units of the same
  // dimension
  constexpr explicit(false) Unit(SameDimensionAs<Unit> auto input) noexcept
      : data(input.data) {}

  // Return magnitude in expected named unit by applying conversion
  [[nodiscard]] constexpr auto Get() const noexcept {
    return (data * DefType::Get()) -
           static_cast<ValueType>(OriginType::num) / OriginType::den;
  }

  // Return magnitude in si, a getter for var data for readability if desired
  // Note: data is public and can be accessed directly
  [[nodiscard]] constexpr auto SI() const noexcept { return data; }

  Data data;  // magnitude in si

  // Unary operator overloads
  constexpr friend auto operator-(Unit lhs) noexcept {
    lhs.data = -1 * lhs.data;
    return lhs;
  }

  // Operator overloads for interactions with arithmetic types
  constexpr auto operator*=(IsArithmetic auto rhs) noexcept -> auto& {
    data *= rhs;
    return *this;
  }

  constexpr friend auto operator*(Unit lhs, IsArithmetic auto rhs) noexcept {
    lhs *= rhs;
    return lhs;
  }

  constexpr friend auto operator*(IsArithmetic auto lhs, Unit rhs) noexcept {
    return rhs * lhs;
  }

  constexpr auto operator/=(IsArithmetic auto rhs) noexcept -> auto& {
    data /= rhs;
    return *this;
  }

  constexpr friend auto operator/(Unit lhs, IsArithmetic auto rhs) noexcept {
    lhs /= rhs;
    return lhs;
  }

  constexpr friend auto operator/(IsArithmetic auto lhs, Unit rhs) noexcept {
    using ResultType = decltype(lhs / rhs.data);
    return Unit<literals::One() / def, ResultType>(lhs / rhs.data);
  }

  // constexpr friend auto operator/(IsArithmetic auto lhs, Unit rhs) noexcept {
  //   return Unit<
  // }

  // Operator overloads for interactions with Units of the same dimension
  // Unit storage ValueType follows from lhs class
  constexpr friend auto operator<=>(
      const Unit& lhs, const SameDimensionAs<Unit> auto& rhs) noexcept
      -> std::strong_ordering {
    return std::strong_order(lhs.data, rhs.data);
  }

  constexpr friend auto operator==(
      const Unit& lhs, const SameDimensionAs<Unit> auto& rhs) noexcept -> bool {
    return lhs.data == rhs.data;
  }

  constexpr auto operator-=(const SameDimensionAs<Unit> auto& rhs) noexcept
      -> auto& {
    data -= rhs.data;
    return *this;
  }

  constexpr friend auto operator-(
      Unit lhs, const SameDimensionAs<Unit> auto& rhs) noexcept {
    lhs -= rhs;
    return lhs;
  }

  constexpr auto operator+=(const SameDimensionAs<Unit> auto& rhs) noexcept
      -> auto& {
    data += rhs.data;
    return *this;
  }

  constexpr friend auto operator+(
      Unit lhs, const SameDimensionAs<Unit> auto& rhs) noexcept {
    lhs += rhs;
    return lhs;
  }

  template <SameDimensionAs<Unit> U>
  constexpr friend auto operator/(Unit lhs, U rhs) noexcept {
    return lhs.data / rhs.data;  // Unitless return since dimensions cancel
  }

  // Operator overloads for interactions with Units of specific relative
  // dimensions
  template <IsUnit U>
    requires std::same_as<typename U::DefType::dim,
                          DimensionFlip<typename DefType::dim>>
  constexpr friend auto operator*(Unit lhs, U rhs) noexcept {
    return lhs.data * rhs.data;  // Unitless return since dimensions cancel
  }

  // Operator overloads for interactions with other Units
  // Unit storage ValueType follows regular c++ promotion rules
  template <IsUnit U>
  constexpr friend auto operator*(Unit lhs, const U& rhs) noexcept {
    using ResultType = decltype(lhs.data * rhs.data);
    auto result = Unit<def * U::def, ResultType>();
    result.data = lhs.data * rhs.data;  // bypass constructor SI cast
    return result;
  }

  template <IsUnit U>
    requires(not SameDimensionAs<Unit, U>)  // Otherwise dimensionless return
  constexpr friend auto operator/(Unit lhs, const U& rhs) noexcept {
    using ResultType = decltype(lhs.data / rhs.data);
    auto result = Unit<def / U::def, ResultType>();
    result.data = lhs.data / rhs.data;  // bypass constructor SI cast
    return result;
  }
};

// Operator overloads for unit construction via Definition class
// They are implemented in this header to avoid a circular dependency with
// definition.hpp
template <IsDefinition DR>
constexpr auto operator*(IsArithmetic auto lhs, DR /*rhs*/) noexcept {
  return Unit<DR{}, decltype(lhs)>(lhs);
}

template <IsUnit U, IsDefinition D>
constexpr auto operator*(U lhs, D rhs) noexcept {
  auto result = Unit<U::def * rhs, typename U::ValueType>();
  result.data = lhs.data;
  return result;
}

template <IsDefinition D>
constexpr auto operator/(IsArithmetic auto lhs, D rhs) noexcept {
  return Unit<literals::One() / rhs, decltype(lhs)>(lhs);
}

template <IsUnit U, IsDefinition D>
constexpr auto operator/(U lhs, D rhs) noexcept {
  auto result = Unit<U::def / rhs, typename U::ValueType>();
  result.data = lhs.data;
  return result;
}

}  // namespace csm_units