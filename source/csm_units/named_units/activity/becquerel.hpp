#pragma once

#include "../../unit.hpp"
#include "../../unitcast.hpp"
#include "dimension.hpp"

namespace csm_units {

using Becquerel = Unit<Activity, "Bq", double>;

// Unit Cast for Base becquerel
template <>
[[nodiscard]] constexpr auto UnitCast(Activity &&input) noexcept -> Becquerel {
  return Becquerel(input.data);
}

// Unit Cast for Unit becquerel
template <>
[[nodiscard]] constexpr auto UnitCast(Becquerel &&input) noexcept -> Activity {
  return Activity(input.data);
}

constexpr auto operator""_Bq(long double data) noexcept {
  return Becquerel(static_cast<double>(data));
}

}  // namespace csm_units