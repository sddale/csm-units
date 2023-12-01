/**  \file unitcast.hpp
 *   \brief This file defines the function declaration for the UnitCast
 * function.
 *
 * The UnitCast function explains how to convert from a derived unit to the base
 * unit in SI.
 *
 * Below are instructions for adding a new unit that is in a dimension that is
 * already provided. The form for everything explained below can be seen in the
 * example code shown below.
 *
 * 1.) Create the new unit inside of a using statement. The alias of the using
 * statement can be anything that would help you know what the unit is. The new
 * units code should be something that is unique to that unit and would not be
 * used by any other unit. It is important that the code is not used by any
 * other unit already. The underlying data type is the data type that you want
 * the unit to store in under the hood.
 *
 * 2.) Make a unit cast from the already defined base dimenion to the new unit
 * where the equation is how you would get from the source unit to the
 * destination unit.
 *
 * 3.) Make a second unit cast that goes the other direction. That is from the
 * the new unit to the base dimension.
 *
 * \include new_unit.cpp
 *
 * Below are instructions for adding a new unit that is in a new dimension. The
 * form for everything explained below can be seen in the example code shown
 * below.
 *
 * 1.) Create the new base dimension where the power of each dimension type is
 * listed inside of exponents. The first seven integers are the numerators for
 * each dimension and last seven integers are the denominators for each
 * dimension. If all of the dimensions you are using only have an integer power
 * then only the first seven integers for the numerators need to be defined. The
 * denominators are defaulted to 1.
 *
 * 2.) Create the new unit inside of a using statement. The alias of the using
 * statement can be anything that would help you know what the unit is. The base
 * dimension should be the alias in the using statement that you just defined.
 * The new units code should be something that is unique to that unit and would
 * not be used by any other unit. It is important that the code is not used by
 * any other unit already. The underlying data type is the data type that you
 * want the unit to store in under the hood.
 *
 * 3.) Make a unit cast from the already defined base dimenion to the new unit
 * where the equation is how you would get from the source unit to the
 * destination unit.
 *
 * 4.) Make a second unit cast that goes the other direction. That is from the
 * the new unit to the base dimension.
 *
 * \include new_unit_and_base.cpp
 *
 */

#pragma once

#include <csm_units/concepts.hpp>

namespace csm_units {

template <class DST, class SRC>
[[nodiscard]] constexpr auto UnitCast(SRC /*input*/) noexcept -> DST;

}  // namespace csm_units