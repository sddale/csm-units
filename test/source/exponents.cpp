#include "source/csm_units/exponents.hpp"

#include <doctest/doctest.h>

namespace csm_units::test {

// NOLINTBEGIN(modernize-use-trailing-return-type)
TEST_SUITE("Exponents") {
  TEST_CASE("Addition") {
    CHECK(std::is_same_v<
          ExponentsAdd<Exponents<1, 2, 3, 1, 1, 1>, Exponents<4, 5, 6>>,
          Exponents<5, 7, 9, 1, 1, 1>>);
  }
}
// NOLINTEND(modernize-use-trailing-return-type)

}  // namespace csm_units::test