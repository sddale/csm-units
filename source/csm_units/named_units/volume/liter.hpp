/**  \file liter.hpp
 *   \brief This file is used to define the unit Liter derived from the base
 * dimension for Volume.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Litre">Liter</a> if needed.
 */

#pragma once

#include "../../definition.hpp"
#include "../../unit.hpp"
#include "dimension.hpp"

namespace csm_units {

namespace definition {

using Liter = Definition<Volume, std::deca>;  // Liter = dm3

}

using Liter = Unit<definition::Liter>;

namespace literals {

constexpr auto L =  // NOLINT(readability-identifier-length)
    definition::Liter();

constexpr auto operator""_L(long double data) noexcept {
  return Liter(static_cast<Liter::ValueType>(data));
}

constexpr auto operator""_L(unsigned long long data) noexcept {
  return Liter(static_cast<Liter::ValueType>(data));
}

}  // namespace literals

}  // namespace csm_units