/**  \file gram.hpp
 *   \brief This file is used to define the unit Slug derived from the
 * base dimension for Mass.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Slug_(unit)">Slug</a> if needed.
 */

#pragma once

#include "../../definition.hpp"
#include "../../unit.hpp"
#include "dimension.hpp"

namespace csm_units {

namespace definition {

using Slug = Definition<Mass, NoConv, std::ratio<10000, 145939>>;

}

using Slug = Unit<definition::Slug>;

namespace literals {

constexpr auto slug =  // NOLINT(readability-identifier-length)
    definition::Slug();

constexpr auto operator""_slug(long double data) noexcept {
  return Slug(static_cast<Slug::type>(data));
}

constexpr auto operator""_slug(unsigned long long data) noexcept {
  return Slug(static_cast<Slug::type>(data));
}

}  // namespace literals

}  // namespace csm_units