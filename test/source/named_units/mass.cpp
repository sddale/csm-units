#include <doctest/doctest.h>

#include <csm_units/mass.hpp>

#include "../common.hpp"

namespace csm_units::test {

// NOLINTBEGIN(modernize-use-trailing-return-type, misc-use-anonymous-namespace)
TEST_SUITE("Named Units") {
  using namespace literals;

  TEST_CASE("Mass") {
    SUBCASE("Base unit functionality") {
      CHECK_DBL_EQ(Kilogram(3.).Get(), 3.);
      CHECK_DBL_EQ(Kilogram(3.).data, 3.);

      CHECK_UNIT_EQ(Kilogram(3.), 3_kg);
      CHECK_UNIT_EQ(Kilogram(3.), 3 * kg);
    }

    SUBCASE("Derived unit conversions and literals") {
      CHECK_UNIT_EQ(Gram(3000), 3_kg);
      CHECK_UNIT_EQ(3000_g, 3_kg);
      CHECK_UNIT_EQ(3000. * g, 3_kg);

      CHECK_UNIT_EQ(Pound(2.20462), 1_kg);
      CHECK_UNIT_EQ(2.20462_lb, 1_kg);
      CHECK_UNIT_EQ(2.20462 * lb, 1_kg);

      CHECK_UNIT_EQ(1_kg, Slug(0.0685218));
      CHECK_UNIT_EQ(1_kg, 0.0685218_slug);
      CHECK_UNIT_EQ(1_kg, 0.0685218 * slug);
    }

    SUBCASE("Misc conversions") { CHECK_UNIT_EQ(1_lb, 0.031081_slug); }
  }
}
// NOLINTEND(modernize-use-trailing-return-type, misc-use-anonymous-namespace)

}  // namespace csm_units::test