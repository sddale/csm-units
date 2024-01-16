/**  \file calorie.hpp
 *   \brief This file is used to define the Calorie
 * from the base dimension for Energy.
 *
 *   The following Encyclopedia Britannica page can explain <a
 * href="https://www.britannica.com/science/calorie">Calorie</a> if needed.
 */

#pragma once

#include "../../definition.hpp"
#include "../../unit.hpp"
#include "joule.hpp"

namespace csm_units {

using Calorie = Unit<literals::J / std::ratio<21, 5>()>;

namespace literals {

constexpr auto Cal =  // NOLINT(readability-identifier-length)
    Calorie::def;

constexpr auto operator""_Cal(long double data) noexcept {
  return Calorie(static_cast<Calorie::ValueType>(data));
}

constexpr auto operator""_Cal(unsigned long long data) noexcept {
  return Calorie(static_cast<Calorie::ValueType>(data));
}

}  // namespace literals

}  // namespace csm_units