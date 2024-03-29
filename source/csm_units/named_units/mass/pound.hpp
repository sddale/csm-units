/**  \file pound.hpp
 *   \brief This file is used to define the unit Pound (mass) derived from the
 * base dimension for Mass.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Pound_(mass)">Pound</a> if needed.
 */
#pragma once

#include "../../definition.hpp"
#include "../../unit.hpp"
#include "kilogram.hpp"

namespace csm_units {

using Pound = Unit<literals::kg * std::ratio<220462, 100000>()>;

namespace literals {

constexpr auto lb =  // NOLINT(readability-identifier-length)
    Pound::def;

constexpr auto operator""_lb(long double data) noexcept {
  return Pound(static_cast<Pound::ValueType>(data));
}

constexpr auto operator""_lb(unsigned long long data) noexcept {
  return Pound(static_cast<Pound::ValueType>(data));
}

}  // namespace literals

}  // namespace csm_units