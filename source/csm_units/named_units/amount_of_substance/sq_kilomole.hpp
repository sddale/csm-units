/**  \file sqr_kilomole.hpp
 *   \brief This file is used to define the unit Square Kilomole derived from
 * the base dimension for Amount of a Substance.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Mole_(unit)">Mole</a> if
 * needed.
 */

#pragma once

#include "../../definition.hpp"
#include "../../unit.hpp"
#include "dimension.hpp"

namespace csm_units {

namespace definition {

using SqKilomole =
    Definition<SqAmount, NoConv, NoConv, NoConv, NoConv, NoConv, std::kilo>;

}

using SqKilomole = Unit<definition::SqKilomole>;

namespace literals {

constexpr auto kmol2 =  // NOLINT(readability-identifier-length)
    definition::SqKilomole();

constexpr auto operator""_kmol2(long double data) noexcept {
  return SqKilomole(static_cast<SqKilomole::ValueType>(data));
}

constexpr auto operator""_kmol2(unsigned long long data) noexcept {
  return SqKilomole(static_cast<SqKilomole::ValueType>(data));
}

}  // namespace literals

}  // namespace csm_units