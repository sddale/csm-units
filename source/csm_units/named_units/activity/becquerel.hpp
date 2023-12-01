/**  \file becquerel.hpp
 *   \brief This file is used to define the Activity of a Radionuclide SI unit
 * Becquerel.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Becquerel">Becquerel</a> if needed.
 */

#pragma once

#include "../../unit.hpp"
#include "dimension.hpp"

namespace csm_units {

using Becquerel = Unit<Activity, "Bq", double>;

// Unit Cast for Base becquerel
template <>
[[nodiscard]] constexpr auto UnitCast(Activity input) noexcept -> Becquerel {
  return Becquerel(input.data);
}

// Unit Cast for Unit becquerel
template <>
[[nodiscard]] constexpr auto UnitCast(Becquerel input) noexcept -> Activity {
  return Activity(input.data);
}

namespace literals {

constexpr auto operator""_Bq(long double data) noexcept {
  return Becquerel(static_cast<double>(data));
}

constexpr auto operator""_Bq(unsigned long long data) noexcept {
  return Becquerel(static_cast<double>(data));
}

}  // namespace literals

}  // namespace csm_units