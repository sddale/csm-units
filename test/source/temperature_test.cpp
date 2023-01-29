#include "../../include/csm_units/temperature.hpp"

#include <iostream>

#include "../../build/_deps/doctest-src/doctest/doctest.h"

namespace csm_units::test {

TEST_SUITE("Temperature") {
  TEST_CASE("Kelvin to Kelvin") {
    {
      const auto temperature = Kelvin(34.0);
      CHECK(temperature.Value() == doctest::Approx(34.0));
      CHECK(temperature.Value() == doctest::Approx(34.0));
    }
    {
      const auto temperature = Kelvin(300.4543);
      CHECK(temperature.Data() == doctest::Approx(300.4543));
      CHECK(temperature.Value() == doctest::Approx(300.4543));
    }
  }

  TEST_CASE("Fahrenheit to Kelvin") {
    {
      const auto temperature = Fahrenheit(32.0);
      CHECK(temperature.Data() == doctest::Approx(273.15));
      CHECK(temperature.Value() == doctest::Approx(32.0));
    }
    {
      const auto temperature = Fahrenheit(-32.554);
      CHECK(temperature.Data() == doctest::Approx(237.286));
      CHECK(temperature.Value() == doctest::Approx(-32.554));
    }
    {
      const auto temperature = Fahrenheit(150.58483948747);
      CHECK(temperature.Data() == doctest::Approx(339.030));
      CHECK(temperature.Value() == doctest::Approx(150.58483948747));
    }
  }

  TEST_CASE("Celsius to Kelvin") {
    {
      const auto temperature = Celsius(0.0);
      CHECK(temperature.Data() == doctest::Approx(273.15));
      CHECK(temperature.Value() == doctest::Approx(0.0));
    }
    {
      const auto temperature = Celsius(-132.34211111);
      CHECK(temperature.Data() == doctest::Approx(140.807));
      CHECK(temperature.Value() == doctest::Approx(-132.34211111));
    }
    {
      const auto temperature = Celsius(120.453);
      CHECK(temperature.Data() == doctest::Approx(393.602));
      CHECK(temperature.Value() == doctest::Approx(120.453));
    }
  }
  
  TEST_CASE("Size") {
    const auto temp = Kelvin(1.0);
    REQUIRE(sizeof(temp) == sizeof(temp.Data()));  // converter requires 0 bytes
  }
  
}

}  // namespace csm_units::test
