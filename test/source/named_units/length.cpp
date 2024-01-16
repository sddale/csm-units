#include <doctest/doctest.h>

#include <csm_units/length.hpp>

#include "../common.hpp"

namespace csm_units::test {

// NOLINTBEGIN(modernize-use-trailing-return-type, misc-use-anonymous-namespace)
TEST_SUITE("Named Units") {
  using namespace literals;

  TEST_CASE("Length") {
    SUBCASE("Base unit functionality") {
      CHECK_DBL_EQ(Meter(3.).Get(), 3.);
      CHECK_DBL_EQ(Meter(3.).data, 3.);

      // Literals
      CHECK_UNIT_EQ(Meter(3), 3. * m);
      CHECK_UNIT_EQ(Meter(3), 3_m);
    }

    SUBCASE("Derived unit conversions and literals") {
      CHECK_UNIT_EQ(1_m, Centimeter(100));
      CHECK_UNIT_EQ(1_m, 100_cm);
      CHECK_UNIT_EQ(1_m, 100. * cm);

      CHECK_UNIT_EQ(0.3048_m, Foot(1));
      CHECK_UNIT_EQ(0.3048_m, 1_ft);
      CHECK_UNIT_EQ(0.3048_m, 1. * ft);

      CHECK_UNIT_EQ(0.3048_m, Inch(12));
      CHECK_UNIT_EQ(0.3048_m, 12_in);
      CHECK_UNIT_EQ(0.3048_m, 12. * in);

      CHECK_UNIT_EQ(1000_m, Kilometer(1));
      CHECK_UNIT_EQ(1000_m, 1_km);
      CHECK_UNIT_EQ(1000_m, 1. * km);

      CHECK_UNIT_EQ(1609.34_m, Mile(1));
      CHECK_UNIT_EQ(1609.34_m, 1_mi);
      CHECK_UNIT_EQ(1609.34_m, 1. * mi);

      CHECK_UNIT_EQ(1_m, Millimeter(1000));
      CHECK_UNIT_EQ(1_m, 1000_mm);
      CHECK_UNIT_EQ(1_m, 1000. * mm);

      CHECK_UNIT_EQ(1_m, Yard(1.09361));
      CHECK_UNIT_EQ(1_m, 1.09361_yd);
      CHECK_UNIT_EQ(1_m, 1.09361 * yd);
    }

    SUBCASE("Misc conversions") {
      // If desired
      CHECK_UNIT_EQ(10_mm, 1_cm);
      CHECK_UNIT_EQ(10_mm, 1. * cm);
      CHECK_UNIT_EQ(10. * mm, 1_cm);
      CHECK_UNIT_EQ(1.0e6_mm, 1_km);
      CHECK_UNIT_EQ(0.3048_m, 1_ft);
      CHECK_UNIT_EQ(1_yd, 3_ft);
      CHECK_UNIT_EQ(1_yd, 36_in);
      CHECK_UNIT_EQ(1_mi, 5280_ft);
    }
  }
}
// NOLINTEND(modernize-use-trailing-return-type, misc-use-anonymous-namespace)

}  // namespace csm_units::test