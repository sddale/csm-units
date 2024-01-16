#include <doctest/doctest.h>

#include <csm_units/energy.hpp>
#include <csm_units/solubility_parameter.hpp>
#include <csm_units/volume.hpp>

#include "../common.hpp"

namespace csm_units::test {

// NOLINTBEGIN(modernize-use-trailing-return-type, misc-use-anonymous-namespace)
TEST_SUITE("Named Units") {
  using namespace literals;

  TEST_CASE("Solubility Parameter") {
    SUBCASE("Base unit functionality") {
      // Getters
      CHECK_DBL_EQ(JoulesPerCuMeter(3.).Get(), 3.);
      CHECK_DBL_EQ(JoulesPerCuMeter(3.).data, 3.);
      CHECK_DBL_EQ(SqrtJoulesPerSqrtCuMeter(3.).Get(), 3.);
      CHECK_DBL_EQ(SqrtJoulesPerSqrtCuMeter(3.).data, 3.);

      // Literals
      CHECK_UNIT_EQ(JoulesPerCuMeter(3), 3. * Jperm3);
      CHECK_UNIT_EQ(JoulesPerCuMeter(3), 3_Jperm3);
      CHECK_UNIT_EQ(SqrtJoulesPerSqrtCuMeter(3), 3. * SqrtJperSqrtm3);
      CHECK_UNIT_EQ(SqrtJoulesPerSqrtCuMeter(3), 3_SqrtJperSqrtm3);
    }

    SUBCASE("Derived unit conversions and literals") {
      // Calories Per Cubic Centimeter
      CHECK_UNIT_EQ(1_Jperm3, CaloriesPerCuCM(2.390057361E-7));
      CHECK_UNIT_EQ(1_Jperm3, 2.390057361E-7_calpercm3);
      CHECK_UNIT_EQ(1_Jperm3, 2.390057361E-7 * calpercm3);
    }

    SUBCASE("Validate derived dimension") {
      CHECK_UNIT_EQ(3_SqrtJperSqrtm3 * 2_SqrtJperSqrtm3, 6_Jperm3);
      CHECK_UNIT_EQ(6_J / 2_m3, 3_Jperm3);
      CHECK_UNIT_EQ(4_SqrtJperSqrtm3 * 5_SqrtJperSqrtm3, 20_Jperm3);
    }

    SUBCASE("Misc conversions") {
      // If desired
    }
  }
}
// NOLINTEND(modernize-use-trailing-return-type, misc-use-anonymous-namespace)

}  // namespace csm_units::test