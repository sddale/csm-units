/**  \file definition.hpp
 *   \brief This file defines a more verbose version of user defined definition.
 *
 * Allows for the combination of user defined literal with different binary
 * arithmetic operators to create a unit from scratch. Then defining a decimal
 * number with that unit.
 */

#pragma once

#include <csm_units/concepts.hpp>
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
  [[nodiscard]] constexpr auto operator*(DR /*rhs*/) const noexcept {
    if constexpr (std::same_as<DimenType,
                               DimensionFlip<typename DR::DimenType>>) {
      return static_cast<CSMUNITS_VALUE_TYPE>(1.0);
    } else {
      return DefinitionMultiply<DR>();
    }
  }

  template <IsDefinition DR>
  [[nodiscard]] constexpr auto operator/(DR /*rhs*/) const noexcept {
    if constexpr (std::same_as<DimenType, typename DR::DimenType>) {
      return static_cast<CSMUNITS_VALUE_TYPE>(1.0);
    } else {
      return DefinitionDivide<DR>();
    }
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

}  // namespace csm_units
