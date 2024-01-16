/**  \file liter.hpp
 *   \brief This file is used to define the unit Liter derived from the base
 * dimension for Volume.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Litre">Liter</a> if needed.
 */

#pragma once

#include "../../definition.hpp"
#include "../../unit.hpp"
#include "cu_meter.hpp"

namespace csm_units {

using Liter = Unit<literals::m3 * std::kilo()>;

namespace literals {

constexpr auto L =  // NOLINT(readability-identifier-length)
    Liter::def;

constexpr auto operator""_L(long double data) noexcept {
  return Liter(static_cast<Liter::ValueType>(data));
}

constexpr auto operator""_L(unsigned long long data) noexcept {
  return Liter(static_cast<Liter::ValueType>(data));
}

}  // namespace literals

}  // namespace csm_units