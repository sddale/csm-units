#include <csm_units/units.hpp>
#include <doctest/doctest.h>

namespace csm_units::test {

// NOLINTBEGIN(modernize-use-trailing-return-type)
TEST_SUITE("Pressure") {
  // test to make user each data unit can go back and forth by creating each
  // type then asking for it back

  // TEST_CASE("Pascal") {  // test for Pascals
  //   const auto test = Pascals(1234567.0);
  //   CHECK(test.Value() == doctest::Approx(1234567.0));
  // }

  // // test for Bar
  // TEST_CASE("Bar") {
  //   const auto test = Bar(12.34567);
  //   CHECK(test.Value() == doctest::Approx(12.34567));

  //   const auto ref = Pascals(1234567.0);
  //   CHECK(test.Data() == doctest::Approx(ref.Value()));
  // }

  // // test for ATM
  // TEST_CASE("ATM") {
  //   const auto test = Atm(12.18422897);
  //   CHECK(test.Value() == doctest::Approx(12.18422897));

  //   const auto ref = Pascals(1234567.0);
  //   CHECK(test.Data() == doctest::Approx(ref.Value()));
  // }

  // // test for PSI
  // TEST_CASE("PSI") {
  //   const auto test = Psi(179.0588048);
  //   CHECK(test.Value() == doctest::Approx(179.05873445));

  //   const auto ref = Pascals(1234567.0);
  //   CHECK(test.Data() == doctest::Approx(ref.Value()));
  // }

  // // test to make sure the size of the class never exceeds the size of the
  // data
  // // member variable. Force all test cases to stop if it does.
  // TEST_CASE("Size") {
  //   const auto test = Pascals(1.0);
  //   REQUIRE(sizeof(test) == sizeof(test.Data()));
  // }

  // test to make sure the three-way comparison operator (<=>) overload works as
  // it should. As well as the equality operator overload.
  TEST_CASE("Comparison Overload") {
    const auto testLow = Pascals(1.0);
    const auto testEq1 = Pascals(13.0);
    const auto testEq2 = Pascals(13.0);
    CHECK(testLow <= testEq1);
    CHECK(testEq1 >= testLow);
    CHECK(testEq1 == testEq2);

    const auto intLower = 5L;
    const auto doubleLower = 5.0;
    // const auto my_temperature =
    //  273.15_F;                // "user-defined string literal operators"
    CHECK(testEq1 >= intLower);  // "C++ Feature: Type promotion"
    CHECK(testEq1 >= doubleLower);
    CHECK(intLower <= testEq1);  // look into why this works
    CHECK(doubleLower <= testEq1);

    const auto intEq = 13;
    const auto doubleEq = 13.0;
    CHECK(intEq == testEq1);
    CHECK(doubleEq == testEq1);

    // TODO(Sander): test Heterogenous unit type comparisons (ie comparing
    // between units)
  }

  // test to make sure the copy constructor works.
  TEST_CASE("Copy Constructor") {
    const auto test = Pascals(1.0);
    const auto copyTest = Pascals(test);
    const auto copyTest2 = Bar(test);
    CHECK(test == copyTest);
    CHECK(test == copyTest2);
  }

  // test to make sure the move constructor works.
  TEST_CASE("Move Constructor") {
    // not really sure how to go about testing this
  }
}
// NOLINTEND(modernize-use-trailing-return-type)
}  // namespace csm_units::test