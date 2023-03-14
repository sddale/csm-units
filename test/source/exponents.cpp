#include "source/csm_units/exponents.hpp"

#include <doctest/doctest.h>

#include <type_traits>

namespace csm_units::test {

// NOLINTBEGIN(modernize-use-trailing-return-type)

TEST_SUITE("Exponents") {
  TEST_CASE("Addition") {
    CHECK(std::is_same_v<
          ExponentsAdd<Exponents<1, 2, 3, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0>,
                       Exponents<4, 5, 6, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0>>,
          Exponents<5, 7, 9, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0>>);
  }

  TEST_CASE("Subtraction") {
    CHECK(std::is_same_v<
          ExponentsSubtract<Exponents<1, 2, 3, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0>,
                            Exponents<4, 5, 6, 0, 0, 0, 0>>,
          Exponents<-3, -3, -3, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0>>);
  }

  TEST_CASE("Flipping") {
    CHECK(std::is_same_v<
          ExponentsFlip<Exponents<1, 3, 5, 0, 0, 0, 0 2, 4, 6, 0, 0, 0, 0>>,
          Exponents<-1, -3, -5, 0, 0, 0, 0, 2, 4, 6, 0, 0, 0, 0>>);
  }
}

// NOLINTEND(modernize-use-trailing-return-type)

}  // namespace csm_units::test