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
      CHECK_UNIT_EQ(JoulesPerCuMeter(3), 3. * Jpercm3);
      CHECK_UNIT_EQ(JoulesPerCuMeter(3), 3_Jpercm3);
      CHECK_UNIT_EQ(SqrtJoulesPerSqrtCuMeter(3), 3. * SqrtJperSqrtcm3);
      CHECK_UNIT_EQ(SqrtJoulesPerSqrtCuMeter(3), 3_SqrtJperSqrtcm3);
    }

    SUBCASE("Derived unit conversions and literals") {
      // Calories Per Cubic Centimeter
    }

    SUBCASE("Misc conversions") {
      CHECK_UNIT_EQ(3_SqrtJperSqrtcm3 * 2_SqrtJperSqrtcm3, 6_Jpercm3);
      CHECK_UNIT_EQ(6_J / 2_m3, 3_Jpercm3);
      CHECK_UNIT_EQ(4_SqrtJperSqrtcm3 * 5_SqrtJperSqrtcm3, 20_Jpercm3);
    }
  }
}
// NOLINTEND(modernize-use-trailing-return-type, misc-use-anonymous-namespace)

}  // namespace csm_units::test