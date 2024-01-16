#include <doctest/doctest.h>

#include <csm_units/temperature.hpp>

#include "../common.hpp"

namespace csm_units::test {

// NOLINTBEGIN(modernize-use-trailing-return-type, misc-use-anonymous-namespace)
TEST_SUITE("Named Units") {
  using namespace literals;

  TEST_CASE("Temperature") {
    SUBCASE("Base unit functionality") {
      CHECK_DBL_EQ(Kelvin(2.).Get(), 2.);
      CHECK_DBL_EQ(Kelvin(2.).data, 2.);

      // Literals
      CHECK_UNIT_EQ(Kelvin(3), 3. * K);
      CHECK_UNIT_EQ(Kelvin(3), 3_K);
    }

    SUBCASE("Derived unit conversions and literals") {
      CHECK_UNIT_EQ(1_K, Rankine(1.8));
      CHECK_UNIT_EQ(1_K, 1.8_degR);
      CHECK_UNIT_EQ(1_K, 1.8 * degR);

      CHECK_UNIT_EQ(274.15_K, Celsius(1));
      CHECK_UNIT_EQ(274.15_K, 1_degC);
      CHECK_UNIT_EQ(274.15_K, 1. * degC);

      CHECK_UNIT_EQ(255.928_K, Fahrenheit(1));
      CHECK_UNIT_EQ(255.928_K, 1_degF);
      CHECK_UNIT_EQ(255.928_K, 1. * degF);
    }

    SUBCASE("Derived unit conversions and literals") {
      CHECK_DBL_NEQ(Unit<K * K>(1).data, Unit<degC * K>(1 + 273.15).data);
    }
  }
}
// NOLINTEND(modernize-use-trailing-return-type, misc-use-anonymous-namespace)

}  // namespace csm_units::test