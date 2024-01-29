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
#include "sci_no.hpp"

#ifndef CSMUNITS_VALUE_TYPE
#define CSMUNITS_VALUE_TYPE double
#endif

namespace csm_units {

namespace literals {

using Inv = SciNo<std::ratio<-1>>;
using Zero = SciNo<std::ratio<0>>;
using One = SciNo<std::ratio<1>>;
using Two = SciNo<std::ratio<2>>;
using Three = SciNo<std::ratio<3>>;

}  // namespace literals

template <IsDimension D, IsSciNo ConversionFactor = literals::One,
          IsRatio Origin = std::ratio<0>>
class Definition {
 public:
  using DimenType = D;
  using ConvType = ConversionFactor;
  using OriginType = Origin;

  [[nodiscard]] consteval static auto Get() noexcept {
    return SciNoDecimal<ConvType>;
  }

  [[nodiscard]] consteval static auto ToSI() noexcept {
    return static_cast<CSMUNITS_VALUE_TYPE>(1.0) / SciNoDecimal<ConvType>;
  }

  // Arithmetic helpers
  // Zero point nonsensical for any arithmetic
  template <IsDefinition A>
  using DefinitionMultiply =
      Definition<DimensionAdd<DimenType, typename A::DimenType>,
                 SciNoMultiply<ConvType, typename A::ConvType>>;

  template <IsDefinition A>
  using DefinitionDivide =
      Definition<DimensionSubtract<DimenType, typename A::DimenType>,
                 SciNoDivide<ConvType, typename A::ConvType>>;

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
  return Definition<typename D::DimenType, typename D::ConvType,
                    std::ratio_add<R, typename D::OriginType>>();
}

[[nodiscard]] constexpr auto operator+(IsDefinition auto lhs,
                                       IsRatio auto rhs) noexcept {
  return rhs + lhs;
}

template <IsDefinition D, IsRatio R>
[[nodiscard]] constexpr auto operator-(D /*lhs*/, R /*rhs*/) noexcept {
  return Definition<typename D::DimenType, typename D::ConvType,
                    std::ratio_subtract<typename D::OriginType, R>>();
}

// Operator*,/ with ratio sets conversion factor
template <IsDefinition D, IsConversion C>
[[nodiscard]] constexpr auto operator*(D /*lhs*/, C /*rhs*/) noexcept {
  if constexpr (IsRatio<C>) {
    return Definition<typename D::DimenType,
                      SciNoMultiply<typename D::ConvType, SciNo<C>>>();
  } else {
    return Definition<typename D::DimenType,
                      SciNoMultiply<typename D::ConvType, C>>();
  }
}

[[nodiscard]] constexpr auto operator*(IsConversion auto lhs,
                                       IsDefinition auto rhs) noexcept {
  return rhs * lhs;
}

template <IsDefinition D, IsConversion C>
[[nodiscard]] constexpr auto operator/(D /*lhs*/, C /*rhs*/) noexcept {
  if constexpr (IsRatio<C>) {
    return Definition<typename D::DimenType,
                      SciNoDivide<typename D::ConvType, SciNo<C>>>();
  } else {
    return Definition<typename D::DimenType,
                      SciNoDivide<typename D::ConvType, C>>();
  }
}

template <IsConversion C, IsDefinition D>
[[nodiscard]] constexpr auto operator/(C /*lhs*/, D /*rhs*/) noexcept {
  if constexpr (IsRatio<C>) {
    return Definition<DimensionFlip<typename D::DimenType>,
                      SciNoDivide<SciNo<C>, typename D::ConvType>>();
  } else {
    return Definition<DimensionFlip<typename D::DimenType>,
                      SciNoDivide<C, typename D::ConvType>>();
  }
}

}  // namespace csm_units
