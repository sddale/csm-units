/**  \file second.hpp
 *   \brief This file is used to define the Time SI unit Second.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Second">Second</a> if needed.
 */

#pragma once

#include "../../definition.hpp"
#include "../../unit.hpp"
#include "dimension.hpp"

namespace csm_units {

namespace definition {

using Second = Definition<Time>;

}

using Second = Unit<definition::Second>;

namespace literals {

constexpr auto s =  // NOLINT(readability-identifier-length)
    definition::Second();

constexpr auto operator""_s(long double data) noexcept {
  return Second(static_cast<Second::type>(data));
}

constexpr auto operator""_s(unsigned long long data) noexcept {
  return Second(static_cast<Second::type>(data));
}

}  // namespace literals

}  // namespace csm_units
