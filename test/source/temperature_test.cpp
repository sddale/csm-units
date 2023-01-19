#include <doctest/doctest.h>

#include <csm_units/temperature.hpp>

namespace csm_units::test {

template <class Converter>
TEST_CASE("Temperature") {
  const auto temperature = Temperature(Converter 78.0);
  CHECK(temperature.data == 78.0);
}

}  // namespace csm_units::test
