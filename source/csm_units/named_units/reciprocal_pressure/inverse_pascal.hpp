/**  \file pascal.hpp
 *   \brief This file is used to define the Inverse Pressure base unit Inverse
 * Pascal.
 *
 */

#pragma once

#include "../../definition.hpp"
#include "../../unit.hpp"
#include "dimension.hpp"

namespace csm_units {

namespace definition {

using InversePascal = Definition<ReciprocalPressure>;

}

using InversePascal = Unit<definition::InversePascal>;

namespace literals {

constexpr auto invPa =  // NOLINT(readability-identifier-length)
    definition::InversePascal();

constexpr auto operator""_invPa(long double data) noexcept {
  return InversePascal(static_cast<InversePascal::ValueType>(data));
}

constexpr auto operator""_invPa(unsigned long long data) noexcept {
  return InversePascal(static_cast<InversePascal::ValueType>(data));
}

}  // namespace literals

}  // namespace csm_units