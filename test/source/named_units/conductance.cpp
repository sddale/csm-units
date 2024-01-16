#include <doctest/doctest.h>

#include <csm_units/conductance.hpp>
#include <csm_units/electric_current.hpp>
#include <csm_units/length.hpp>
#include <csm_units/mass.hpp>
#include <csm_units/time.hpp>

#include "../common.hpp"

namespace csm_units::test {

// NOLINTBEGIN(modernize-use-trailing-return-type, misc-use-anonymous-namespace)
TEST_SUITE("Named Units") {
  using namespace literals;

  TEST_CASE("Catalytic Activity") {
    SUBCASE("Base unit Sunctionality") {
      // Getters
      CHECK_DBL_EQ(Siemens(1.).Get(), 1.);
      CHECK_DBL_EQ(Siemens(1.).data, 1.);

      // Literals
      CHECK_UNIT_EQ(Siemens(1.), 1.0_S);
      CHECK_UNIT_EQ(Siemens(1.), 1.0 * S);
    }

    SUBCASE("Validate derived dimension") {
      CHECK_UNIT_EQ(1_s * 2_s * 3_s * 4_A * 5_A / (6_m * 7_m * 8_kg),
                    0.3571428571_S);
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