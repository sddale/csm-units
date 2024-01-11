/**  \file siemens.hpp
 *   \brief This file is used to define the Conductance SI unit Siemens.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Siemens_(unit)">Siemens</a> if needed.
 */

#pragma once

#include "../../definition.hpp"
#include "../../unit.hpp"
#include "dimension.hpp"

namespace csm_units {

namespace definition {

using Siemens = Definition<Conductance>;

}

using Siemens = Unit<definition::Siemens>;

namespace literals {

constexpr auto S =  // NOLINT(readability-identifier-length)
    Siemens::def;

constexpr auto operator""_S(long double data) noexcept {
  return Siemens(static_cast<Siemens::ValueType>(data));
}

constexpr auto operator""_S(unsigned long long data) noexcept {
  return Siemens(static_cast<Siemens::ValueType>(data));
}

}  // namespace literals

}  // namespace csm_units