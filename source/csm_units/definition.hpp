/**  \file definition.hpp
 *   \brief This file defines a more verbose version of user defined definition.
 *
 * Allows for the combination of user defined literal with different binary
 * arithmetic operators to create a unit from scratch. Then defining a decimal
 * number with that unit.
 */

#pragma once

#include <csm_units/concepts.hpp>
#include <gcem.hpp>
#include <ratio>

#include "dimension.hpp"

#ifndef CSMUNITS_VALUE_TYPE
#define CSMUNITS_VALUE_TYPE double
#endif

namespace csm_units {

namespace literals {

using Inv = std::ratio<-1>;
using Zero = std::ratio<0>;
using One = std::ratio<1>;
using Two = std::ratio<2>;
using Three = std::ratio<3>;

}  // namespace literals

template <IsDimension D, IsRatio ConversionFactor = literals::One,
          IsRatio Origin = literals::Zero>
class Definition {
 public:
  using DimenType = D;
  using ConvType = ConversionFactor;
  using OriginType = Origin;

  [[nodiscard]] consteval static auto Get() noexcept {
    return static_cast<CSMUNITS_VALUE_TYPE>(ConvType::num) / ConvType::den;
  }

  [[nodiscard]] consteval static auto ToSI() noexcept {
    return static_cast<CSMUNITS_VALUE_TYPE>(ConvType::den) / ConvType::num;
  }

  // Arithmetic helpers
  // Zero point nonsensical for any arithmetic
  template <IsDefinition A>
  using DefinitionMultiply =
      Definition<DimensionAdd<DimenType, typename A::DimenType>,
                 std::ratio_multiply<ConvType, typename A::ConvType>>;

  template <IsDefinition A>
  using DefinitionDivide =
      Definition<DimensionSubtract<DimenType, typename A::DimenType>,
                 std::ratio_divide<ConvType, typename A::ConvType>>;

  using DefinitionInvert = Definition<DimensionFlip<DimenType>,
                                      std::ratio<ConvType::den, ConvType::num>>;

  template <IsDefinition DR>
    requires std::same_as<DimenType, DimensionFlip<typename DR::DimenType>>
  [[nodiscard]] constexpr auto operator*(DR /*rhs*/) const noexcept {
    return CSMUNITS_VALUE_TYPE();
  }

  template <IsDefinition DR>
  [[nodiscard]] constexpr auto operator*(DR /*rhs*/) const noexcept {
    return DefinitionMultiply<DR>();
  }

  template <IsDefinition DR>
    requires std::same_as<DimenType, typename DR::DimenType>
  [[nodiscard]] constexpr auto operator/(DR /*rhs*/) const noexcept {
    return CSMUNITS_VALUE_TYPE();
  }

