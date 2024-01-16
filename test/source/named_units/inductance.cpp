#include <doctest/doctest.h>

#include <csm_units/inductance.hpp>
#include <csm_units/length.hpp>
#include <csm_units/mass.hpp>
#include <csm_units/time.hpp>

#include "../common.hpp"

namespace csm_units::test {

// NOLINTBEGIN(modernize-use-trailing-return-type, misc-use-anonymous-namespace)
TEST_SUITE("Named Units") {
  using namespace literals;

  TEST_CASE("Inductance") {
    SUBCASE("Base unit functionality") {
      // Getters
      CHECK_DBL_EQ(Henry(1.).Get(), 1.);
      CHECK_DBL_EQ(Henry(1.).data, 1.);

      // Literals
      CHECK_UNIT_EQ(Henry(1.), 1.0_H);
      CHECK_UNIT_EQ(Henry(1.), 1.0 * H);
    }

    SUBCASE("Validate derived dimension") {
      CHECK_UNIT_EQ(1_m * 2_kg / (2_s * 5_s), 0.2_H);
    }

    SUBCASE("Derived unit conversions and literals") {
      // None Yet
    }

    SUBCASE("Misc conversions") {
      // Not Desired
    }
  }
}
// NOLINTEND(modernize-use-trailing-return-type, misc-use-anonymous-namespace)

}  // namespace csm_units::test