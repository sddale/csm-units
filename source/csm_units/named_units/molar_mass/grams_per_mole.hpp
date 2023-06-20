#pragma once

#include "../../unit.hpp"
#include "../../unitcast.hpp"
#include "dimension.hpp"

namespace csm_units {

using GramsPerMol = Unit<MolarMass, "g/mol", double>;

// Unit Cast for Base GramsPerMol
template <>
[[nodiscard]] constexpr auto UnitCast(MolarMass &&input) noexcept
    -> GramsPerMol {
  return GramsPerMol(input.data);
}
template <>
[[nodiscard]] constexpr auto UnitCast(GramsPerMol &&input) noexcept
    -> MolarMass {
  return MolarMass(input.data);
}

namespace literals {

constexpr auto operator""_gpmol(long double data) noexcept {
  return GramsPerMol(static_cast<double>(data));
}

}  // namespace literals

}  // namespace csm_units