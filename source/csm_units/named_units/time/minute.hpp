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
#include "second.hpp"

namespace csm_units {

using Minute = Unit<literals::s * std::ratio<1, 60>()>;

namespace literals {

constexpr auto min =  // NOLINT(readability-identifier-length)
    Minute::definition;

constexpr auto operator""_min(long double data) noexcept {
  return Minute(static_cast<Minute::ValueType>(data));
}

constexpr auto operator""_min(unsigned long long data) noexcept {
  return Minute(static_cast<Minute::ValueType>(data));
}

}  // namespace literals

}  // namespace csm_units