/**  \file inch.hpp
 *   \brief This file is used to define the unit Inch derived from the
 * base dimension for Length.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Inch">Inch</a> if needed.
 */

#pragma once

#include "../../definition.hpp"
#include "../../unit.hpp"
#include "dimension.hpp"

namespace csm_units {

namespace definition {

using Inch = Definition<Length, std::ratio<393701, 10000>>;

}

using Inch = Unit<definition::Inch>;

namespace literals {

constexpr auto in =  // NOLINT(readability-identifier-length)
    definition::Inch();

constexpr auto operator""_in(long double data) noexcept {
  return Inch(static_cast<Inch::ValueType>(data));
}

constexpr auto operator""_in(unsigned long long data) noexcept {
  return Inch(static_cast<Inch::ValueType>(data));
}

}  // namespace literals

}  // namespace csm_units