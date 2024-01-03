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
#include "dimension.hpp"

namespace csm_units {

namespace definition {

using Milliampere = Definition<ElectricCurrent, std::ratio<1>, std::ratio<1>,
                               std::ratio<1>, std::milli>;

}

using Milliampere = Unit<definition::Milliampere>;

namespace literals {

constexpr auto mA =  // NOLINT(readability-identifier-length)
    definition::Milliampere();

constexpr auto operator""_mA(long double data) noexcept {
  return Milliampere(static_cast<Milliampere::type>(data));
}

constexpr auto operator""_mA(unsigned long long data) noexcept {
  return Milliampere(static_cast<Milliampere::type>(data));
}

}  // namespace literals

}  // namespace csm_units