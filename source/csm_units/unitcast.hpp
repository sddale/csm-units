#pragma once

#include <csm_units/concepts.hpp>

#include "util.hpp"

// #include "unitbase.hpp"

namespace csm_units {

template <class DST, class SRC>
constexpr auto UnitCast(SRC /*input*/) -> DST;

}  // namespace csm_units