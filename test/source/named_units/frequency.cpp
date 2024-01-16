#include <doctest/doctest.h>

#include <csm_units/frequency.hpp>
#include <csm_units/time.hpp>

#include "../common.hpp"

namespace csm_units::test {

// NOLINTBEGIN(modernize-use-trailing-return-type, misc-use-anonymous-namespace)
TEST_SUITE("Named Units") {
  using namespace literals;

  TEST_CASE("Frequency") {
    SUBCASE("Base unit functionality") {
      // Getters
      CHECK_DBL_EQ(Hertz(1.).Get(), 1.);
      CHECK_DBL_EQ(Hertz(1.).data, 1.);

      // Literals
      CHECK_UNIT_EQ(Hertz(1.), 1.0_Hz);
      CHECK_UNIT_EQ(Hertz(1.), 1.0 * Hz);
    }

    SUBCASE("Validate derived dimension") { CHECK_UNIT_EQ(1 / (2_s), 0.5_Hz); }

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