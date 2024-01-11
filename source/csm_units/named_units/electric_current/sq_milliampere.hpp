/**  \file sqr_milliampere.hpp
 *   \brief This file is used to define the unit Square Milliammpere derived
 * from the base dimension for Amount of a Substance.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/?title=SqMilliampere&redirect=no">SqMilliampere</a>
 * if needed.
 */

#pragma once

#include "../../definition.hpp"
#include "../../unit.hpp"
#include "dimension.hpp"

namespace csm_units {

namespace definition {

using SqMilliampere =
    Definition<SqElectricCurrent, NoConv, NoConv, NoConv, std::milli>;

}

using SqMilliampere = Unit<definition::SqMilliampere>;

namespace literals {

constexpr auto mA2 =  // NOLINT(readability-identifier-length)
    SqMilliampere::def;

constexpr auto operator""_mA2(long double data) noexcept {
  return SqMilliampere(static_cast<SqMilliampere::ValueType>(data));
}

constexpr auto operator""_mA2(unsigned long long data) noexcept {
  return SqMilliampere(static_cast<SqMilliampere::ValueType>(data));
}

}  // namespace literals

}  // namespace csm_units