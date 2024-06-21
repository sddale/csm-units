#include <doctest/doctest.h>

#include <csm_units/concepts.hpp>
#include <csm_units/units.hpp>
#include <source/csm_units/definition.hpp>
#include <source/csm_units/dimension.hpp>
#include <source/csm_units/unit.hpp>

#include "common.hpp"

#ifndef CSMUNITS_VALUE_TYPE
#define CSMUNITS_VALUE_TYPE double
#endif

namespace csm_units::test {

// NOLINTBEGIN(modernize-use-trailing-return-type, misc-use-anonymous-namespace)

TEST_SUITE("Definition") {
  using namespace csm_units::literals;
  using length_def = Definition<DimensionInt<1>>;
  using inv_def = decltype(One() / length_def());
  using area_def = decltype(length_def() * length_def());
  using dimensionless = decltype(length_def() / length_def());
  TEST_CASE("Construction via operator*") {
    static_assert(
        std::is_same_v<length_def::DimenType, Dimension<std::ratio<1>>>);
    static_assert(
        std::is_same_v<area_def::DimenType, Dimension<std::ratio<2>>>);
    static_assert(std::is_same_v<dimensionless, CSMUNITS_VALUE_TYPE>);
    static_assert(
        std::is_same_v<decltype(area_def() / length_def()), length_def>);
    static_assert(std::is_same_v<decltype(length_def() / area_def()), inv_def>);
  }
  TEST_CASE("Binary operations") {
    CHECK_UNIT_EQ(12_Jpermol, 36_J / 3_mol);
    CHECK_DBL_EQ(300., 300._bar / bar);
    CHECK_UNIT_EQ(100_m2, 0.1_km * 1._m);
  }
}

// NOLINTEND(modernize-use-trailing-return-type, misc-use-anonymous-namespace)

}  // namespace csm_units::test