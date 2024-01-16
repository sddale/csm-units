#include <doctest/doctest.h>

#include <csm_units/area.hpp>
#include <csm_units/length.hpp>

#include "../common.hpp"

namespace csm_units::test {

// NOLINTBEGIN(modernize-use-trailing-return-type, misc-use-anonymous-namespace)
TEST_SUITE("Named Units") {
  using namespace literals;

  TEST_CASE("Area") {
    SUBCASE("Base unit functionality") {
      // Getters
      CHECK_DBL_EQ(SqMeter(3.).Get(), 3.);
      CHECK_DBL_EQ(SqMeter(3.).data, 3.);

      // Literals
      CHECK_UNIT_EQ(SqMeter(3), 3. * m2);
      CHECK_UNIT_EQ(SqMeter(3), 3_m2);
    }

    SUBCASE("Derived unit conversions and literals") {
      // Square Foot
      CHECK_UNIT_EQ(1_m2, SqFoot(10.7639));
      CHECK_UNIT_EQ(1_m2, 10.7639_ft2);
      CHECK_UNIT_EQ(1_m2, 10.7639 * ft2);
    }

    SUBCASE("Validate derived dimension") {
      CHECK_UNIT_EQ(3_m * 2_m, 6_m2);
      CHECK_UNIT_EQ(3_m * 2_m, 64.5835_ft2);

      CHECK_UNIT_EQ(3_ft * 2_ft, 0.557418_m2);
      CHECK_UNIT_EQ(3_ft * 2_ft, 6_ft2);

      CHECK_UNIT_EQ(3_ft * 2_m, 1.8288_m2);
      CHECK_UNIT_EQ(3_m * 2_ft, 19.6850394_ft2);
    }

    SUBCASE("Misc conversions") {
      // If desired
    }
  }
}
// NOLINTEND(modernize-use-trailing-return-type, misc-use-anonymous-namespace)

}  // namespace csm_units::test