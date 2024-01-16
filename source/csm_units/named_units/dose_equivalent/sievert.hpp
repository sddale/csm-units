/**  \file sievert.hpp
 *   \brief This file is used to define the Dose Equivalent SI unit Sievert.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Sievert">Sievert</a> if needed.
 */
#pragma once

#include "../../definition.hpp"
#include "../../unit.hpp"
#include "dimension.hpp"

namespace csm_units {

using Sievert = Unit<Definition<DoseEquivalent>{}>;

namespace literals {

constexpr auto Sv =  // NOLINT(readability-identifier-length)
    Sievert::def;

constexpr auto operator""_Sv(long double data) noexcept {
  return Sievert(static_cast<Sievert::ValueType>(data));
}

constexpr auto operator""_Sv(unsigned long long data) noexcept {
  return Sievert(static_cast<Sievert::ValueType>(data));
}

}  // namespace literals

}  // namespace csm_units