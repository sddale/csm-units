#include "../../include/csm_units/temperature.hpp"

#include <iostream>

#include "../../build/_deps/doctest-src/doctest/doctest.h"

namespace csm_units::test {

TEST_SUITE("Temperature") {
  // TEST_CASE("Kelvin to Kelvin") {
  //   {
  //     const auto temperature = Kelvin(34.0);
  //     CHECK(temperature.Value() == doctest::Approx(34.0));
  //     CHECK(temperature.Value() == doctest::Approx(34.0));
  //   }
  //   {
  //     const auto temperature = Kelvin(300.4543);
  //     CHECK(temperature.Data() == doctest::Approx(300.4543));
  //     CHECK(temperature.Value() == doctest::Approx(300.4543));
  //   }
  // }

  // TEST_CASE("Fahrenheit to Kelvin") {
  //   {
  //     const auto temperature = Fahrenheit(32.0);
  //     CHECK(temperature.Data() == doctest::Approx(273.15));
  //     CHECK(temperature.Value() == doctest::Approx(32.0));
  //   }
  //   {
  //     const auto temperature = Fahrenheit(-32.554);
  //     CHECK(temperature.Data() == doctest::Approx(237.286));
  //     CHECK(temperature.Value() == doctest::Approx(-32.554));
  //   }
  //   {
  //     const auto temperature = Fahrenheit(150.58483948747);
  //     CHECK(temperature.Data() == doctest::Approx(339.030));
  //     CHECK(temperature.Value() == doctest::Approx(150.58483948747));
  //   }
  // }

  // TEST_CASE("Celsius to Kelvin") {
  //   {
  //     const auto temperature = Celsius(0.0);
  //     CHECK(temperature.Data() == doctest::Approx(273.15));
  //     CHECK(temperature.Value() == doctest::Approx(0.0));
  //   }
  //   {
  //     const auto temperature = Celsius(-132.34211111);
  //     CHECK(temperature.Data() == doctest::Approx(140.807));
  //     CHECK(temperature.Value() == doctest::Approx(-132.34211111));
  //   }
  //   {
  //     const auto temperature = Celsius(120.453);
  //     CHECK(temperature.Data() == doctest::Approx(393.602));
  //     CHECK(temperature.Value() == doctest::Approx(120.453));
  //   }
  // }

  // TEST_CASE("Size") {
  //   const auto temp = Kelvin(1.0);
  //   REQUIRE(sizeof(temp) == sizeof(temp.Data()));  // converter requires 0
  //   bytes
  // }

  // TEST_CASE("Overloading Kelvin") {
  //   const auto temp = Kelvin(273.15);
  //   const auto sameTemp = Kelvin(273.15);
  //   const auto lowTemp = Kelvin(88.45);
  //   const auto highTemp = Kelvin(456.32);

  //   CHECK(temp >= lowTemp);
  //   CHECK(lowTemp <= highTemp);
  //   CHECK(highTemp >= temp);
  //   CHECK(temp > lowTemp);
  //   CHECK(lowTemp < highTemp);
  //   CHECK(highTemp >= temp);
  //   CHECK(temp == sameTemp);
  // }

  // TEST_CASE("Overloading Fahrenheit") {
  //   const auto temp = Fahrenheit(66.34);
  //   const auto sameTemp = Fahrenheit(66.34);
  //   const auto lowTemp = Fahrenheit(-56.8);
  //   const auto highTemp = Fahrenheit(127.84);

  //   CHECK(temp >= lowTemp);
  //   CHECK(lowTemp <= highTemp);
  //   CHECK(highTemp >= temp);
  //   CHECK(temp > lowTemp);
  //   CHECK(lowTemp < highTemp);
  //   CHECK(highTemp > temp);
  //   CHECK(temp == sameTemp);
  // }

  // TEST_CASE("Overloading Celsius") {
  //   const auto temp = Celsius(0.0);
  //   const auto sameTemp = Celsius(0.0);
  //   const auto lowTemp = Celsius(-34.8);
  //   const auto highTemp = Celsius(94.33);

  //   CHECK(temp >= lowTemp);
  //   CHECK(lowTemp <= highTemp);
  //   CHECK(highTemp >= temp);
  //   CHECK(highTemp >= sameTemp);
  //   CHECK(temp > lowTemp);
  //   CHECK(lowTemp < highTemp);
  //   CHECK(highTemp > temp);
  //   CHECK(temp == sameTemp);
  // }

  TEST_CASE("different unit test check") {
    const auto temperature = Celsius(0.0);
    const auto temperature2 = Kelvin(273.15);
    const auto temperature3 = Fahrenheit(273.15);
    CHECK(temperature == temperature2);
    CHECK_FALSE(temperature2 > temperature3);
  }

  // TODO(MANAS): Refactor comparison overload test cases

  TEST_CASE("Copy Constructor") {
    const auto temperature = Kelvin(30.5);
    const auto diffTemperature =
        Kelvin(temperature);  // throwing error here not sure what is going on
    CHECK(diffTemperature.data == doctest::Approx(30.5));
  }
}

}  // namespace csm_units::test
