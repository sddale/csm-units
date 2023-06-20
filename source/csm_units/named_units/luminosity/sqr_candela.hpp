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

namespace literals {

constexpr auto operator""_cd2(long double data) noexcept {
  return SqrCandela(static_cast<double>(data));
}

}  // namespace literals

}  // namespace csm_units