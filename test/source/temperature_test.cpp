#include <doctest/doctest.h>

#include <csm_units/temperature.hpp>

namespace csm_units::test {

TEST_CASE("Kelvin to Kelvin") {
  auto lowTemperature = Kelvin(34.0);
  CHECK(lowTemperature.data == 34.0);
  
  auto highTemperature = Kelvin(300.4543);
  CHECK(highTemperature.data == 300.4543);
}

TEST_CASE("Fahrenheit to Kelvin") {
  auto baseTemperature = Fahrenheit(32.0);
  CHECK(baseTemperature.data == 273.15);

  auto lowTemperature = Fahrenheit(-32.554);
  CHECK(lowTemperature.data == 237.286);

  auto highTemperature = Fahrenheit(150.58483948747);
  CHECK(highTemperature.data == 339.030);
}

TEST_CASE("Celsius to Kelvin") {
  auto baseTemperature = Celsius(0.0);
  CHECK(baseTemperature.data == 273.15);

  auto lowTemperature = Celsius(-132.34211111);
  CHECK(lowTemperature.data == 140.807);

  auto highTemperature = Celsius(120.453);
  CHECK(highTemperature.data == 393.602);
}


}  // namespace csm_units::test
