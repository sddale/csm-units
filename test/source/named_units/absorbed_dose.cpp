#include <doctest/doctest.h>

#include <csm_units/absorbed_dose.hpp>
#include <csm_units/length.hpp>
#include <csm_units/time.hpp>

#include "../common.hpp"

namespace csm_units::test {

// NOLINTBEGIN(modernize-use-trailing-return-type, misc-use-anonymous-namespace)
TEST_SUITE("Named Units") {
  using namespace literals;

  TEST_CASE("Absorbed Dose") {
    SUBCASE("Base unit functionality") {
      // Getters
      CHECK_DBL_EQ(Gray(1.).Get(), 1.);
      CHECK_DBL_EQ(Gray(1.).data, 1.);

      // Literals
      CHECK_UNIT_EQ(Gray(1.), 1.0_Gy);
      CHECK_UNIT_EQ(Gray(1.), 1.0 * Gy);
    }

    SUBCASE("Validate derived dimension") {
      CHECK_UNIT_EQ(3_m * 2_ft / (8_s * 1_min), 0.00381_Gy);
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