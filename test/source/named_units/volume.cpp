#include <doctest/doctest.h>

#include <csm_units/volume.hpp>

#include "../common.hpp"

namespace csm_units::test {

// NOLINTBEGIN(modernize-use-trailing-return-type, misc-use-anonymous-namespace)
TEST_SUITE("Named Units") {
  using namespace literals;

  TEST_CASE("Volume") {
    SUBCASE("Base unit functionality") {
      CHECK_DBL_EQ(CuMeter(3.).Get(), 3.);
      CHECK_DBL_EQ(CuMeter(3.).data, 3.);

      CHECK_UNIT_EQ(CuMeter(3.), 3_m3);
      CHECK_UNIT_EQ(CuMeter(3.), 3.0 * m3);

      CHECK_DBL_EQ(CuCentimeter(3.).Get(), 3.);
      CHECK_DBL_EQ(CuCentimeter(3.).data, 3e-6);

      CHECK_UNIT_EQ(CuCentimeter(3.), 3_cm3);
      CHECK_UNIT_EQ(CuCentimeter(3.), 3.0 * cm3);

      CHECK_DBL_EQ(Liter(3000.).data, 3);
      CHECK_DBL_EQ(Liter(3000.).Get(), 3000);

      CHECK_UNIT_EQ(Liter(3.), 3_L);
      CHECK_UNIT_EQ(Liter(3.), 3.0 * L);
    }

    SUBCASE("Validate derived dimension") {
      CHECK_UNIT_EQ(3_cm * 2_cm * 15_cm, 90_cm3);

      CHECK_UNIT_EQ((3_m * 2_m) * 15_m, 90_m3);
    }

    SUBCASE("Derived unit conversions and literals") {
      CHECK_UNIT_EQ(1.0_m3, CuCentimeter(1000000));
      CHECK_UNIT_EQ(1.0_m3, 1000000_cm3);
      CHECK_UNIT_EQ(1.0_m3, 1000000 * cm3);

      CHECK_UNIT_EQ(1.0_m3, Liter(1000));
      CHECK_UNIT_EQ(1.0_m3, 1000_L);
      CHECK_UNIT_EQ(1.0_m3, 1000 * L);
    }

    SUBCASE("Misc conversions") {
      CHECK_UNIT_EQ(10_m3, 10000_L);
      CHECK_UNIT_EQ(50_cm3, 5e-5_m3);
      CHECK_UNIT_EQ(0.55_L, 550_cm3);
      CHECK_UNIT_EQ(1_cm3, 0.001_L);
    }
  }
}
// NOLINTEND(modernize-use-trailing-return-type, misc-use-anonymous-namespace)

}  // namespace csm_units::test