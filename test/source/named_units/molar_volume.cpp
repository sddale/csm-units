#include <doctest/doctest.h>

#include <csm_units/amount.hpp>
#include <csm_units/area.hpp>
#include <csm_units/length.hpp>
#include <csm_units/molar_volume.hpp>
#include <csm_units/volume.hpp>

#include "../common.hpp"

namespace csm_units::test {

// NOLINTBEGIN(modernize-use-trailing-return-type, misc-use-anonymous-namespace)
TEST_SUITE("Named Units") {
  using namespace literals;

  TEST_CASE("Molar Volume") {
    SUBCASE("Base unit functionality") {
      // Getters
      CHECK_DBL_EQ(CuMeterPerMole(1.).Get(), 1.);
      CHECK_DBL_EQ(CuMeterPerMole(1.).data, 1.);

      // Literals
      CHECK_UNIT_EQ(CuMeterPerMole(1.), 1.0_m3permole);
      CHECK_UNIT_EQ(CuMeterPerMole(1.), 1.0 * m3permole);
    }

    SUBCASE("Validate derived dimension") {
      CHECK_UNIT_EQ(2.5_m * m2 / (0.5_mol), 5.0_m3permole);
    }

    SUBCASE("Derived unit conversions and literals") {
      CHECK_UNIT_EQ(1.0_m3permole, CuCentimeterPerMole(1.0e6));
      CHECK_UNIT_EQ(6.7_m3permole, CuCentimeterPerMole(6.7e6));
      CHECK_UNIT_EQ(1.0_m3permole, 1.0e6_cm3permole);
      CHECK_UNIT_EQ(1.0_m3permole, 1.0e6 * cm3permole);
    }

    SUBCASE("Misc conversions") {
      // If desired
      CHECK_UNIT_EQ(5_m3permole * 7_cm3permole / 5_m3permole, 7_cm3permole);
      CHECK_DBL_EQ(7.0_m3permole / 3.5e6_cm3permole, 2.0);
    }
  }
}
// NOLINTEND(modernize-use-trailing-return-type, misc-use-anonymous-namespace)

}  // namespace csm_units::test