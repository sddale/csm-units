#include "../../include/csm_units/pressure.hpp"

#include <cmath>

#include "../../build/_deps/doctest-src/doctest/doctest.h"

namespace csm_units::test {

// NOLINTBEGIN(modernize-use-trailing-return-type)
TEST_SUITE("Pressure") {
  // test to make user each data unit can go back and forth by creating each
  // type then asking for it back

  TEST_CASE("Pascal") {  // test for Pascals
    const auto test = Pascals(1234567.0);
    CHECK(test.Value() == doctest::Approx(1234567.0));
  }

  // test for Bar
  TEST_CASE("Bar") {
    const auto test = Bar(12.34567);
    CHECK(test.Value() == doctest::Approx(12.34567));

    const auto ref = Pascals(1234567.0);
    CHECK(test.Data() == doctest::Approx(ref.Value()));
  }

  // test for ATM
  TEST_CASE("ATM") {
    const auto test = Atm(12.18422897);
    CHECK(test.Value() == doctest::Approx(12.18422897));

    const auto ref = Pascals(1234567.0);
    CHECK(test.Data() == doctest::Approx(ref.Value()));
  }

  // test for PSI
  TEST_CASE("PSI") {
    const auto test = Psi(179.0588048);
    CHECK(test.Value() == doctest::Approx(179.05873445));

    const auto ref = Pascals(1234567.0);
    CHECK(test.Data() == doctest::Approx(ref.Value()));
  }

  // test to make sure the size of the class never exceeds the size of the data
  // member variable. Force all test cases to stop if it does.
  TEST_CASE("Size") {
    const auto temp = Pascals(1.0);
    REQUIRE(sizeof(temp) == sizeof(temp.Data()));
  }

  // test to make sure the three-way comparison operator (<=>) overload works as
  // it should.
  TEST_CASE("Three-Way Comparison Overload") {
    const auto tempLow = Pascals(1.0);
    const auto tempEq1 = Pascals(13.0);
    const auto tempEq2 = Pascals(13.0);
    CHECK(tempLow < tempEq1);
    CHECK(tempEq1 > tempLow);
    bool equivalence = ((tempEq1 <=> tempEq2) == 0);
    CHECK(equivalence);
  }
}
// NOLINTEND(modernize-use-trailing-return-type)

}  // namespace csm_units::test