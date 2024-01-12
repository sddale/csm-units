#include <doctest/doctest.h>

#include <csm_units/momentum.hpp>

#include "../common.hpp"

namespace csm_units::test {

// NOLINTBEGIN(modernize-use-trailing-return-type, misc-use-anonymous-namespace)
TEST_SUITE("Named Units") {
  using namespace literals;
  TEST_CASE("Mass") {
    SUBCASE("Base unit functionality") {
      CHECK_DBL_EQ(KilogramMeterPerSecond(3.).Get(), 3.);
      CHECK_DBL_EQ(KilogramMeterPerSecond(3.).data, 3.);

      CHECK_UNIT_EQ(KilogramMeterPerSecond(3.), 3_kgmpers);
      CHECK_UNIT_EQ(KilogramMeterPerSecond(3.), 3. * kgmpers);

      CHECK_DBL_EQ(SlugFeetPerSecond(3.).Get(), 3.);
      CHECK_DBL_EQ(SlugFeetPerSecond(3.).data, 13.3447);

      CHECK_UNIT_EQ(SlugFeetPerSecond(3.), 3_slugftpers);
      CHECK_UNIT_EQ(SlugFeetPerSecond(3.), 3. * slugftpers);
    }

    SUBCASE("Validate derived dimension") {
      CHECK_UNIT_EQ(3_kg * 2_m / 6_s, 1_kgmpers);

      CHECK_UNIT_EQ(3_slug * 2_ft / 6_s, 1_slugftpers);
    }

    SUBCASE("Derived unit conversions and literals") {
      CHECK_UNIT_EQ(1.0_kgmpers, SlugFeetPerSecond(0.224808943));
      CHECK_UNIT_EQ(1.0_kgmpers, 0.224808943_slugftpers);
      CHECK_UNIT_EQ(1.0_kgmpers, 0.224808943 * slugftpers);
    }

    SUBCASE("Misc conversions") {
      CHECK_UNIT_EQ(4.44822_kgmpers, 1_slugftpers);
      CHECK_UNIT_EQ(10_slugftpers, 44.48221_kgmpers);
    }
  }
}
// NOLINTEND(modernize-use-trailing-return-type, misc-use-anonymous-namespace)

}  // namespace csm_units::test