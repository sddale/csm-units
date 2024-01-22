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
    CHECK_DBL_EQ(UnitPow<0>(-2._m), 1.0);
    CHECK_UNIT_EQ(UnitPow<1>(-2._m), -2._m);
    CHECK_UNIT_EQ(UnitPow<2>(-2._m), 4._m2);
    CHECK_UNIT_EQ(UnitPow<3>(-2._m), -8._m3);
    CHECK_UNIT_EQ(UnitPow<4>(-2._m), 16._m3 * m);
    CHECK_UNIT_EQ(UnitPow<-1>(-2._m), Unit<One() / m>(-0.5));
    CHECK_UNIT_EQ(UnitPow<-2>(-2._m), 1 / 4_m2);
    CHECK_UNIT_EQ(UnitPow<-3>(-2._m), -1 / 8_m3);
  }
}
// NOLINTEND(modernize-use-trailing-return-type, misc-use-anonymous-namespace)

}  // namespace csm_units::test