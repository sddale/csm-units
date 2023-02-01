#include "../../include/csm_units/temperature.hpp"

#include <iostream>

#include "../../build/_deps/doctest-src/doctest/doctest.h"

namespace csm_units::test {

TEST_SUITE("Temperature") {
  TEST_CASE("Kelvin to Kelvin") {
    {
      const auto temperature = Kelvin(34.0);
      CHECK(temperature.data == doctest::Approx(34.0));
    }
    {
      const auto temperature = Kelvin(300.4543);
      CHECK(temperature.data == doctest::Approx(300.4543));
    }
  }

  TEST_CASE("Fahrenheit to Kelvin") {
    {
      const auto temperature = Fahrenheit(32.0);
      CHECK(temperature.data == doctest::Approx(32.0));
    }
    {
      const auto temperature = Fahrenheit(-32.554);
      CHECK(temperature.data == doctest::Approx(-32.554));
    }
    {
      const auto temperature = Fahrenheit(150.58483948747);
      CHECK(temperature.data == doctest::Approx(150.58483948747));
    }
  }

  TEST_CASE("Celsius to Kelvin") {
    {
      const auto temperature = Celsius(0.0);
      CHECK(temperature.data == doctest::Approx(0.0));
    }
    {
      const auto temperature = Celsius(-132.34211111);
      CHECK(temperature.data == doctest::Approx(-132.34211111));
    }
    {
      const auto temperature = Celsius(120.453);
      CHECK(temperature.data == doctest::Approx(120.453));
    }
  }

  TEST_CASE("Size") {
    const auto temp = Kelvin(1.0);
    REQUIRE(sizeof(temp) == sizeof(temp.data));  // converter requires 0 bytes
  }

TEST_SUITE("Operator Overloading Tests") {

  TEST_CASE("Kelvin - Same Unit") {
    const auto temp = Kelvin(273.15);
    const auto sameTemp = Kelvin(273.15);
    const auto lowTemp = Kelvin(88.45);
    const auto highTemp = Kelvin(456.32);

    CHECK(temp > lowTemp);
    CHECK(temp < highTemp);
    CHECK(temp >= lowTemp);
    CHECK(temp <= highTemp);
    CHECK(temp >= sameTemp);
    CHECK(temp <= sameTemp);
    CHECK(temp == sameTemp);
    CHECK(lowTemp < highTemp);
    CHECK(lowTemp <= highTemp);
    CHECK_FALSE(lowTemp > highTemp);
    CHECK_FALSE(highTemp <= lowTemp);
  }

  TEST_CASE("Fahrenheit - Same Unit") {
    const auto temp = Fahrenheit(66.34);
    const auto sameTemp = Fahrenheit(66.34);
    const auto lowTemp = Fahrenheit(-56.8);
    const auto highTemp = Fahrenheit(127.84);

    CHECK(temp > lowTemp);
    CHECK(temp < highTemp);
    CHECK(temp >= lowTemp);
    CHECK(temp <= highTemp);
    CHECK(temp >= sameTemp);
    CHECK(temp <= sameTemp);
    CHECK(temp == sameTemp);
    CHECK(lowTemp < highTemp);
    CHECK(lowTemp <= highTemp);
    CHECK_FALSE(lowTemp > highTemp);
    CHECK_FALSE(highTemp <= lowTemp);
  }

  TEST_CASE("Celsius - Same Unit") {
    const auto temp = Celsius(0.0);
    const auto sameTemp = Celsius(0.0);
    const auto lowTemp = Celsius(-34.8);
    const auto highTemp = Celsius(94.33);

    CHECK(temp > lowTemp);
    CHECK(temp < highTemp);
    CHECK(temp >= lowTemp);
    CHECK(temp <= highTemp);
    CHECK(temp >= sameTemp);
    CHECK(temp <= sameTemp);
    CHECK(temp == sameTemp);
    CHECK(lowTemp < highTemp);
    CHECK(lowTemp <= highTemp);
    CHECK_FALSE(lowTemp > highTemp);
    CHECK_FALSE(highTemp <= lowTemp);
  }

  TEST_CASE("Different Unit Comparisons") {
    const auto tempCelsius = Celsius(0.0);
    const auto tempKelvin = Kelvin(273.15);
    const auto tempFahrenheit = Fahrenheit(32.0);
    CHECK(tempCelsius == tempKelvin);
    CHECK(tempCelsius == tempFahrenheit);
    CHECK(tempKelvin >= tempFahrenheit);

    // add way more here
  }
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
