/**  \file milliampere.hpp
 *   \brief This file is used to define the unit Milliampere derived from the
 * base dimension for Electric Current.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/?title=Milliampere&redirect=no">Milliampere</a>
 * if needed.
 */
#pragma once

#include "../../definition.hpp"
#include "../../unit.hpp"
#include "ampere.hpp"

namespace csm_units {

using Milliampere = Unit<literals::A / std::milli()>;

namespace literals {

constexpr auto mA =  // NOLINT(readability-identifier-length)
    Milliampere::def;

constexpr auto operator""_mA(long double data) noexcept {
  return Milliampere(static_cast<Milliampere::ValueType>(data));
}

constexpr auto operator""_mA(unsigned long long data) noexcept {
  return Milliampere(static_cast<Milliampere::ValueType>(data));
}

}  // namespace literals

}  // namespace csm_units