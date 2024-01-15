#include <doctest/doctest.h>

#include <csm_units/area.hpp>
#include <csm_units/density.hpp>
#include <csm_units/length.hpp>
#include <csm_units/mass.hpp>
#include <csm_units/volume.hpp>

#include "../common.hpp"

namespace csm_units::test {

// NOLINTBEGIN(modernize-use-trailing-return-type, misc-use-anonymous-namespace)
TEST_SUITE("Named Units") {
  using namespace literals;

  TEST_CASE("Density") {
    SUBCASE("Base unit functionality") {
      // Getters
      CHECK_DBL_EQ(KilogramPerCuMeter(1.).Get(), 1.);
      CHECK_DBL_EQ(KilogramPerCuMeter(1.).data, 1.);

      // Literals
      CHECK_UNIT_EQ(KilogramPerCuMeter(1.), 1.0_kgperm3);
      CHECK_UNIT_EQ(KilogramPerCuMeter(1.), 1.0 * kgperm3);
    }

    SUBCASE("Validate derived dimension") {
      CHECK_UNIT_EQ(3.0_kg / (0.75_m2 * m), 4.0_kgperm3);
    }

    SUBCASE("Derived unit conversions and literals for Kg/Cm3") {
      CHECK_UNIT_EQ(1.0_kgperm3, KilogramPerCuCentimeter(1.0e-6));
      CHECK_UNIT_EQ(5.4_kgperm3, KilogramPerCuCentimeter(5.4e-6));
      CHECK_UNIT_EQ(1.0_kgperm3, 1.0e-6_kgpercm3);
      CHECK_UNIT_EQ(1.0_kgperm3, 1.0e-6 * kgpercm3);
    }

    SUBCASE("Derived unit conversions and literals for Kg/L") {
      CHECK_UNIT_EQ(1.0_kgperm3, KilogramPerLiter(1.0e-3));
      CHECK_UNIT_EQ(3.6_kgperm3, KilogramPerLiter(3.6e-3));
      CHECK_UNIT_EQ(1.0_kgperm3, 1.0e-3_kgperL);
      CHECK_UNIT_EQ(1.0_kgperm3, 1.0e-3 * kgperL);
    }

    SUBCASE("Misc conversions") {
      // If desired
      CHECK_UNIT_EQ(4.3_kgpercm3 * 3.0_kgperL / 1.5_kgperm3, 8.6e6_kgperL);
      CHECK_DBL_EQ(4.4_kgperL / 4.0_kgperm3, 1.1e3);
    }
  }
}
// NOLINTEND(modernize-use-trailing-return-type, misc-use-anonymous-namespace)

}  // namespace csm_units::test