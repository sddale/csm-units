#pragma once

#include "../../unit.hpp"
#include "../../unitcast.hpp"
#include "dimension.hpp"

namespace csm_units {

using Katal = Unit<CatalyticActivity, "kat", double>;

// Unit Cast for Base katal
template <>
[[nodiscard]] constexpr auto UnitCast(CatalyticActivity &&input) noexcept
    -> Katal {
  return Katal(input.data);
}

// Unit Cast for Unit katal
template <>
[[nodiscard]] constexpr auto UnitCast(Katal &&input) noexcept
    -> CatalyticActivity {
  return CatalyticActivity(input.data);
}

}  // namespace csm_units