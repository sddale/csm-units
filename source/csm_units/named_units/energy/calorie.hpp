/**  \file calorie.hpp
 *   \brief This file is used to define the small calorie
 * from the base dimension for Energy.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Calorie">calorie</a> if needed.
 */

#pragma once

#include "../../definition.hpp"
#include "../../unit.hpp"
#include "joule.hpp"

namespace csm_units {

using Calorie = Unit<literals::J / std::ratio<523, 125>()>;

namespace literals {

constexpr auto cal =  // NOLINT(readability-identifier-length)
    Calorie::def;

constexpr auto operator""_cal(long double data) noexcept {
  return Calorie(static_cast<Calorie::ValueType>(data));
}

constexpr auto operator""_cal(unsigned long long data) noexcept {
  return Calorie(static_cast<Calorie::ValueType>(data));
}

}  // namespace literals

}  // namespace csm_units