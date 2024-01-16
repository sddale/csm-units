#include <doctest/doctest.h>

#include <csm_units/electric_charge.hpp>
#include <csm_units/electric_current.hpp>
#include <csm_units/time.hpp>

#include "../common.hpp"

namespace csm_units::test {

// NOLINTBEGIN(modernize-use-trailing-return-type, misc-use-anonymous-namespace)
TEST_SUITE("Named Units") {
  using namespace literals;
  TEST_CASE("Electric Charge") {
    SUBCASE("Base unit functionality") {
      CHECK_DBL_EQ(Coulomb(3.).Get(), 3.);
      CHECK_DBL_EQ(Coulomb(3.).data, 3.);

      CHECK_UNIT_EQ(Coulomb(3.), 3_C);
      CHECK_UNIT_EQ(Coulomb(3.), 3. * C);
    }

    SUBCASE("Validate derived dimension") { CHECK_UNIT_EQ(2_s * 3_A, 6_C); }

    SUBCASE("Derived unit conversions and literals") {
      // None Yet
    }

    SUBCASE("Misc conversions") {
      // Not Desired
    }

    // CHECK_UNIT_EQ(1_kg, 1000_g);
  }
}
// NOLINTEND(modernize-use-trailing-return-type, misc-use-anonymous-namespace)

}  // namespace csm_units::test