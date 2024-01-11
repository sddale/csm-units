/**  \file ohm.hpp
 *   \brief This file is used to define the Resistance SI unit Ohm.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Ohm">Ohm</a> if needed.
 */

#pragma once

#include "../../definition.hpp"
#include "../../unit.hpp"
#include "dimension.hpp"

namespace csm_units {

namespace definition {

using Ohm = Definition<Resistance>;

}

using Ohm = Unit<definition::Ohm>;

namespace literals {

constexpr auto ohm =  // NOLINT(readability-identifier-length)
    Ohm::def;

constexpr auto operator""_ohm(long double data) noexcept {
  return Ohm(static_cast<Ohm::ValueType>(data));
}

constexpr auto operator""_ohm(unsigned long long data) noexcept {
  return Ohm(static_cast<Ohm::ValueType>(data));
}

}  // namespace literals

}  // namespace csm_units