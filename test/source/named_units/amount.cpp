#include <doctest/doctest.h>

#include <csm_units/amount.hpp>

#include "../common.hpp"

namespace csm_units::test {

// NOLINTBEGIN(modernize-use-trailing-return-type, misc-use-anonymous-namespace)
TEST_SUITE("Named Units") {
  using namespace literals;

  TEST_CASE("Amount") {
    SUBCASE("Base unit functionality") {
      // Getters
      CHECK_DBL_EQ(Mole(3.).Get(), 3.);
      CHECK_DBL_EQ(Mole(3.).data, 3.);
      CHECK_DBL_EQ(SqMole(3.).Get(), 3.);
      CHECK_DBL_EQ(SqMole(3.).data, 3.);

      // Literals
      CHECK_UNIT_EQ(Mole(3), 3. * mol);
      CHECK_UNIT_EQ(Mole(3), 3_mol);
      CHECK_UNIT_EQ(SqMole(3), 3. * mol2);
      CHECK_UNIT_EQ(SqMole(3), 3_mol2);
    }

    SUBCASE("Derived unit conversions and literals") {
      CHECK_UNIT_EQ(1_mol, Kilomole(0.001));
      CHECK_UNIT_EQ(1_mol, 0.001_kmol);
      CHECK_UNIT_EQ(1_mol, 0.001 * kmol);

      CHECK_UNIT_EQ(1_mol2, SqKilomole(1e-6));
      CHECK_UNIT_EQ(1_mol2, 1.e-6_kmol2);
      CHECK_UNIT_EQ(1_mol2, 1.e-6 * kmol2);
    }

    SUBCASE("Misc conversions") {
      // If desired
      CHECK_UNIT_EQ(2_mol * 2_mol, 4_mol2);
      CHECK_UNIT_EQ(2_kmol * 2_kmol, 4.e6_mol2);
      CHECK_DBL_EQ(4_kmol / 3_mol, 1333.33);
    }
  }
}
// NOLINTEND(modernize-use-trailing-return-type, misc-use-anonymous-namespace)

}  // namespace csm_units::test