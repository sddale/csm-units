#include "../../include/csm_units/temperature.hpp"

#include <iostream>

#include "../../build/_deps/doctest-src/doctest/doctest.h"

namespace csm_units::test {

TEST_CASE("Kelvin to Kelvin") {
  {
    auto temperature = Kelvin(34.0);
    CHECK(temperature.data == doctest::Approx(34.0));
  }
  {
    auto temperature = Kelvin(300.4543);
    CHECK(temperature.data == doctest::Approx(300.4543));
  }
}

TEST_CASE("Fahrenheit to Kelvin") {
  auto baseTemperature = Fahrenheit(32.0);
  CHECK(baseTemperature.data == doctest::Approx(273.15));

  auto lowTemperature = Fahrenheit(-32.554);
  CHECK(lowTemperature.data == doctest::Approx(237.286));

  auto highTemperature = Fahrenheit(150.58483948747);
  CHECK(highTemperature.data == doctest::Approx(339.030));
}

TEST_CASE("Celsius to Kelvin") {
  auto baseTemperature = Celsius(0.0);
  CHECK(baseTemperature.data == doctest::Approx(273.15));

  auto lowTemperature = Celsius(-132.34211111);
  CHECK(lowTemperature.data == doctest::Approx(140.807));

  auto highTemperature = Celsius(120.453);
  CHECK(highTemperature.data == doctest::Approx(393.602));
}

TEST_CASE("Size") {
  auto temp = Kelvin(10);
  REQUIRE(sizeof(temp) == sizeof(temp.data));  // converter requires 0 bytes
}

}  // namespace csm_units::test
