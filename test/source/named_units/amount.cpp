#include <doctest/doctest.h>

#include <csm_units/amount.hpp>

#include "../common.hpp"

namespace csm_units::test {

// NOLINTBEGIN(modernize-use-trailing-return-type, misc-use-anonymous-namespace)
TEST_SUITE("Named Units") {
  using namespace literals;
  TEST_CASE("Amount") {
    CHECK_DBL_EQ(Mole(3.).Get(), 3.);
    CHECK_DBL_EQ(Mole(3.).data, 3.);

    CHECK_DBL_EQ(Kilomole(3).data, 3000);
    CHECK_DBL_EQ(Kilomole(3).Get(), 3);

    CHECK_UNIT_EQ(1.0_mol, 0.001_kmol);
    CHECK_UNIT_EQ(2_mol * 2_mol, 4_mol2);
    CHECK_UNIT_EQ(2_kmol * 2_kmol, 4.e6_mol2);
  }
}
// NOLINTEND(modernize-use-trailing-return-type, misc-use-anonymous-namespace)

}  // namespace csm_units::test