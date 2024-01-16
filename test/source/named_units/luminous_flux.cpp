#include <doctest/doctest.h>

#include <csm_units/luminosity.hpp>
#include <csm_units/luminous_flux.hpp>

#include "../common.hpp"

namespace csm_units::test {

// NOLINTBEGIN(modernize-use-trailing-return-type, misc-use-anonymous-namespace)
TEST_SUITE("Named Units") {
  using namespace literals;

  TEST_CASE("Luminous Flux") {
    SUBCASE("Base unit functionality") {
      // Getters
      CHECK_DBL_EQ(Lumen(1.).Get(), 1.);
      CHECK_DBL_EQ(Lumen(1.).data, 1.);

      // Literals
      CHECK_UNIT_EQ(Lumen(1.), 1.0_lm);
      CHECK_UNIT_EQ(Lumen(1.), 1.0 * lm);
    }

    SUBCASE("Validate derived dimension") { CHECK_UNIT_EQ(1_cd, 1_lm); }

    SUBCASE("Derived unit conversions and literals") {
      // None Yet
    }

    SUBCASE("Misc conversions") {
      // Not Desired
    }
  }
}
// NOLINTEND(modernize-use-trailing-return-type, misc-use-anonymous-namespace)

}  // namespace csm_units::test