#pragma once

#include "../../unit.hpp"
#include "../../unitcast.hpp"
#include "dimension.hpp"

namespace csm_units {

using Hertz = Unit<Frequency, "Hz", double>;

// Unit Cast for Base hertz
template <>
[[nodiscard]] constexpr auto UnitCast(Frequency &&input) noexcept -> Hertz {
  return Hertz(input.data);
}

// Unit Cast for Unit hertz
template <>
[[nodiscard]] constexpr auto UnitCast(Hertz &&input) noexcept -> Frequency {
  return Frequency(input.data);
}

constexpr auto operator""_Hz(long double data) noexcept {
  return Hertz(static_cast<double>(data));
}

}  // namespace csm_units