/**  \file unitcast.hpp
 *   \brief This file defines the function declaration for the UnitCast
 * function.
 *
 * The UnitCast function explains how to convert from a derived unit to the base
 * unit in SI. This should be created in the manner explained in the unit.hpp
 * file.
 */

#pragma once

#include <csm_units/concepts.hpp>

#include "util.hpp"

namespace csm_units {

template <class DST, class SRC>
[[nodiscard]] constexpr auto UnitCast(SRC&& /*input*/) noexcept -> DST;

}  // namespace csm_units