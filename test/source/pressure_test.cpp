#include "csm_units/pressure.hpp"

#include <doctest/doctest.h>

#include <cmath>

namespace pressure::test {

TEST_CASE("Pressure") {
  auto pressure = Pressure(13.0);
  CHECK(std::abs(pressure.data - 13.0) < 0.001);
}

}  // namespace pressure::test