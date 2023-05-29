#pragma once

#include "../../unit.hpp"
#include "../../unitcast.hpp"
#include "dimension.hpp"

namespace csm_units {

using SqrCandela = Unit<SqrLuminosity, "cd2", double>;

template <>
[[nodiscard]] constexpr auto UnitCast(SqrLuminosity &&input) noexcept
    -> SqrCandela {
  return SqrCandela(input.data);
}

template <>
[[nodiscard]] constexpr auto UnitCast(SqrCandela &&input) noexcept
    -> SqrLuminosity {
  return SqrLuminosity(input.data);
}

}  // namespace csm_units