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

using Kilogram = Unit<Definition<Mass>{}>;

namespace literals {

constexpr auto kg =  // NOLINT(readability-identifier-length)
    Kilogram::def;

constexpr auto operator""_kg(long double data) noexcept {
  return Kilogram(static_cast<Kilogram::ValueType>(data));
}

constexpr auto operator""_kg(unsigned long long data) noexcept {
  return Kilogram(static_cast<Kilogram::ValueType>(data));
}

}  // namespace literals

}  // namespace csm_units