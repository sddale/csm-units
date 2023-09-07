/**  \file meter.hpp
 *   \brief This file is used to define the Length SI unit Meter.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Metre">Meter</a> if needed.
 */

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

namespace literals {

// length - meter
constexpr auto operator""_m(long double data) noexcept {
  return Meter(static_cast<double>(data));
}

constexpr auto operator""_m(unsigned long long data) noexcept {
  return Meter(static_cast<double>(data));
}

}  // namespace literals

}  // namespace csm_units