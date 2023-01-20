#include "csm_units/pressure.hpp"

#include <doctest/doctest.h>

#include <cmath>

namespace csm_units::test {
TEST_CASE("Pressure") {
  // test to make user each data unit can go back and forth by creating each
  // type then asking for it back

  // test for Pascals
  auto pascalsTest = Pascals(1234567.0);
  CHECK(std::abs(pascalsTest.getData() - 1234567.0) < 0.001);

  // test for Bar
  auto barTest = Bar(12.34567);
  CHECK(std::abs(barTest.getData() - 12.34567) < 0.001);

  // test for ATM
  auto atmTest = ATM(12.18422897);
  CHECK(std::abs(atmTest.getData() - 12.18422897) < 0.001);

  // test for PSI
  auto psiTest = PSI(179.0588048);
  CHECK(std::abs(psiTest.getData() - 179.05873445) < 0.001);

  // test for PSIG
  auto psigTest = PSIG(179.0588048);
  CHECK(std::abs(psigTest.getData() - 179.05873445) < 0.001);

  // all of these should be the same just in their respective units. So, the
  // below will test to make sure that they are all actually equivalent.
  CHECK(std::abs(pascalsTest.getData() - barTest.getDataInPascals()) < 0.001);
  CHECK(std::abs(pascalsTest.getData() - atmTest.getDataInPascals()) < 0.001);
  CHECK(std::abs(pascalsTest.getData() - psiTest.getDataInPascals()) < 0.5);
  CHECK(std::abs(pascalsTest.getData() - psigTest.getDataInPascals()) < 0.5);
}
}  // namespace csm_units::test