#include <doctest/doctest.h>

#include <csm_units/momentum.hpp>

#include "../common.hpp"

namespace csm_units::test {

// NOLINTBEGIN(modernize-use-trailing-return-type, misc-use-anonymous-namespace)
TEST_SUITE("Named Units") {
  using namespace literals;
  TEST_CASE("Mass") {
    CHECK_DBL_EQ(KilogramMeterPerSecond(3.).Get(), 3.);
    CHECK_DBL_EQ(KilogramMeterPerSecond(3.).data, 3.);

    CHECK_DBL_EQ(SlugFeetPerSecond(3.).Get(), 3.);
    CHECK_DBL_EQ(SlugFeetPerSecond(3.).data, 13.3447);

    CHECK_UNIT_EQ(4.44822_kgmpers, 1_slugftpers);
    CHECK_UNIT_EQ(10_slugftpers, 44.48221_kgmpers);
  }
}
// NOLINTEND(modernize-use-trailing-return-type, misc-use-anonymous-namespace)

}  // namespace csm_units::test