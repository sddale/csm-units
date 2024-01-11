/**  \file ampere.hpp
 *   \brief This file is used to define the Electric Current SI unit Ampere.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Ampere">Ampere</a> if needed.
 */

#pragma once

#include "../../definition.hpp"
#include "../../unit.hpp"
#include "dimension.hpp"

namespace csm_units {

namespace definition {

using Ampere = Definition<ElectricCurrent>;

}

using Ampere = Unit<definition::Ampere>;

namespace literals {

constexpr auto A =  // NOLINT(readability-identifier-length)
    Ampere::def;

constexpr auto operator""_A(long double data) noexcept {
  return Ampere(static_cast<Ampere::ValueTypeeType>(data));
}

constexpr auto operator""_A(unsigned long long data) noexcept {
  return Ampere(static_cast<Ampere::ValueTypeeType>(data));
}

}  // namespace literals

}  // namespace csm_units
