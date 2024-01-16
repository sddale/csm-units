/**  \file sq_ampere.hpp
 *   \brief This file is used to define the unit Square Ampere derived from the
 * base dimension for Electric Current.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Ampere">Ampere</a> if needed. Square
 * Ampere having a close description to this.
 */
#pragma once

#include "../../definition.hpp"
#include "../../unit.hpp"
#include "ampere.hpp"

namespace csm_units {

using SqAmpere = Unit<literals::A * literals::A>;

namespace literals {

constexpr auto A2 =  // NOLINT(readability-identifier-length)
    SqAmpere::def;

constexpr auto operator""_A2(long double data) noexcept {
  return SqAmpere(static_cast<SqAmpere::ValueType>(data));
}

constexpr auto operator""_A2(unsigned long long data) noexcept {
  return SqAmpere(static_cast<SqAmpere::ValueType>(data));
}

}  // namespace literals

}  // namespace csm_units