/**  \file katal.hpp
 *   \brief This file is used to define the Absorbed Dose SI unit Katal.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Katal">Katal</a> if needed.
 */

#pragma once

#include "../../definition.hpp"
#include "../../unit.hpp"
#include "dimension.hpp"

namespace csm_units {

namespace definition {

using Katal = Definition<CatalyticActivity>;

}

using Katal = Unit<definition::Katal>;

namespace literals {

constexpr auto kat =  // NOLINT(readability-identifier-length)
    definition::Katal();

constexpr auto operator""_kat(long double data) noexcept {
  return Katal(static_cast<Katal::type>(data));
}

constexpr auto operator""_kat(unsigned long long data) noexcept {
  return Katal(static_cast<Katal::type>(data));
}

}  // namespace literals

}  // namespace csm_units