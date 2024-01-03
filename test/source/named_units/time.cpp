#include <doctest/doctest.h>

#include <source/csm_units/named_units/time/hour.hpp>
#include <source/csm_units/named_units/time/minute.hpp>
#include <source/csm_units/named_units/time/second.hpp>

#include "../common.hpp"

namespace csm_units::test {

// NOLINTBEGIN(modernize-use-trailing-return-type, misc-use-anonymous-namespace)
TEST_SUITE("Named Units") {
  TEST_CASE("Time") {
    CHECK_DBL_EQ(Hour(1.).Get(), 1.);
    CHECK_DBL_NEQ(Hour(1.).Get(), 2.);

    CHECK_DBL_EQ(Hour(1.).data, 3600);
    CHECK_DBL_NEQ(Hour(1.).data, 360);

    CHECK_DBL_EQ(Hour(1.).data, Minute(1 * 60.).data);
    CHECK_DBL_NEQ(Hour(1.).data, Minute(1 * 6.).data);

    CHECK_DBL_EQ(Hour(1.).data, Second(1 * 60 * 60.).data);
    CHECK_DBL_NEQ(Hour(1.).data, Second(1 * 60 * 6.).data);
  }
}
// NOLINTEND(modernize-use-trailing-return-type, misc-use-anonymous-namespace)

}  // namespace csm_units::test