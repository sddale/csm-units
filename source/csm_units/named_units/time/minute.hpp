/**  \file minute.hpp
 *   \brief This file is used to define the unit Minute derived from the base
 * dimension for Time.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Minute">Minute</a> if needed.
 */

#pragma once

#include "../../definition.hpp"
#include "../../unit.hpp"
#include "dimension.hpp"

namespace csm_units {

namespace definition {

using Minute = Definition<Time, NoConv, NoConv, std::ratio<1, 60>>;

}

using Minute = Unit<definition::Minute>;

namespace literals {

constexpr auto min =  // NOLINT(readability-identifier-length)
    definition::Minute();

constexpr auto operator""_min(long double data) noexcept {
  return Minute(static_cast<Minute::type>(data));
}

constexpr auto operator""_min(unsigned long long data) noexcept {
  return Minute(static_cast<Minute::type>(data));
}

}  // namespace literals

}  // namespace csm_units