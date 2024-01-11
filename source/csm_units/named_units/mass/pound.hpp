/**  \file gram.hpp
 *   \brief This file is used to define the unit Pound (mass) derived from the
 * base dimension for Mass.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Pound_(mass)">Pound</a> if needed.
 */
#pragma once

#include "../../definition.hpp"
#include "../../unit.hpp"
#include "dimension.hpp"

namespace csm_units {

namespace definition {

using Pound = Definition<Mass, NoConv, std::ratio<220462, 100000>>;

}

using Pound = Unit<definition::Pound>;

namespace literals {

constexpr auto lb =  // NOLINT(readability-identifier-length)
    definition::Pound();

constexpr auto operator""_lb(long double data) noexcept {
  return Pound(static_cast<Pound::ValueType>(data));
}

constexpr auto operator""_lb(unsigned long long data) noexcept {
  return Pound(static_cast<Pound::ValueType>(data));
}

}  // namespace literals

}  // namespace csm_units