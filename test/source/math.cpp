#include <doctest/doctest.h>

#include <csm_units/units.hpp>
#include <source/csm_units/math.hpp>

#include "common.hpp"

namespace csm_units::test {

using namespace csm_units;
using namespace csm_units::literals;

// NOLINTBEGIN(modernize-use-trailing-return-type, misc-use-anonymous-namespace)
TEST_SUITE("Math utility functions") {
  TEST_CASE("UnitPow") {
    CHECK_UNIT_EQ(UnitSquare(2._m), 4._m2);
    CHECK_UNIT_EQ(UnitSquare(-2._m), 4._m2);
    CHECK_UNIT_EQ(UnitCube(2._m), 8._m3);
    CHECK_UNIT_EQ(UnitCube(-2._m), -8._m3);
  }
}
// NOLINTEND(modernize-use-trailing-return-type, misc-use-anonymous-namespace)

}  // namespace csm_units::test