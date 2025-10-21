#include <csm_units/units.hpp>

using base_alias = UnitBase<
    Dimension<Length_Numerator, Mass_Numerator, Time_Numerator,
              Current_Numerator, Thermodynamic_Temperature_Numerator,
              Amount_Of_A_Substance_Numerator, Luminous_Intensity_Numerator,
              Length_Denominator, Mass_Denominator, Time_Denominator,
              Current_Denominator, Thermodynamic_Temperature_Denominator,
              Amount_Of_A_Substance_Denominator,
              Luminous_Intensity_Denominator>,
    underlying_data_type>;

using unit_alias =
    Unit<defined_base_dimension, "unit_code", underlying_data_type>;

template <>
[[nodiscard]] constexpr auto UnitCast(base_alias&& input) noexcept
    -> unit_alias {
  return alias(equation);
}

template <>
[[nodiscard]] constexpr auto UnitCast(unit_alias&& input) noexcept
    -> base_alias {
  return base_alias(equation);
}