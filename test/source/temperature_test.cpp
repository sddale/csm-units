#include <doctest/doctest.h>

#include <csm_units/temperature.hpp>

namespace csm_units::test {

TEST_CASE("Kelvin to Kelvin") {
  auto lowTemperature = Kelvin(34.0);
  CHECK(lowTemperature.data == 34.0);
  
  auto highTemperature = Kelvin(300.0);
  CHECK(highTemperature.data == 300.0);
}

TEST_CASE("Fahrenheit to Kelvin") {
  auto baseTemperature = Fahrenheit(32.0);
  CHECK(baseTemperature.data == 273.15);

  auto lowTemperature = Fahrenheit(0.0);
  CHECK(lowTemperature.data == 255.0);

}

}  // namespace csm_units::test
