#pragma once

#include "../../unit.hpp"
#include "../../unitcast.hpp"
#include "dimension.hpp"

namespace csm_units {

using Meter = Unit<Length, "m", double>;

// Unit cast for Base m to Unit m
template <>
[[nodiscard]] constexpr auto UnitCast(Length &&input) noexcept -> Meter {
  return Meter(input.data);
}

// Unit Cast for Unit m to Base m
template <>
[[nodiscard]] constexpr auto UnitCast(Meter &&input) noexcept -> Length {
  return Length(input.data);
}

// length - meter
constexpr auto operator""_m(long double data) noexcept {
  return Meter(static_cast<double>(data));
}

}  // namespace csm_units