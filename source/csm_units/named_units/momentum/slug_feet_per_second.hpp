/**  \file slug_feet_per_second.hpp
 *   \brief This file is used to define the unit Slug Feet Per Second derived
 * from the base dimension for Momentum.
 *
 */

#pragma once

#include "../../definition.hpp"
#include "../../unit.hpp"
#include "../length/foot.hpp"
#include "../mass/slug.hpp"
#include "../time/second.hpp"

namespace csm_units {

using SlugFeetPerSecond = Unit<literals::slug * literals::ft / literals::s>;

namespace literals {

constexpr auto slugftpers =  // NOLINT(readability-identifier-length)
    SlugFeetPerSecond::def;

constexpr auto operator""_slugftpers(long double data) noexcept {
  return SlugFeetPerSecond(static_cast<SlugFeetPerSecond::ValueType>(data));
}

constexpr auto operator""_slugftpers(unsigned long long data) noexcept {
  return SlugFeetPerSecond(static_cast<SlugFeetPerSecond::ValueType>(data));
}

}  // namespace literals

}  // namespace csm_units