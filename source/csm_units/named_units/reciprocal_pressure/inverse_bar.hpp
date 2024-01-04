/**  \file bar.hpp
 *   \brief This file is used to define the unit Inverse Bar derived from the
 * base dimension for Inverse Pressure.
 *
 */

// TODO monolithic conversions

// #pragma once

// #include "../../unit.hpp"
// #include "dimension.hpp"

// namespace csm_units {

// using InvBar = Unit<InvPressure, "inv_bar">;

// // Unit Cast for Base Pascals to Unit InvBar
// // Conversion Equation: 1 InvBar = 100,000 pascals
// template <>
// [[nodiscard]] constexpr auto UnitCast(InvPressure &&input) noexcept -> InvBar
// {
//   return InvBar(input.data * 100000);
// }

// // Unit Cast for Unit InvBar to Base Pascals
// // Conversion Equation: 1 InvBar = 100,000 pascals
// template <>
// [[nodiscard]] constexpr auto UnitCast(InvBar &&input) noexcept -> InvPressure
// {
//   return InvPressure(input.data / 100000);
// }

// }  // namespace csm_units