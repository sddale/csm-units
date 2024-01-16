#include <doctest/doctest.h>

#include <csm_units/capacitance.hpp>
#include <csm_units/electric_current.hpp>
#include <csm_units/length.hpp>
#include <csm_units/mass.hpp>
#include <csm_units/time.hpp>

#include "../common.hpp"

namespace csm_units::test {

// NOLINTBEGIN(modernize-use-trailing-return-type, misc-use-anonymous-namespace)
TEST_SUITE("Named Units") {
  using namespace literals;

  TEST_CASE("Capacitance") {
    SUBCASE("Base unit functionality") {
      // Getters
      CHECK_DBL_EQ(Farad(1.).Get(), 1.);
      CHECK_DBL_EQ(Farad(1.).data, 1.);

      // Literals
      CHECK_UNIT_EQ(Farad(1.), 1.0_F);
      CHECK_UNIT_EQ(Farad(1.), 1.0 * F);
    }

    SUBCASE("Validate derived dimension") {
      CHECK_UNIT_EQ(1_s * 2_s * 3_s * 4_s * 5_A * 6_A / (7_m * 8_m * 9_kg),
                    1.428571429_F);
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