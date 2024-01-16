#include <doctest/doctest.h>

#include <csm_units/length.hpp>
#include <csm_units/mass.hpp>
#include <csm_units/pressure.hpp>
#include <csm_units/time.hpp>

#include "../common.hpp"

namespace csm_units::test {

// NOLINTBEGIN(modernize-use-trailing-return-type, misc-use-anonymous-namespace)
TEST_SUITE("Named Units") {
  using namespace literals;

  TEST_CASE("Pressure") {
    SUBCASE("Base unit functionality") {
      // Getters
      CHECK_DBL_EQ(Pascal(3.).Get(), 3.);
      CHECK_DBL_EQ(Pascal(3.).data, 3.);

      // Literals
      CHECK_UNIT_EQ(Pascal(3), 3. * Pa);
      CHECK_UNIT_EQ(Pascal(3), 3_Pa);
    }

    SUBCASE("Derived unit conversions and literals") {
      // Bar
      CHECK_UNIT_EQ(1_Pa, Bar(1e-5));
      CHECK_UNIT_EQ(1_Pa, 1e-5_bar);
      CHECK_UNIT_EQ(1_Pa, 1e-5 * bar);

      // Psi
      CHECK_UNIT_EQ(1_Pa, PoundForcePerSqInch(1.45038e-4));
      CHECK_UNIT_EQ(1_Pa, 1.45038e-4_psi);
      CHECK_UNIT_EQ(1_Pa, 1.45038e-4 * psi);

      // Standard Atmosphere
      CHECK_UNIT_EQ(101325_Pa, StandardAtmosphere(1));
      CHECK_UNIT_EQ(101325_Pa, 1_atm);
      CHECK_UNIT_EQ(101325_Pa, 1 * atm);
      CHECK_UNIT_EQ(101325_Pa, 1. * atm);
    }

    SUBCASE("Validate derived dimension") {
      CHECK_UNIT_EQ(64_kg / 2_m / 8_s / 2_s, 2_Pa);
    }

    SUBCASE("Misc conversions") {
      // If desired
    }
  }
}
// NOLINTEND(modernize-use-trailing-return-type, misc-use-anonymous-namespace)

}  // namespace csm_units::test