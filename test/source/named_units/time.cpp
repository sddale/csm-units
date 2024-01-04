#include <doctest/doctest.h>

#include <csm_units/units.hpp>

#include "../common.hpp"

namespace csm_units::test {

// NOLINTBEGIN(modernize-use-trailing-return-type, misc-use-anonymous-namespace)
TEST_SUITE("Named Units") {
  TEST_CASE("Time") {
    CHECK_DBL_EQ(Hour(1.).Get(), 1.);
    CHECK_DBL_NEQ(Hour(1.).Get(), 2.);

    CHECK_DBL_EQ(Hour(1.).data, 3600);
    CHECK_DBL_NEQ(Hour(1.).data, 360);

    CHECK_UNIT_EQ(Hour(1.), Minute(1 * 60.));
    CHECK_UNIT_NEQ(Hour(1.), Minute(1 * 6.));

    CHECK_UNIT_EQ(Hour(1.), Second(1 * 60 * 60.));
    CHECK_UNIT_NEQ(Hour(1.), Second(1 * 60 * 6.));
  }
}
// NOLINTEND(modernize-use-trailing-return-type, misc-use-anonymous-namespace)

}  // namespace csm_units::test