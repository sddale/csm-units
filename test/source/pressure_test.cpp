
#include "../../include/csm_units/pressure.hpp"

#include <cmath>

#include "../../build/_deps/doctest-src/doctest/doctest.h"

namespace csm_units::test {

// NOLINTBEGIN(modernize-use-trailing-return-type)
TEST_SUITE("Pressure") {
  // test to make user each data unit can go back and forth by creating each
  // type then asking for it back

  TEST_CASE("Pascal") {  // test for Pascals
    auto test = Pascals(1234567.0);
    CHECK(test.Value() == doctest::Approx(1234567.0));
  }

  // test for Bar
  TEST_CASE("Bar") {
    auto test = Bar(12.34567);
    CHECK(test.Value() == doctest::Approx(12.34567));

    auto ref = Pascals(1234567.0);
    CHECK(test.Data() == doctest::Approx(ref.Value()));
  }

  // test for ATM
  TEST_CASE("ATM") {
    auto test = Atm(12.18422897);
    CHECK(test.Value() == doctest::Approx(12.18422897));

    auto ref = Pascals(1234567.0);
    CHECK(test.Data() == doctest::Approx(ref.Value()));
  }

  // test for PSI
  TEST_CASE("PSI") {
    const auto test = Psi(179.0588048);
    CHECK(test.Value() == doctest::Approx(179.05873445));

    const auto ref = Pascals(1234567.0);
    CHECK(test.Data() == doctest::Approx(ref.Value()));
  }
}
// NOLINTEND(modernize-use-trailing-return-type)

}  // namespace csm_units::test