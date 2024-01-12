#pragma once
#include <doctest/doctest.h>

#include <csm_units/concepts.hpp>

#ifndef CSMUNITS_VALUE_TYPE
#define CSMUNITS_VALUE_TYPE double
#endif

namespace csm_units::test {

template <class UL, class UR>
requires SameDimensionAs<UL, UR>
constexpr void CHECK_UNIT_EQ(UL lhs, UR rhs) {
  CHECK_EQ(lhs.data, doctest::Approx(rhs.data).scale(1e-6));
};
constexpr void CHECK_UNIT_NEQ(IsUnit auto lhs,
                              SameDimensionAs<decltype(lhs)> auto rhs) {
  CHECK(lhs.data != doctest::Approx(rhs.data));
};
constexpr void CHECK_DBL_EQ(auto lhs, auto rhs) {
  CHECK_EQ(lhs, doctest::Approx(rhs));
};
constexpr void CHECK_DBL_NEQ(auto lhs, auto rhs) {
  CHECK(lhs != doctest::Approx(rhs));
};

}  // namespace csm_units::test