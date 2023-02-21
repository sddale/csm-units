#include <doctest/doctest.h>

#include <csm_units/units.hpp>

namespace csm_units::test {

template <int LP, int MP, int TP>
using DBasic =
    Derived<Base<DimLength>, LP, Base<DimMass>, MP, Base<DimTime>, TP, double>;

// NOLINTBEGIN(modernize-use-trailing-return-type)
TEST_SUITE("Derived") {
  // Tests to make sure that the derived class is working the way we expect

  // test to make sure the size of the class never exceeds the size of the data
  // member variable. Force all test cases to stop if it does.
  TEST_CASE("Size") {
    const auto test = DBasic<14, 14, 14>(14.0);
    REQUIRE(sizeof(test) == sizeof(test.data));
  }

  TEST_CASE("Objects") {
    SUBCASE("DimLength") {
      const auto testLengthPow1 = DBasic<1, 0, 0>(13.0);

      const auto testLengthPow2 = DBasic<2, 0, 0>(13.0);

      CHECK(testLengthPow1.data == doctest::Approx(13.0));
      CHECK(testLengthPow2.data == doctest::Approx(13.0));
    }

    SUBCASE("DimMass") {
      const auto testMassPow1 = DBasic<0, 1, 0>(13.0);

      const auto testMassPow2 = DBasic<0, 2, 0>(13.0);

      CHECK(testMassPow1.data == doctest::Approx(13.0));
      CHECK(testMassPow2.data == doctest::Approx(13.0));
    }

    SUBCASE("DimTime") {
      const auto testTimePow1 = DBasic<0, 0, 1>(13.0);

      const auto testTimePow2 = DBasic<0, 0, 2>(13.0);

      CHECK(testTimePow1.data == doctest::Approx(13.0));
      CHECK(testTimePow2.data == doctest::Approx(13.0));
    }

    SUBCASE("Mix of All 3") {
      const auto length1Mass1Time1 = DBasic<1, 1, 1>(13.0);

      const auto length2Mass2Time2 = DBasic<2, 2, 2>(13.0);

      const auto arbitraryMixUp = DBasic<3, 1, 4>(13.0);

      CHECK(length1Mass1Time1.data == doctest::Approx(13.0));
      CHECK(length2Mass2Time2.data == doctest::Approx(13.0));
      CHECK(arbitraryMixUp.data == doctest::Approx(13.0));
    }
  }

  TEST_CASE("Division") {
    const auto length2Mass2 = DBasic<2, 2, 0>(20.0);
    const auto length1 = DBasic<1, 0, 0>(2.0);
    const auto mass1 = DBasic<0, 1, 0>(10.0);
    const auto baseDimLength = Base<DimLength>(4.0);
    const auto baseDimMass = Base<DimMass>(2.0);

    const auto quotientDerivedDerived = length2Mass2 / mass1;
    const auto quotientDerivedBase = length2Mass2 / baseDimLength;
    const auto quotientBaseDerived = baseDimLength / length1;
    const auto quotientBaseBase = baseDimLength / baseDimMass;
    const auto quotientDerivedDouble = length2Mass2 / 10.0;
    const auto quotientDoubleDerived = 40.0 / length2Mass2;

    CHECK(quotientDerivedDerived.data == doctest::Approx(2.0));
    CHECK(quotientDerivedBase.data == doctest::Approx(5.0));
    CHECK(quotientBaseDerived.data == doctest::Approx(2.0));
    CHECK(quotientBaseBase.data == doctest::Approx(2.0));
    CHECK(quotientDerivedDouble.data == doctest::Approx(2.0));
    CHECK(quotientDoubleDerived.data == doctest::Approx(2.0));

    CHECK(std::is_same_v<std::remove_const_t<decltype(quotientDerivedDerived)>,
                         DBasic<2, 1, 0>>);
    CHECK(std::is_same_v<std::remove_const_t<decltype(quotientDerivedBase)>,
                         DBasic<1, 2, 0>>);
    CHECK(std::is_same_v<std::remove_const_t<decltype(quotientBaseDerived)>,
                         DBasic<0, 0, 0>>);
    CHECK(std::is_same_v<std::remove_const_t<decltype(quotientBaseBase)>,
                         DBasic<1, -1, 0>>);
    CHECK(std::is_same_v<decltype(quotientDerivedDouble),
                         decltype(length2Mass2)>);
    CHECK(std::is_same_v<std::remove_const_t<decltype(quotientDoubleDerived)>,
                         DBasic<-2, -2, 0>>);
  }
}
// NOLINTEND(modernize-use-trailing-return-type)
}  // namespace csm_units::test