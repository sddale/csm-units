#include <doctest/doctest.h>

#include <csm_units/dose_equivalent.hpp>
#include <csm_units/length.hpp>
#include <csm_units/time.hpp>

#include "../common.hpp"

namespace csm_units::test {

// NOLINTBEGIN(modernize-use-trailing-return-type, misc-use-anonymous-namespace)
TEST_SUITE("Named Units") {
  using namespace literals;

  TEST_CASE("Dose Equivalent") {
    SUBCASE("Base unit functionality") {
      // Getters
      CHECK_DBL_EQ(Sievert(1.).Get(), 1.);
      CHECK_DBL_EQ(Sievert(1.).data, 1.);

      // Literals
      CHECK_UNIT_EQ(Sievert(1.), 1.0_Sv);
      CHECK_UNIT_EQ(Sievert(1.), 1.0 * Sv);
    }

    SUBCASE("Validate derived dimension") {
      CHECK_UNIT_EQ(1_m * 2_m / (2_s * 4_s), 0.25_Sv);
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