  template <IsDefinition DR>
  [[nodiscard]] constexpr auto operator/(DR /*rhs*/) const noexcept {
    return DefinitionDivide<DR>();
  }
};

// Operator+,- with ratio sets Origin
// Operator+ is symmetric, operator- with def rhs not supported due to
// potentially unintuitive arithmetic
template <IsRatio R, IsDefinition D>
[[nodiscard]] constexpr auto operator+(R /*lhs*/, D /*rhs*/) noexcept {
  return Definition<typename D::DimenType, typename D::ConvType, R>();
}

template <IsDefinition D, IsRatio R>
[[nodiscard]] constexpr auto operator+(D /*lhs*/, R /*rhs*/) noexcept {
  return Definition<typename D::DimenType, typename D::ConvType, R>();
}

template <IsDefinition D, IsRatio R>
[[nodiscard]] constexpr auto operator-(D /*lhs*/, R /*rhs*/) noexcept {
  return Definition<typename D::DimenType, typename D::ConvType,
                    std::ratio<-1 * R::num, R::den>>();
}

// Operator*,/ with ratio sets conversion factor
template <IsDefinition D, IsRatio R>
[[nodiscard]] constexpr auto operator*(D /*lhs*/, R /*rhs*/) noexcept {
  return Definition<typename D::DimenType,
                    std::ratio_multiply<typename D::ConvType, R>>();
}

template <IsRatio R, IsDefinition D>
[[nodiscard]] constexpr auto operator*(R /*lhs*/, D /*rhs*/) noexcept {
  return Definition<typename D::DimenType,
                    std::ratio_multiply<R, typename D::ConvType>>();
}

template <IsDefinition D, IsRatio R>
[[nodiscard]] constexpr auto operator/(D /*lhs*/, R /*rhs*/) noexcept {
  return Definition<typename D::DimenType,
                    std::ratio_divide<typename D::ConvType, R>>();
}

template <IsRatio R, IsDefinition D>
[[nodiscard]] constexpr auto operator/(R /*lhs*/, D /*rhs*/) noexcept {
  return Definition<DimensionFlip<typename D::DimenType>,
                    std::ratio_divide<R, typename D::ConvType>>();
}

namespace literals {
// NOLINTBEGIN(readability-identifier-length)

// constexpr auto Gy = Definition<Dimension<2, 0, -2, 0, 0, 0, 0>>();
// constexpr auto Bq = Definition<Dimension<0, 0, -1, 0, 0, 0, 0>>();
// constexpr auto mol = Definition<Dimension<0, 0, 0, 0, 0, 1, 0>>();
// constexpr auto mol2 = Definition<Dimension<0, 0, 0, 0, 0, 2, 0>>();
// constexpr auto m2 = Definition<Dimension<2, 0, 0, 0, 0, 0, 0>>();
// constexpr auto F = Definition<Dimension<-2, -1, 4, 2, 0, 0, 0>>();
// constexpr auto kat = Definition<Dimension<0, 0, -1, 0, 0, 1, 0>>();
// constexpr auto S = Definition<Dimension<-2, -1, 3, 2, 0, 0, 0>>();
// constexpr auto kgperm3 = Definition<Dimension<-3, 1, 0, 0, 0, 0, 0>>();
// constexpr auto kgmpers = Definition<Dimension<1, 1, -1, 0, 0, 0, 0>>();
// constexpr auto Sv = Definition<Dimension<2, 0, -2, 0, 0, 0, 0>>();
// constexpr auto C = Definition<Dimension<0, 0, 1, 1, 0, 0, 0>>();
// constexpr auto A = Definition<Dimension<0, 0, 0, 1, 0, 0, 0>>();
// constexpr auto A2 = Definition<Dimension<0, 0, 0, 2, 0, 0, 0>>();
// constexpr auto J = Definition<Dimension<2, 1, -2, 0, 0, 0, 0>>();
// constexpr auto N = Definition<Dimension<1, 1, -2, 0, 0, 0, 0>>();
// constexpr auto Hz = Definition<Dimension<0, 0, -1, 0, 0, 0, 0>>();
// constexpr auto lx = Definition<Dimension<-2, 0, 0, 0, 0, 0, 1>>();
// constexpr auto H = Definition<Dimension<1, 1, -2, 0, 0, 0, 0>>();
// constexpr auto m = Definition<Dimension<1, 0, 0, 0, 0, 0, 0>>();
// constexpr auto inv_m = Definition<Dimension<-1, 0, 0, 0, 0, 0, 0>>();
// constexpr auto cd = Definition<Dimension<0, 0, 0, 0, 0, 0, 1>>();
// constexpr auto cd2 = Definition<Dimension<0, 0, 0, 0, 0, 0, 2>>();
// constexpr auto lm = Definition<Dimension<0, 0, 0, 0, 0, 0, 1>>();
// constexpr auto Wb = Definition<Dimension<1, 1, -2, 1, 0, 0, 0>>();
// constexpr auto T = Definition<Dimension<-1, 1, -2, 1, 0, 0, 0>>();
// constexpr auto kg = Definition<Dimension<0, 1, 0, 0, 0, 0, 0>>();
// constexpr auto V = Definition<Dimension<2, 1, -3, -1, 0, 0, 0>>();
// constexpr auto W = Definition<Dimension<2, 1, -3, 0, 0, 0, 0>>();
// constexpr auto Pa = Definition<Dimension<-1, 1, -2, 0, 0, 0, 0>>();
// constexpr auto Pa2 = Definition<Dimension<-2, 2, -4, 0, 0, 0, 0>>();
// constexpr auto Pa3 = Definition<Dimension<-3, 3, -6, 0, 0, 0, 0>>();
// constexpr auto Pa4 = Definition<Dimension<-4, 4, -8, 0, 0, 0, 0>>();
// constexpr auto ohm = Definition<Dimension<2, 1, -3, -2, 0, 0, 0>>();
// constexpr auto K = Definition<Dimension<0, 0, 0, 0, 1, 0, 0>>();
// constexpr auto K2 = Definition<Dimension<0, 0, 0, 0, 2, 0, 0>>();
// constexpr auto K3 = Definition<Dimension<0, 0, 0, 0, 3, 0, 0>>();
// constexpr auto K4 = Definition<Dimension<0, 0, 0, 0, 4, 0, 0>>();
// constexpr auto m3 = Definition<Dimension<3, 0, 0, 0, 0, 0, 0>>();

// NOLINTEND(readability-identifier-length)

// constexpr auto mps = m / s;
// constexpr auto mps2 = m / s / s;

}  // namespace literals

}  // namespace csm_units