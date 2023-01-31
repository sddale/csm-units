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
    CHECK(test.data == doctest::Approx(1234567.0));
  }

  // test for Bar
  TEST_CASE("Bar") {
    const auto test = Bar(12.34567);
    CHECK(test.data == doctest::Approx(12.34567));

    const auto ref = Pascals(1234567.0);
    CHECK(BarConverter::ConvertValue(test.data) == doctest::Approx(ref.data));
  }

  // test for ATM
  TEST_CASE("ATM") {
    const auto test = Atm(12.18422897);
    CHECK(test.data == doctest::Approx(12.18422897));

    const auto ref = Pascals(1234567.0);
    CHECK(AtmConverter::ConvertValue(test.data) == doctest::Approx(ref.data));
  }

  // test for PSI
  TEST_CASE("PSI") {
    const auto test = Psi(179.0588048);
    CHECK(test.data == doctest::Approx(179.05873445));

    const auto ref = Pascals(1234567.0);
    CHECK(PsiConverter::ConvertValue(test.data) == doctest::Approx(ref.data));
  }

  // test to make sure the size of the class never exceeds the size of the data
  // member variable. Force all test cases to stop if it does.
  TEST_CASE("Size") {
    const auto test = Pascals(1.0);
    REQUIRE(sizeof(test) == sizeof(test.data));
  }

  // test to make sure the three-way comparison operator (<=>) overload works as
  // it should. As well as the equality operator overload.
  TEST_CASE("Comparison Overload") {
    // put these here because all three sub cases will use them
    const auto testLow = Pascals(1.0);
    const auto test = Pascals(13.0);

    SUBCASE("Testing Pressure to Pressure Comparisons") {
      // put these in here because the other sub cases don't need them

      const auto testEq2 = Pascals(13.0);

      CHECK(testLow <= test);
      CHECK(testLow < test);
      CHECK(test >= testLow);
      CHECK(test > testLow);
      CHECK(test == testEq2);
      CHECK_FALSE(test != testEq2);
    }

    SUBCASE("Testing Pressure to Primitive Data Types Comparisons") {
      // const auto my_temperature =
      //  273.15_F;                // "user-defined string literal operators"

      SUBCASE("Testing Pressure to Int Comparisons") {
        // put these in here because the other sub cases don't need them
        const auto intLower = 5;
        const auto intEq = 13;

        CHECK(test >= intLower);  // "C++ Feature: Type promotion"
        CHECK(test > intLower);
        CHECK(intLower <= test);  // look into why this works
        CHECK(intLower < test);
        CHECK(intEq == test);
        CHECK_FALSE(test != intEq);
      }

      SUBCASE("Testing Pressure to Double Comparisons") {
        // put these in here because the other sub cases don't need them
        const auto doubleLower = 5.0;
        const auto doubleEq = 13.0;
        const auto doubleHigher = 15.0;

        SUBCASE("Pressure to Double") {
          CHECK(test <= doubleHigher);
          CHECK(test < doubleHigher);
          CHECK(test >= doubleLower);
          CHECK(test > doubleLower);
          CHECK(doubleEq == test);
          CHECK_FALSE(doubleEq != test);
        }

        SUBCASE("Double to Pressure") {
          CHECK(doubleLower <= test);
          CHECK(doubleLower < test);
          CHECK(test >= doubleLower);
          CHECK(test > doubleLower);
          CHECK(doubleEq == test);
          CHECK_FALSE(doubleEq != test);
        }
      }
    }

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