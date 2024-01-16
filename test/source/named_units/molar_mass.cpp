#include <doctest/doctest.h>

#include <csm_units/amount.hpp>
#include <csm_units/mass.hpp>
#include <csm_units/molar_mass.hpp>

#include "../common.hpp"

namespace csm_units::test {

// NOLINTBEGIN(modernize-use-trailing-return-type, misc-use-anonymous-namespace)
TEST_SUITE("Named Units") {
  using namespace literals;

  TEST_CASE("Molar Mass") {
    SUBCASE("Base unit functionality") {
      // Getters
      CHECK_DBL_EQ(KilogramPerMole(1.).Get(), 1.);
      CHECK_DBL_EQ(KilogramPerMole(1.).data, 1.);

      // Literals
      CHECK_UNIT_EQ(KilogramPerMole(1.), 1.0_kgpermol);
      CHECK_UNIT_EQ(KilogramPerMole(1.), 1.0 * kgpermol);
    }

    SUBCASE("Validate derived dimension") {
      CHECK_UNIT_EQ(6.6_kg / (2.0_mol), 3.3_kgpermol);
    }

    SUBCASE("Derived unit conversions and literals") {
      CHECK_UNIT_EQ(1.0_kgpermol, GramPerMole(1.0e3));
      CHECK_UNIT_EQ(5.4_kgpermol, GramPerMole(5.4e3));
      CHECK_UNIT_EQ(1.0_kgpermol, 1.0e3_gpermol);
      CHECK_UNIT_EQ(1.0_kgpermol, 1.0e3 * gpermol);
    }

    SUBCASE("Misc conversions") {
      // If desired
      CHECK_UNIT_EQ(3.7_gpermol * 5.8_kgpermol / 3.7_gpermol, 5.8_kgpermol);
      CHECK_DBL_EQ(8.0_kgpermol / 2.0_gpermol, 4.0e3);
    }
  }
}
// NOLINTEND(modernize-use-trailing-return-type, misc-use-anonymous-namespace)

}  // namespace csm_units::test