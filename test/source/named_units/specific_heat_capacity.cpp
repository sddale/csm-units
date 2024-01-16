#include <doctest/doctest.h>

#include <csm_units/length.hpp>
#include <csm_units/specific_heat_capacity.hpp>
#include <csm_units/temperature.hpp>
#include <csm_units/time.hpp>

#include "../common.hpp"

namespace csm_units::test {

// NOLINTBEGIN(modernize-use-trailing-return-type, misc-use-anonymous-namespace)
TEST_SUITE("Named Units") {
  using namespace literals;

  TEST_CASE("Specific Heat Capacity") {
    SUBCASE("Base unit functionality") {
      // Getters
      CHECK_DBL_EQ(JoulesPerKilogramKelvin(1.).Get(), 1.);
      CHECK_DBL_EQ(JoulesPerKilogramKelvin(1.).data, 1.);

      // Literals
      CHECK_UNIT_EQ(JoulesPerKilogramKelvin(1.), 1.0_JperkgK);
      CHECK_UNIT_EQ(JoulesPerKilogramKelvin(1.), 1.0 * JperkgK);
    }

    SUBCASE("Validate derived dimension") {
      CHECK_UNIT_EQ(1_m * 2_m / (5_s * 4_s * 2_K), 0.05_JperkgK);
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