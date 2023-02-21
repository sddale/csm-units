#include <doctest/doctest.h>

#include <concepts>
#include <csm_units/units.hpp>

namespace csm_units::test {

// NOLINTBEGIN(modernize-use-trailing-return-type)
TEST_SUITE("Derived") {
  // Tests to make sure that the derived class is working the way we expect

  TEST_CASE("Objects") {
    SUBCASE("DimLength") {
      const auto testLengthPow1 =
          Derived<DimLength, 1, DimMass, 0, DimTime, 0>(13.0);

      const auto testLengthPow2 =
          Derived<DimLength, 2, DimMass, 0, DimTime, 0>(13.0);

      CHECK(testLengthPow1.data == doctest::Approx(13.0));
      CHECK(testLengthPow2.data == doctest::Approx(13.0));
    }

    SUBCASE("DimMass") {
      const auto testMassPow1 =
          Derived<DimLength, 1, DimMass, 0, DimTime, 0>(13.0);

      const auto testMassPow2 =
          Derived<DimLength, 2, DimMass, 0, DimTime, 0>(13.0);

      CHECK(testMassPow1.data == doctest::Approx(13.0));
      CHECK(testMassPow2.data == doctest::Approx(13.0));
    }

    SUBCASE("DimTime") {
      const auto testTimePow1 =
          Derived<DimLength, 1, DimMass, 0, DimTime, 0>(13.0);

      const auto testTimePow2 =
          Derived<DimLength, 2, DimMass, 0, DimTime, 0>(13.0);

      CHECK(testTimePow1.data == doctest::Approx(13.0));
      CHECK(testTimePow2.data == doctest::Approx(13.0));
    }

    SUBCASE("Mix of All 3") {
      const auto length1Mass1Time1 =
          Derived<DimLength, 1, DimMass, 1, DimTime, 1>(13.0);

      const auto length2Mass2Time2 =
          Derived<DimLength, 2, DimMass, 2, DimTime, 2>(13.0);

      const auto arbitraryMixUp =
          Derived<DimLength, 3, DimMass, 1, DimTime, 4>(13.0);

      CHECK(length1Mass1Time1.data == doctest::Approx(13.0));
      CHECK(length2Mass2Time2.data == doctest::Approx(13.0));
      CHECK(arbitraryMixUp.data == doctest::Approx(13.0));
    }
  }

  TEST_CASE("Division") {
    const auto length2Mass2 =
        Derived<Base<DimLength>, 2, Base<DimMass>, 2, Base<DimTime>, 0>(20.0);
    const auto length1 =
        Derived<Base<DimLength>, 1, Base<DimMass>, 0, Base<DimTime>, 0>(2.0);
    const auto mass1 =
        Derived<Base<DimLength>, 0, Base<DimMass>, 1, Base<DimTime>, 0>(10.0);
    const auto baseDimLength = Base<DimLength>(4.0);

    // why does the below not work?
    const auto quotientDerivedDerived = length2Mass2 / mass1;
    const auto quotientDerivedBase = length2Mass2 / baseDimLength;
    const auto quotientBaseDerived = baseDimLength / length1;

    CHECK(quotientDerivedDerived.data == doctest::Approx(2.0));
    CHECK(quotientDerivedBase.data == doctest::Approx(5.0));
    CHECK(quotientBaseDerived.data == doctest::Approx(2.0));

    CHECK(std::is_same_v<decltype(quotientDerivedDerived),
                         const Derived<Base<DimLength>, 2, Base<DimMass>, 1,
                                       Base<DimTime>, 0>>);
    CHECK(std::is_same_v<decltype(quotientDerivedBase),
                         const Derived<Base<DimLength>, 1, Base<DimMass>, 2,
                                       Base<DimTime>, 0>>);
    CHECK(std::is_same_v<decltype(quotientBaseDerived),
                         const Derived<Base<DimLength>, 0, Base<DimMass>, 0,
                                       Base<DimTime>, 0>>);
  }
}
// NOLINTEND(modernize-use-trailing-return-type)
}  // namespace csm_units::test