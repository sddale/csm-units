#include <doctest/doctest.h>

#include <csm_units/temperature.hpp>

#include "../common.hpp"

namespace csm_units::test {

// NOLINTBEGIN(modernize-use-trailing-return-type, misc-use-anonymous-namespace)
TEST_SUITE("Named Units") {
  TEST_CASE("Temperature") {
    CHECK_DBL_EQ(Kelvin(1.).Get(), 1.);
    CHECK_DBL_NEQ(Kelvin(1.).Get(), 2.);
    CHECK_DBL_EQ(Kelvin(1.).data, 1.);
    CHECK_DBL_NEQ(Kelvin(1.).data, 2.);

    CHECK_UNIT_EQ(Kelvin(5. / 9), Rankine(1));
    CHECK_UNIT_NEQ(Kelvin(5. / 9), Rankine(1));

    CHECK_UNIT_EQ(Kelvin(274.15), Celsius(1));
    CHECK_UNIT_NEQ(Kelvin(273.15), Celsius(1));

    CHECK_UNIT_EQ(Kelvin(255.928), Fahrenheit(1));
    CHECK_UNIT_NEQ(Kelvin(255.928), Fahrenheit(1));
  }
}
// NOLINTEND(modernize-use-trailing-return-type, misc-use-anonymous-namespace)

}  // namespace csm_units::test