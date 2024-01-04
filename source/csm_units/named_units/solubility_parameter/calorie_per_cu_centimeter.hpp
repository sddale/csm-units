/**  \file cal_per_cubic_cm.hpp
 *   \brief This file is used to define the unit cal / cm^3 derived from the
 * base dimension for Square Solubility Parameter.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Hildebrand_solubility_parameter">cal /
 * cm^3</a> if needed.
 */

// TODO monolithic conversions

// #pragma once

// #include "../../unit.hpp"
// #include "dimension.hpp"

// namespace csm_units {

// using CalPerCubicCM = Unit<SqrSolubilityParameter, "cal/cm^3">;

// // Unit Cast for base m3
// template <>
// [[nodiscard]] constexpr auto UnitCast(SqrSolubilityParameter &&input)
// noexcept
//     -> CalPerCubicCM {
//   return CalPerCubicCM(input.data * 2.39006E-7);
// }

// // Unit Cast for Unit m3
// template <>
// [[nodiscard]] constexpr auto UnitCast(CalPerCubicCM &&input) noexcept
//     -> SqrSolubilityParameter {
//   return SqrSolubilityParameter(input.data / 2.39006E-7);
// }

// }  // namespace csm_units
