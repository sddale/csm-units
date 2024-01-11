#include <doctest/doctest.h>

#include <csm_units/mass.hpp>

#include "../common.hpp"

namespace csm_units::test {

// NOLINTBEGIN(modernize-use-trailing-return-type, misc-use-anonymous-namespace)
TEST_SUITE("Named Units") {
  using namespace literals;
  TEST_CASE("Length") {
    CHECK_DBL_EQ(Kilogram(3.).Get(), 3.);
    CHECK_DBL_EQ(Kilogram(3.).data, 3.);

    CHECK_DBL_EQ(Gram(3.).Get(), 3);
    CHECK_DBL_EQ(Gram(3.).data, 0.003);

    CHECK_UNIT_EQ(2.20462_lb, 1_kg);
    CHECK_UNIT_EQ(1_lb, 0.031081_slug);
    CHECK_UNIT_EQ(1_kg, 0.0685218_slug);
    CHECK_UNIT_EQ(1_kg, 1000_g);
  }
}
// NOLINTEND(modernize-use-trailing-return-type, misc-use-anonymous-namespace)

}  // namespace csm_units::test