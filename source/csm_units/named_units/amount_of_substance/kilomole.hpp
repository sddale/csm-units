/**  \file kilomole.hpp
 *   \brief This file is used to define the unit Kilomole derived from the base
 * dimension for Amount of a Substance.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Mole_(unit)">Mole</a> if needed.
 */

#pragma once

#include "../../definition.hpp"
#include "../../unit.hpp"
#include "dimension.hpp"

namespace csm_units {

namespace definition {

using Kilomole = Definition<Amount, std::ratio<1>, std::ratio<1>, std::ratio<1>,
                            std::ratio<1>, std::ratio<1>, std::kilo>;

}

using Kilomole = Unit<definition::Kilomole>;

namespace literals {

constexpr auto kmol =  // NOLINT(readability-identifier-length)
    definition::Kilomole();

constexpr auto operator""_kmol(long double data) noexcept {
  return Kilomole(static_cast<Kilomole::type>(data));
}

constexpr auto operator""_kmol(unsigned long long data) noexcept {
  return Kilomole(static_cast<Kilomole::type>(data));
}

}  // namespace literals

}  // namespace csm_units