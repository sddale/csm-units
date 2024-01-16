#include <doctest/doctest.h>

#include <csm_units/time.hpp>

#include "../common.hpp"

namespace csm_units::test {

// NOLINTBEGIN(modernize-use-trailing-return-type, misc-use-anonymous-namespace)
TEST_SUITE("Named Units") {
  using namespace literals;

  TEST_CASE("Time") {
    SUBCASE("Base unit functionality") {
      CHECK_DBL_EQ(Second(2.).Get(), 2.);
      CHECK_DBL_EQ(Second(2.).data, 2.);

      // Literals
      CHECK_UNIT_EQ(Second(3), 3_s);
      CHECK_UNIT_EQ(Second(3), 3. * s);
    }

    SUBCASE("Derived unit conversions and literals") {
      CHECK_UNIT_EQ(3600_s, Minute(60));
      CHECK_UNIT_EQ(3600_s, 60_min);
      CHECK_UNIT_EQ(3600_s, 60. * min);

      CHECK_UNIT_EQ(3600_s, Hour(1));
      CHECK_UNIT_EQ(3600_s, 1_hr);
      CHECK_UNIT_EQ(3600_s, 1. * hr);
    }

    SUBCASE("Misc conversions") { CHECK_UNIT_EQ(1_hr, 60_min); }
  }
}
// NOLINTEND(modernize-use-trailing-return-type, misc-use-anonymous-namespace)

}  // namespace csm_units::test