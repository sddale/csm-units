#include "csm_units/pressure.hpp"

#include <doctest/doctest.h>

#include <cmath>

namespace csm_units::test {
TEST_CASE("Pressure") {
  auto pressure = Pressure(13.0);
  CHECK(std::abs(pressure.data - 13.0) < 0.001);
}
}  // namespace csm_units::test