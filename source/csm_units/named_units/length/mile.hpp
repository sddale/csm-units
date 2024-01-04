/**  \file mile.hpp
 *   \brief This file is used to define the unit Miles derived from the
 * base dimension for Length.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Mile">Miles</a> if needed.
 */

#pragma once

#include "../../definition.hpp"
#include "../../unit.hpp"
#include "dimension.hpp"

namespace csm_units {

namespace definition {

using Mile = Definition<Length, std::ratio<100, 160934>>;

}

using Mile = Unit<definition::Mile>;

namespace literals {

constexpr auto mi =  // NOLINT(readability-identifier-length)
    definition::Mile();

constexpr auto operator""_mi(long double data) noexcept {
  return Mile(static_cast<Mile::type>(data));
}

constexpr auto operator""_mi(unsigned long long data) noexcept {
  return Mile(static_cast<Mile::type>(data));
}

}  // namespace literals

}  // namespace csm_units