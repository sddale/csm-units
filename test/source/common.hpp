#pragma once
#include <doctest/doctest.h>

#include <csm_units/concepts.hpp>

#ifndef CSMUNITS_VALUE_TYPE
#define CSMUNITS_VALUE_TYPE double
#endif

namespace csm_units::test {

constexpr void CHECK_UNIT_EQ(IsUnit auto lhs, IsUnit auto rhs) {
  CHECK_EQ(lhs.data, doctest::Approx(rhs.data));
};
constexpr void CHECK_UNIT_NEQ(IsUnit auto lhs, IsUnit auto rhs) {
  CHECK(lhs.data != doctest::Approx(rhs.data));
};
constexpr void CHECK_DBL_EQ(auto lhs, auto rhs) {
  CHECK_EQ(lhs, doctest::Approx(rhs));
};
constexpr void CHECK_DBL_NEQ(auto lhs, auto rhs) {
  CHECK(lhs != doctest::Approx(rhs));
};

}  // namespace csm_units::test