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
// #include <ostream>

// #include "unitcast.hpp"
// #include "util.hpp"

#ifndef CSMUNITS_VALUE_TYPE
#define CSMUNITS_VALUE_TYPE double
#endif

namespace csm_units {

using concepts::Arithmetic;
using concepts::ExpType;

template <concepts::Unit U, concepts::Ratio ZeroPoint>
class RelativeUnit : public U {
 public:
  constexpr explicit RelativeUnit(U::type data)
      : U(data + static_cast<U::type>(ZeroPoint::num) / ZeroPoint::den) {}

  [[nodiscard]] constexpr auto Get() const {
    return U::Get() - static_cast<U::type>(ZeroPoint::num) / ZeroPoint::den;
  }
  // [[nodiscard]] constexpr auto SI() const {
  //   return U::SI() + static_cast<U::type>(ZeroPoint::num) / ZeroPoint::den;
  // }
};

template <concepts::Definition Def, Arithmetic Data = CSMUNITS_VALUE_TYPE>
class Unit {
 public:
  using def = Def;
  using type = Data;

  constexpr explicit Unit(Data input) : data(input * def::ToSI()){};

  template <concepts::SameDimAs<Unit> U>
  constexpr explicit(false) Unit(U input) : data(input.data) {}

  [[nodiscard]] constexpr auto Get() const { return data * Def::Get(); }
  [[nodiscard]] constexpr auto SI() const { return data; }

  Data data;  // magnitude in si

  template <concepts::SameDimAs<Unit> U>
  constexpr friend auto operator<=>(const Unit& lhs, const U& rhs) noexcept
      -> std::strong_ordering {
    return std::strong_order(lhs.data, rhs.data);
  }
  template <concepts::SameDimAs<Unit> U>
  constexpr friend auto operator==(const Unit& lhs, const U& rhs) noexcept
      -> bool {
    return lhs.data == rhs.data;
  }

  constexpr auto operator-=(const Unit& rhs) noexcept -> auto& {
    data -= rhs.data;
    return *this;
  }
  constexpr friend auto operator-(Unit lhs) noexcept {
    lhs.data = -1 * lhs.data;
    return lhs;
  }
  template <concepts::SameDimAs<Unit> U>
  constexpr friend auto operator-(U lhs, const U& rhs) noexcept {
    lhs -= rhs;
    return lhs;
  }

  constexpr auto operator+=(const Unit& rhs) noexcept -> auto& {
    data += rhs.data;
    return *this;
  }

  template <concepts::SameDimAs<Unit> U>
  constexpr friend auto operator+(U lhs, const U& rhs) noexcept {
    lhs += rhs;
    return lhs;
  }

  template <concepts::Ratio... Converters>
  constexpr friend auto operator*(
      Unit lhs,
      Unit<Definition<ExponentsFlip<typename def::dim>, Converters...>, Data>
          rhs) noexcept {
    return lhs.data * rhs.data;
  }
  template <concepts::Unit U>
  constexpr friend auto operator*(Unit lhs, const U& rhs) noexcept {
    return Unit<typename Unit::def::template Muliply<typename U::def>, Data>(
        lhs.data * rhs.data);
  }
  constexpr auto operator*=(Arithmetic auto rhs) noexcept -> auto& {
    data *= rhs;
    return *this;
  }
  constexpr friend auto operator*(Unit lhs, Arithmetic auto rhs) noexcept {
    lhs *= rhs;
    return lhs;
  }

  template <concepts::Ratio... Converters>
  constexpr friend auto operator/(
      Unit lhs,
      Unit<Definition<typename def::dim, Converters...>, Data> rhs) noexcept {
    return lhs.data / rhs.data;
  }
  template <concepts::Unit U>
  constexpr friend auto operator/(Unit lhs, const U& rhs) noexcept {
    return Unit<typename Unit::def::template Divide<typename U::def>, Data>(
        lhs.data / rhs.data);
  }
  constexpr auto operator/=(Arithmetic auto rhs) noexcept -> auto& {
    data /= rhs;
    return *this;
  }
  constexpr friend auto operator/(Unit lhs, Arithmetic auto rhs) noexcept {
    lhs /= rhs;
    return lhs;
  }
};

template <concepts::Definition D>
constexpr auto operator*(Arithmetic auto lhs, D /*rhs*/) {
  return Unit<D, decltype(lhs)>(lhs);
}
template <concepts::Definition DL, concepts::Definition DR>
constexpr auto operator*(DL /*lhs*/, DR /*rhs*/) {
  return Unit<typename DR::template Multiply<DL>>(1.0);
}
template <concepts::Unit U, concepts::Definition D>
constexpr auto operator*(U lhs, D /*rhs*/) {
  return Unit<typename D::template Multiply<typename U::def>, typename U::type>(
      lhs.data);
}
template <concepts::Definition D>
constexpr auto operator/(Arithmetic auto lhs, D /*rhs*/) {
  return Unit<typename D::InverseDef, decltype(lhs)>(lhs);
}
template <concepts::Definition DL, concepts::Definition DR>
constexpr auto operator/(DL /*lhs*/, DR /*rhs*/) {
  return Unit<typename DR::template Divide<DL>>(1.0);
}
template <concepts::Unit U, concepts::Definition D>
constexpr auto operator/(U lhs, D /*rhs*/) {
  return Unit<typename D::template Divide<typename U::def>, typename U::type>(
      lhs.data);
}

}  // namespace csm_units