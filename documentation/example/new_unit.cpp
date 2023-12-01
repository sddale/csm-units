#include <csm_units/units.hpp>

using alias = Unit<defined_base_dimension, "unit_code", underlying_data_type>;

template <>
[[nodiscard]] constexpr auto UnitCast(defined_base_dimension input) noexcept
    -> alias {
  return alias(equation);
}

template <>
[[nodiscard]] constexpr auto UnitCast(alias input) noexcept
    -> defined_base_dimension {
  return defined_base_dimension(equation);
}