#include <doctest/doctest.h>

#include <csm_units/electric_current.hpp>
#include <csm_units/length.hpp>
#include <csm_units/magnetic_flux_density.hpp>
#include <csm_units/mass.hpp>
#include <csm_units/time.hpp>

#include "../common.hpp"

namespace csm_units::test {

// NOLINTBEGIN(modernize-use-trailing-return-type, misc-use-anonymous-namespace)
TEST_SUITE("Named Units") {
  using namespace literals;

  TEST_CASE("Magnetic Flux Density") {
    SUBCASE("Base unit functionality") {
      // Getters
      CHECK_DBL_EQ(Tesla(1.).Get(), 1.);
      CHECK_DBL_EQ(Tesla(1.).data, 1.);

      // Literals
      CHECK_UNIT_EQ(Tesla(1.), 1.0_T);
      CHECK_UNIT_EQ(Tesla(1.), 1.0 * T);
    }

    SUBCASE("Validate derived dimension") {
      CHECK_UNIT_EQ(2_kg * 3_A / (1_m * 4_s * 5_s), 0.3_T);
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