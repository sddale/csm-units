#include <doctest/doctest.h>

#include <csm_units/area.hpp>
#include <csm_units/energy.hpp>
#include <csm_units/mass.hpp>
#include <csm_units/time.hpp>

#include "../common.hpp"

namespace csm_units::test {

// NOLINTBEGIN(modernize-use-trailing-return-type, misc-use-anonymous-namespace)
TEST_SUITE("Named Units") {
  using namespace literals;

  TEST_CASE("Time") {
    SUBCASE("Base unit functionality") {
      // Getters
      CHECK_DBL_EQ(Joule(1.).Get(), 1.);
      CHECK_DBL_EQ(Joule(1.).data, 1.);

      // Literals
      CHECK_UNIT_EQ(Joule(1.), 1.0_J);
      CHECK_UNIT_EQ(Joule(1.), 1.0 * J);
    }

    SUBCASE("Validate derived dimension") {
      CHECK_UNIT_EQ(3_kg * 2_m2 / (8_s * s), 0.75_J);
    }

    SUBCASE("Derived unit conversions and literals") {
      // BTU
      CHECK_UNIT_EQ(1.0_J, BritishThermalUnit(0.000947817));
      CHECK_UNIT_EQ(1.0_J, 0.000947817_BTU);
      CHECK_UNIT_EQ(1.0_J, 0.000947817 * BTU);
      CHECK_UNIT_EQ(1.0_J, 0.000947817_Btu);
      CHECK_UNIT_EQ(1.0_J, 0.000947817 * Btu);

      // Calorie
      CHECK_UNIT_EQ(4.184_J, Calorie(1.0));
      CHECK_UNIT_EQ(4.184_J, 1.0_cal);
      CHECK_UNIT_EQ(4.184_J, 1.0 * cal);
    }

    SUBCASE("Misc conversions") {
      // If desired
      CHECK_UNIT_EQ(1.0_BTU, 1055.06_J);
      CHECK_UNIT_EQ(3_BTU * 2_J / 3_BTU, 2_J);
      CHECK_DBL_EQ(2.0_BTU / 3_J, 703.37);
    }
  }
}
// NOLINTEND(modernize-use-trailing-return-type, misc-use-anonymous-namespace)

}  // namespace csm_units::test