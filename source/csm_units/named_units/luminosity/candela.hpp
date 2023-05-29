#pragma once

#include "../../unit.hpp"
#include "../../unitcast.hpp"
#include "dimension.hpp"

namespace csm_units {

using Candela = Unit<Luminosity, "cd", double>;

// Unit Cast for Unit Candela
template <>
[[nodiscard]] constexpr auto UnitCast(Luminosity &&input) noexcept -> Candela {
  return Candela(input.data);
}

// Unit Cast for Unit Candela
template <>
[[nodiscard]] constexpr auto UnitCast(Candela &&input) noexcept -> Luminosity {
  return Luminosity(input.data);
}

}  // namespace csm_units