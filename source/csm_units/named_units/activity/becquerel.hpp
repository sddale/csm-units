/**  \file becquerel.hpp
 *   \brief This file is used to define the Activity of a Radionuclide SI unit
 * Becquerel.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Becquerel">Becquerel</a> if needed.
 */

#pragma once

#include "../../definition.hpp"
#include "../../unit.hpp"
#include "dimension.hpp"

namespace csm_units {

using Becquerel = Unit<Definition<Activity>{}>;

namespace literals {

constexpr auto Bq =  // NOLINT(readability-identifier-length)
    Becquerel::def;

constexpr auto operator""_Bq(long double data) noexcept {
  return Becquerel(static_cast<Becquerel::ValueType>(data));
}

constexpr auto operator""_Bq(unsigned long long data) noexcept {
  return Becquerel(static_cast<Becquerel::ValueType>(data));
}

}  // namespace literals

}  // namespace csm_units
