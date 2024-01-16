#include <doctest/doctest.h>

#include <csm_units/illuminance.hpp>
#include <csm_units/length.hpp>
#include <csm_units/luminosity.hpp>

#include "../common.hpp"

namespace csm_units::test {

// NOLINTBEGIN(modernize-use-trailing-return-type, misc-use-anonymous-namespace)
TEST_SUITE("Named Units") {
  using namespace literals;

  TEST_CASE("Illuminance") {
    SUBCASE("Base unit functionality") {
      // Getters
      CHECK_DBL_EQ(Lux(1.).Get(), 1.);
      CHECK_DBL_EQ(Lux(1.).data, 1.);

      // Literals
      CHECK_UNIT_EQ(Lux(1.), 1.0_lx);
      CHECK_UNIT_EQ(Lux(1.), 1.0 * lx);
    }

    SUBCASE("Validate derived dimension") {
      CHECK_UNIT_EQ(1_cd / (2_m * 4_m), 0.125_lx);
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