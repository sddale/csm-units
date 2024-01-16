#include <doctest/doctest.h>

#include <csm_units/length.hpp>
#include <csm_units/time.hpp>
#include <csm_units/velocity.hpp>

#include "../common.hpp"

namespace csm_units::test {

// NOLINTBEGIN(modernize-use-trailing-return-type, misc-use-anonymous-namespace)
TEST_SUITE("Named Units") {
  using namespace literals;

  TEST_CASE("Velocity") {
    SUBCASE("Base unit functionality") {
      // Getters
      CHECK_DBL_EQ(MeterPerSecond(1.).Get(), 1.);
      CHECK_DBL_EQ(MeterPerSecond(1.).data, 1.);

      // Literals
      CHECK_UNIT_EQ(MeterPerSecond(1.), 1.0_mps);
      CHECK_UNIT_EQ(MeterPerSecond(1.), 1.0 * mps);
    }

    SUBCASE("Validate derived dimension") { CHECK_UNIT_EQ(1_m / 2_s, 0.5_mps); }

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