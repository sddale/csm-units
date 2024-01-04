/**  \file centimeter.hpp
 *   \brief This file is used to define the unit Centimeter derived from the
 * base dimension for Length.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Centimetre#">Centimeter</a> if needed.
 */

#pragma once

#include "../../definition.hpp"
#include "../../unit.hpp"
#include "dimension.hpp"

namespace csm_units {

namespace definition {

using Centimeter = Definition<Length, std::centi>;

}

using Centimeter = Unit<definition::Centimeter>;

namespace literals {

constexpr auto cm =  // NOLINT(readability-identifier-length)
    definition::Centimeter();

constexpr auto operator""_cm(long double data) noexcept {
  return Centimeter(static_cast<Centimeter::type>(data));
}

constexpr auto operator""_cm(unsigned long long data) noexcept {
  return Centimeter(static_cast<Centimeter::type>(data));
}

}  // namespace literals

}  // namespace csm_units
