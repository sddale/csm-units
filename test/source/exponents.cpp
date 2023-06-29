#include <doctest/doctest.h>

#include <csm_units/units.hpp>
#include <type_traits>

// NOLINTBEGIN(modernize-use-trailing-return-type)
TEST_SUITE("Exponents") {
  using namespace csm_units;
  TEST_CASE("Addition") {
    CHECK(std::is_same_v<
          ExponentsAdd<Exponents<1, 2, 3, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1>,
                       Exponents<4, 5, 6, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1>>,
          Exponents<5, 7, 9, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1>>);
  }

  TEST_CASE("Subtraction") {
    CHECK(std::is_same_v<
          ExponentsSubtract<Exponents<1, 2, 3, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1>,
                            Exponents<4, 5, 6, 0, 0, 0, 0>>,
          Exponents<-3, -3, -3, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1>>);
  }

  TEST_CASE("Flipping") {
    CHECK(std::is_same_v<
          ExponentsFlip<Exponents<1, 3, 5, 0, 0, 0, 0, 2, 4, 6, 1, 1, 1, 1>>,
          Exponents<-1, -3, -5, 0, 0, 0, 0, 2, 4, 6, 1, 1, 1, 1>>);
  }
}
// NOLINTEND(modernize-use-trailing-return-type)
