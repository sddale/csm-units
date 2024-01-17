/**  \file math.hpp
 *   \brief This file defines simple math functions on Unit objects
 */

#pragma once

#include <csm_units/concepts.hpp>

namespace csm_units {

// Square a unit and return a new unit
using csm_units::IsUnit;
[[nodiscard]] constexpr auto UnitSquare(IsUnit auto unit) noexcept {
  return unit * unit;
}

// Cube a unit and return a new unit
[[nodiscard]] constexpr auto UnitCube(IsUnit auto unit) noexcept {
  return unit * unit * unit;
}

}  // namespace csm_units