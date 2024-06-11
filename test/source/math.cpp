#include <doctest/doctest.h>

#include <cmath>
#include <csm_units/units.hpp>
#include <ratio>
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
    CHECK_UNIT_EQ(UnitPow<std::ratio<2>>(-2._m), 4._m2);
    CHECK_UNIT_EQ(UnitPow<3>(-2._m), -8._m3);
    CHECK_UNIT_EQ(UnitPow<4>(-2._m), 16._m3 * m);
    CHECK_UNIT_EQ(UnitPow<-1>(-2._m), -0.5 / m);
    CHECK_UNIT_EQ(UnitPow<-2>(-2._m), 1 / 4_m2);
    CHECK_UNIT_EQ(UnitPow<-3>(-2._m), -1 / 8_m3);
    CHECK_UNIT_EQ(UnitPow<-3>(-2._cm), -125000. / m3);
    CHECK_UNIT_EQ(UnitPow<std::ratio<1, 2>>(2._m2), 1.4142135623730951_m);
    CHECK_UNIT_EQ(UnitPow<std::ratio<1, 3>>(10._m3), 2.15443469003_m);
    CHECK_UNIT_EQ(UnitPow<std::ratio<2, 3>>(10._m3), 4.64158883361_m2);
    CHECK_UNIT_EQ(UnitPow<3, 2>(10._m2), 31.6227766017_m3);
    CHECK_UNIT_EQ(UnitPow<3, 2>(10. * cm * cm), 3.16228e-05_m3);
    CHECK_UNIT_EQ(UnitPow<std::ratio<-3, 2>>(10._m2), 0.0316227766 / m3);
    CHECK_DBL_EQ(UnitPow<std::ratio<-0, 1>>(10._m2), 1);
    CHECK(std::isnan(UnitPow<std::ratio<1, 2>>(-4._m2).data));
    CHECK_UNIT_EQ(UnitPow<std::ratio<1, 3>>(-8._m3), -2_m);
    CHECK_UNIT_EQ(  // Check arbitrary root function, here just return 10
        UnitPow<std::ratio<-3, 2>, SqMeter,
                [](typename SqMeter::ValueType) { return 10; }>(10._m2),
        1e-3 / m3);
  }
}
// NOLINTEND(modernize-use-trailing-return-type, misc-use-anonymous-namespace)

}  // namespace csm_units::test