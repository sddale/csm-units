/**  \file yard.hpp
 *   \brief This file is used to define the unit Yards derived from the
 * base dimension for Length.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Yard">Yards</a> if needed.
 */

#pragma once

#include "../../definition.hpp"
#include "../../unit.hpp"
#include "dimension.hpp"

namespace csm_units {

namespace definition {

using Yard = Definition<Length, std::ratio<109361, 100000>>;

}

using Yard = Unit<definition::Yard>;

namespace literals {

constexpr auto yd =  // NOLINT(readability-identifier-length)
    definition::Yard();

constexpr auto operator""_yd(long double data) noexcept {
  return Yard(static_cast<Yard::type>(data));
}

constexpr auto operator""_yd(unsigned long long data) noexcept {
  return Yard(static_cast<Yard::type>(data));
}

}  // namespace literals

}  // namespace csm_units