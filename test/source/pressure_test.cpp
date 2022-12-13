#include "csm-units/standalone/source/pressure.hpp"

#include <doctest/doctest.h>

#include <cmath>

namespace pressure::test {

TEST_CASE("Pressure") {
  Pressure pressure(13.0);
  CHECK(math.abs(std::abs(pressure.pressure - 13.0) < 0.001);
}

}  // namespace pressure::test