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
#include "pound.hpp"

namespace csm_units {

using Slug = Unit<literals::lb * std::ratio<100000, 3217405>()>;

namespace literals {

constexpr auto slug =  // NOLINT(readability-identifier-length)
    Slug::def;

constexpr auto operator""_slug(long double data) noexcept {
  return Slug(static_cast<Slug::ValueType>(data));
}

constexpr auto operator""_slug(unsigned long long data) noexcept {
  return Slug(static_cast<Slug::ValueType>(data));
}

}  // namespace literals

}  // namespace csm_units