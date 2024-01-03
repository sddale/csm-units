#include <doctest/doctest.h>

#include <source/csm_units/dimension.hpp>
#include <type_traits>

namespace csm_units::test {

// NOLINTBEGIN(modernize-use-trailing-return-type,misc-use-anonymous-namespace)
TEST_SUITE("Dimension") {
  using namespace csm_units;
  TEST_CASE("Addition") {
    CHECK(std::is_same_v<
          DimensionAdd<Dimension<std::ratio<1>, std::ratio<2>, std::ratio<3>>,
                       Dimension<std::ratio<4>, std::ratio<5>, std::ratio<6>>>,
          Dimension<std::ratio<5>, std::ratio<7>, std::ratio<9>>>);
  }

  TEST_CASE("Subtraction") {
    CHECK(std::is_same_v<
          DimensionSubtract<
              Dimension<std::ratio<1>, std::ratio<2>, std::ratio<7>>,
              Dimension<std::ratio<2>, std::ratio<5>, std::ratio<3>>>,
          Dimension<std::ratio<-1>, std::ratio<-3>, std::ratio<4>>>);
  }

  TEST_CASE("Flipping") {
    CHECK(std::is_same_v<
          DimensionFlip<
              Dimension<std::ratio<1, 2>, std::ratio<3, 4>, std::ratio<5, 6>>>,
          Dimension<std::ratio<-1, 2>, std::ratio<-3, 4>, std::ratio<-5, 6>>>);
  }
}
// NOLINTEND(modernize-use-trailing-return-type,misc-use-anonymous-namespace)

}  // namespace csm_units::test