#include <doctest/doctest.h>

#include <csm_units/length.hpp>

#include "../common.hpp"

namespace csm_units::test {

// NOLINTBEGIN(modernize-use-trailing-return-type, misc-use-anonymous-namespace)
TEST_SUITE("Named Units") {
  using namespace literals;
  TEST_CASE("Length") {
    CHECK_DBL_EQ(Meter(3.).Get(), 3.);
    CHECK_DBL_EQ(Meter(3.).data, 3.);

    CHECK_DBL_EQ(Millimeter(3000.).data, 3);
    CHECK_DBL_EQ(Millimeter(3000.).Get(), 3000);

    CHECK_UNIT_EQ(10_mm, 1_cm);
    CHECK_UNIT_EQ(1.0e6_mm, 1_km);
    CHECK_UNIT_EQ(0.3048_m, 1_ft);
    CHECK_UNIT_EQ(1_yd, 3_ft);
    CHECK_UNIT_EQ(1_yd, 36_in);
    CHECK_UNIT_EQ(1_mi, 5280_ft);
  }
}
// NOLINTEND(modernize-use-trailing-return-type, misc-use-anonymous-namespace)

}  // namespace csm_units::test