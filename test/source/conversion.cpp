#include <doctest/doctest.h>

#include <csm_units/units.hpp>

namespace csm_units::test {

// NOLINTBEGIN(modernize-use-trailing-return-type, misc-use-anonymous-namespace)

TEST_SUITE("Conversion Tests For Named Units") {
  TEST_CASE("Molar Volume") {
    const auto molar_cubic_centimeter = CubicCentimeterPerMole(2E+6);
    const auto molar_cubic_meter = CubicMeterPerMole(2.0);

    CHECK(molar_cubic_centimeter == molar_cubic_meter);
  }
  TEST_CASE("Volume") {
    using namespace csm_units::literals;

    const auto cubic_centimeter = CubicCentimeter(2E+6);
    const auto cubic_centimeter_literal = 2000000_cm3;
    const auto cubic_meter = CubicMeter(2.0);

    CHECK(cubic_centimeter == cubic_meter);
    CHECK(cubic_centimeter_literal == cubic_meter);
  }
}

// NOLINTEND(modernize-use-trailing-return-type, misc-use-anonymous-namespace)

}  // namespace csm_units::test