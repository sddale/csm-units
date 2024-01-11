/**  \file millimeter.hpp
 *   \brief This file is used to define the unit Millimeter derived from the
 * base dimension for Length.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Millimetre">Millimeter</a> if needed.
 */

#pragma once

#include "../../definition.hpp"
#include "../../unit.hpp"
#include "dimension.hpp"

namespace csm_units {

namespace definition {

using Millimeter = Definition<Length, std::milli>;

}

using Millimeter = Unit<definition::Millimeter>;

namespace literals {

constexpr auto mm =  // NOLINT(readability-identifier-length)
    definition::Millimeter();

constexpr auto operator""_mm(long double data) noexcept {
  return Millimeter(static_cast<Millimeter::ValueType>(data));
}

constexpr auto operator""_mm(unsigned long long data) noexcept {
  return Millimeter(static_cast<Millimeter::ValueType>(data));
}

}  // namespace literals

}  // namespace csm_units