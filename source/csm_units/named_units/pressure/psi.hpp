/**  \file psi.hpp
 *   \brief This file is used to define the unit Psi derived from the base
 * dimension for Pressure.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Psi">Psi</a> if needed.
 */

#pragma once

#include "../../definition.hpp"
#include "../../unit.hpp"
#include "pascal.hpp"

namespace csm_units {

using PoundForcePerSqInch = Unit<literals::Pa * std::ratio<100, 689476>()>;

namespace literals {

constexpr auto psi =  // NOLINT(readability-identifier-length)
    PoundForcePerSqInch::def;

constexpr auto operator""_psi(long double data) noexcept {
  return PoundForcePerSqInch(static_cast<PoundForcePerSqInch::ValueType>(data));
}

constexpr auto operator""_psi(unsigned long long data) noexcept {
  return PoundForcePerSqInch(static_cast<PoundForcePerSqInch::ValueType>(data));
}

}  // namespace literals

}  // namespace csm_units