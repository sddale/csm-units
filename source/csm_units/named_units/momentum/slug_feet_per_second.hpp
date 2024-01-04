/**  \file slug_feet_per_second.hpp
 *   \brief This file is used to define the unit Slug Feet Per Second derived
 * from the base dimension for Momentum.
 *
 */

#pragma once

#include "../../definition.hpp"
#include "../../unit.hpp"
#include "dimension.hpp"

namespace csm_units {

namespace definition {

using SlugFeetPerSecond =
    Definition<Momentum, std::ratio<82021, 25000>, std::ratio<10000, 145939>>;

}

using SlugFeetPerSecond = Unit<definition::SlugFeetPerSecond>;

namespace literals {

constexpr auto slugftpers =  // NOLINT(readability-identifier-length)
    definition::SlugFeetPerSecond();

constexpr auto operator""_slugftpers(long double data) noexcept {
  return SlugFeetPerSecond(static_cast<SlugFeetPerSecond::type>(data));
}

constexpr auto operator""_slugftpers(unsigned long long data) noexcept {
  return SlugFeetPerSecond(static_cast<SlugFeetPerSecond::type>(data));
}

}  // namespace literals

}  // namespace csm_units