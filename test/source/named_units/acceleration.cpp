#include <doctest/doctest.h>

#include <csm_units/acceleration.hpp>
#include <csm_units/length.hpp>
#include <csm_units/time.hpp>

#include "../common.hpp"

namespace csm_units::test {

// NOLINTBEGIN(modernize-use-trailing-return-type, misc-use-anonymous-namespace)
TEST_SUITE("Named Units") {
  using namespace literals;

  TEST_CASE("Acceleration") {
    SUBCASE("Base unit functionality") {
      // Getters
      CHECK_DBL_EQ(MetersPerSqSecond(1.).Get(), 1.);
      CHECK_DBL_EQ(MetersPerSqSecond(1.).data, 1.);

      // Literals
      CHECK_UNIT_EQ(MetersPerSqSecond(1.), 1.0_mps2);
      CHECK_UNIT_EQ(MetersPerSqSecond(1.), 1.0 * mps2);
    }

    SUBCASE("Validate derived dimension") {
      CHECK_UNIT_EQ(3_m / (8_s * 1_min), 0.00625_mps2);
    }

    SUBCASE("Derived unit conversions and literals") {
      // None Yet
    }

    SUBCASE("Misc conversions") {
      // Not Desired
    }
  }
}
// NOLINTEND(modernize-use-trailing-return-type, misc-use-anonymous-namespace)

}  // namespace csm_units::test