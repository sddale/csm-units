#include <doctest/doctest.h>

#include <source/csm_units/dimension.hpp>
#include <type_traits>

namespace csm_units::test {

// NOLINTBEGIN(modernize-use-trailing-return-type,misc-use-anonymous-namespace)
TEST_SUITE("Dimension") {
  using namespace csm_units;
  TEST_CASE("Addition") {
    CHECK(std::is_same_v<
          DimensionAdd<Dimension<1, 2, 3, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1>,
                       Dimension<4, 5, 6, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1>>,
          Dimension<5, 7, 9, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1>>);
  }

  TEST_CASE("Subtraction") {
    CHECK(std::is_same_v<
          DimensionSubtract<Dimension<1, 2, 3, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1>,
                            Dimension<4, 5, 6, 0, 0, 0, 0>>,
          Dimension<-3, -3, -3, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1>>);
  }

  TEST_CASE("Flipping") {
    CHECK(std::is_same_v<
          DimensionFlip<Dimension<1, 3, 5, 0, 0, 0, 0, 2, 4, 6, 1, 1, 1, 1>>,
          Dimension<-1, -3, -5, 0, 0, 0, 0, 2, 4, 6, 1, 1, 1, 1>>);
  }
}

// NOLINTEND(modernize-use-trailing-return-type,misc-use-anonymous-namespace)

}  // namespace csm_units::test