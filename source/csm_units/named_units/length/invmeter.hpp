/**  \file invmeter.hpp
 *   \brief This file is used to define the unit Inverse Meters derived from the
 * base dimension for Length.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Reciprocal_length#:~:text=Reciprocal%20length%20or%20inverse%20length,symbol%3A%20cm%E2%88%921).">Inverse
 * Meters</a> if needed.
 */

#pragma once

#include "../../unit.hpp"
#include "dimension.hpp"

namespace csm_units {

using InvMeter = Unit<InvLength, "inv_m">;

// Unit Cast for Base invlength to Unit invm
template <>
[[nodiscard]] constexpr auto UnitCast(InvLength &&input) noexcept -> InvMeter {
  return InvMeter(input.data);
}

// Unit Cast for Unit invm to Base invlength
template <>
[[nodiscard]] constexpr auto UnitCast(InvMeter &&input) noexcept -> InvLength {
  return InvLength(input.data);
}

}  // namespace csm_units