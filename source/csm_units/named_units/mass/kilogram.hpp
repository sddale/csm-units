/**  \file kilogram.hpp
 *   \brief This file is used to define the Mass SI unit Kilogram.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Kilogram">Kilogram</a> if needed.
 */

#pragma once

#include "../../definition.hpp"
#include "../../unit.hpp"
#include "dimension.hpp"

namespace csm_units {

namespace definition {

using Kilogram = Definition<Mass>;

}

using Kilogram = Unit<definition::Kilogram>;

namespace literals {

constexpr auto kg =  // NOLINT(readability-identifier-length)
    definition::Kilogram();

constexpr auto operator""_kg(long double data) noexcept {
  return Kilogram(static_cast<Kilogram::ValueType>(data));
}

constexpr auto operator""_kg(unsigned long long data) noexcept {
  return Kilogram(static_cast<Kilogram::ValueType>(data));
}

}  // namespace literals

}  // namespace csm_units