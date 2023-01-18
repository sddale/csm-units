#include <doctest/doctest.h>

#include <csm_units/temperature.hpp>

namespace csm_units::test {

TEST_CASE("Temperature") {
  const auto temperature = Temperature(78);
  CHECK(temperature.data == 78);
}

}  // namespace csm_units::test
