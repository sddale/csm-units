#pragma once

#include <csm_units/concepts.hpp>

#include "util.hpp"

namespace csm_units {

template <class DST, class SRC>
[[nodiscard]] constexpr auto UnitCast(SRC&& /*input*/) noexcept -> DST;

}  // namespace csm_units