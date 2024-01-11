/**  \file gray.hpp
 *   \brief This file is used to define the Absorbed Dose SI unit Gray.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Gray_(unit)">Gray</a> if needed.
 */

#pragma once

#include "../../definition.hpp"
#include "../../unit.hpp"
#include "dimension.hpp"

namespace csm_units {

namespace definition {

using AbsorbedDose = Definition<AbsorbedDose>;

}

using Gray = Unit<definition::AbsorbedDose>;

namespace literals {

constexpr auto Gy  // NOLINT(readability-identifier-length)
    = definition::AbsorbedDose();

constexpr auto operator""_Gy(long double data) noexcept {
  return Gray(static_cast<Gray::ValueType>(data));
}

constexpr auto operator""_Gy(unsigned long long data) noexcept {
  return Gray(static_cast<Gray::ValueType>(data));
}

}  // namespace literals

}  // namespace csm_units