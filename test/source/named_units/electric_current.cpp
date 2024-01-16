#include <doctest/doctest.h>

#include <csm_units/electric_current.hpp>

#include "../common.hpp"

namespace csm_units::test {

// NOLINTBEGIN(modernize-use-trailing-return-type, misc-use-anonymous-namespace)
TEST_SUITE("Named Units") {
  using namespace literals;
  TEST_CASE("Electric Current") {
    SUBCASE("Base unit functionality") {
      CHECK_DBL_EQ(Ampere(3.).Get(), 3.);
      CHECK_DBL_EQ(Ampere(3.).data, 3.);

      CHECK_UNIT_EQ(Ampere(3.), 3_A);
      CHECK_UNIT_EQ(Ampere(3.), 3. * A);

      CHECK_DBL_EQ(Milliampere(3.).Get(), 3);
      CHECK_DBL_EQ(Milliampere(3.).data, 0.003);

      CHECK_UNIT_EQ(Milliampere(3.), 3_mA);
      CHECK_UNIT_EQ(Milliampere(3.), 3. * mA);

      CHECK_DBL_EQ(SqAmpere(3.).Get(), 3);
      CHECK_DBL_EQ(SqAmpere(3.).data, 3);

      CHECK_UNIT_EQ(SqAmpere(3.), 3_A2);
      CHECK_UNIT_EQ(SqAmpere(3.), 3. * A2);

      CHECK_DBL_EQ(SqMilliampere(3.).Get(), 3);
      CHECK_DBL_EQ(SqMilliampere(3.).data, 3e-6);

      CHECK_UNIT_EQ(SqMilliampere(3.), 3_mA2);
      CHECK_UNIT_EQ(SqMilliampere(3.), 3. * mA2);
    }

    SUBCASE("Validate derived dimension") {
      CHECK_UNIT_EQ(3_A * 2_A, 6_A2);

      CHECK_UNIT_EQ(3_mA * 2_mA, 6_mA2);
    }

    SUBCASE("Derived unit conversions and literals") {
      CHECK_UNIT_EQ(1.0_A, Milliampere(1000));
      CHECK_UNIT_EQ(1.0_A, 1000_mA);
      CHECK_UNIT_EQ(1.0_A, 1000. * mA);

      CHECK_UNIT_EQ(1.0_A2, SqMilliampere(1000000));
      CHECK_UNIT_EQ(1.0_A2, 1000000_mA2);
      CHECK_UNIT_EQ(1.0_A2, 1000000. * mA2);
    }

    SUBCASE("Misc conversions") {
      CHECK_UNIT_EQ(3_mA * 2_mA, 6._mA2);

      CHECK_UNIT_EQ(2_A, 2000_mA);
      CHECK_UNIT_EQ(3_mA2, 3e-6_A2);

      CHECK_UNIT_EQ(5500_mA, 5.50_A);
      CHECK_UNIT_EQ(3_A2, 3000000_mA2);
    }

    // CHECK_UNIT_EQ(1_kg, 1000_g);
  }
}
// NOLINTEND(modernize-use-trailing-return-type, misc-use-anonymous-namespace)

}  // namespace csm_units::test