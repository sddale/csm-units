#include <doctest/doctest.h>

#include <csm_units/amount.hpp>
#include <csm_units/catalytic_activity.hpp>
#include <csm_units/time.hpp>

#include "../common.hpp"

namespace csm_units::test {

// NOLINTBEGIN(modernize-use-trailing-return-type, misc-use-anonymous-namespace)
TEST_SUITE("Named Units") {
  using namespace literals;

  TEST_CASE("Catalytic Activity") {
    SUBCASE("Base unit katunctionality") {
      // Getters
      CHECK_DBL_EQ(Katal(1.).Get(), 1.);
      CHECK_DBL_EQ(Katal(1.).data, 1.);

      // Literals
      CHECK_UNIT_EQ(Katal(1.), 1.0_kat);
      CHECK_UNIT_EQ(Katal(1.), 1.0 * kat);
    }

    SUBCASE("Validate derived dimension") {
      CHECK_UNIT_EQ(1_mol / 2_s, 0.5_kat);
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