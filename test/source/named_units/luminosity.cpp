#include <doctest/doctest.h>

#include <csm_units/luminosity.hpp>

#include "../common.hpp"

namespace csm_units::test {

// NOLINTBEGIN(modernize-use-trailing-return-type, misc-use-anonymous-namespace)
TEST_SUITE("Named Units") {
  using namespace literals;

  TEST_CASE("Luminosity") {
    SUBCASE("Base unit functionality") {
      CHECK_DBL_EQ(Candela(1.).Get(), 1.);
      CHECK_DBL_EQ(Candela(1.).data, 1.);
      CHECK_DBL_EQ(SqCandela(1.).Get(), 1.);
      CHECK_DBL_EQ(SqCandela(1.).data, 1.);

      CHECK_UNIT_EQ(Candela(2.), 2_cd);
      CHECK_UNIT_EQ(Candela(2.), 2. * cd);
      CHECK_UNIT_EQ(SqCandela(2.), 2_cd2);
      CHECK_UNIT_EQ(SqCandela(2.), 2. * cd2);
    }

    SUBCASE("Misc conversions") {
      CHECK_UNIT_EQ(1_cd * cd, 1_cd2);
      CHECK_UNIT_EQ(2_cd * 2_cd, 4. * cd2);
      CHECK_UNIT_EQ(4_cd2 / 2_cd, 2. * cd);
    }
  }
}
// NOLINTEND(modernize-use-trailing-return-type, misc-use-anonymous-namespace)

}  // namespace csm_units::test