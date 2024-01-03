/**  \file joule.hpp
 *   \brief This file is used to define the Energy SI unit Joule.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Joule">Joule</a> if needed.
 */

#pragma once

#include "../../definition.hpp"
#include "../../unit.hpp"
#include "dimension.hpp"

namespace csm_units {

namespace definition {

using Joule = Definition<Energy>;

}

using Joule = Unit<definition::Joule>;

namespace literals {

constexpr auto J =  // NOLINT(readability-identifier-length)
    definition::Joule();

constexpr auto operator""_J(long double data) noexcept {
  return Joule(static_cast<Joule::type>(data));
}

constexpr auto operator""_J(unsigned long long data) noexcept {
  return Joule(static_cast<Joule::type>(data));
}

}  // namespace literals

}  // namespace csm_units