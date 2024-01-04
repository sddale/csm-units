/**  \file kilometer.hpp
 *   \brief This file is used to define the unit Kilometer derived from the
 * base dimension for Length.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Kilometre">Kilometer</a> if needed.
 */

#pragma once

#include "../../definition.hpp"
#include "../../unit.hpp"
#include "dimension.hpp"

namespace csm_units {

namespace definition {

using Kilometer = Definition<Length, std::kilo>;

}

using Kilometer = Unit<definition::Kilometer>;

namespace literals {

constexpr auto km =  // NOLINT(readability-identifier-length)
    definition::Kilometer();

constexpr auto operator""_km(long double data) noexcept {
  return Kilometer(static_cast<Kilometer::type>(data));
}

constexpr auto operator""_km(unsigned long long data) noexcept {
  return Kilometer(static_cast<Kilometer::type>(data));
}

}  // namespace literals

}  // namespace csm_units