/**  \file invmeter.hpp
 *   \brief This file is used to define the unit Inverse Meters derived from the
 * base dimension for Length.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Reciprocal_length#:~:text=Reciprocal%20length%20or%20inverse%20length,symbol%3A%20cm%E2%88%921).">Inverse
 * Meters</a> if needed.
 */

#pragma once

#include "../../definition.hpp"
#include "../../unit.hpp"
#include "dimension.hpp"

namespace csm_units {

namespace definition {

using InverseMeter = Definition<ReciprocalLength>;

}

using InverseMeter = Unit<definition::InverseMeter>;

namespace literals {

constexpr auto invm =  // NOLINT(readability-identifier-length)
    definition::InverseMeter();

constexpr auto operator""_invm(long double data) noexcept {
  return InverseMeter(static_cast<InverseMeter::type>(data));
}

constexpr auto operator""_invm(unsigned long long data) noexcept {
  return InverseMeter(static_cast<InverseMeter::type>(data));
}

}  // namespace literals

}  // namespace csm_units