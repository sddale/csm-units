#include <doctest/doctest.h>

#include <ratio>
#include <source/csm_units/sci_no.hpp>

#ifndef CSMUNITS_VALUE_TYPE
#define CSMUNITS_VALUE_TYPE double
#endif

namespace csm_units::test {

// NOLINTBEGIN(modernize-use-trailing-return-type, misc-use-anonymous-namespace)

TEST_SUITE("SciNo") {
  using namespace csm_units;
  TEST_CASE("Equal") {
    using RHS = SciNo<std::ratio<2, 3>, 2>;
    static_assert(SciNoEqual<SciNo<std::ratio<2, 3>, 2>, RHS>);
    static_assert(not SciNoNotEqual<SciNo<std::ratio<2, 3>, 2>, RHS>);

    static_assert(SciNoEqual<SciNo<std::ratio<4, 6>, 2>, RHS>);
    static_assert(not SciNoNotEqual<SciNo<std::ratio<4, 6>, 2>, RHS>);

    static_assert(SciNoEqual<SciNo<std::ratio<40, 6>, 1>, RHS>);
    static_assert(not SciNoEqual<SciNo<std::ratio<2, 4>, 2>, RHS>);

    static_assert(not SciNoEqual<SciNo<std::ratio<4, 3>, 2>, RHS>);
    static_assert(SciNoNotEqual<SciNo<std::ratio<2, 4>, 2>, RHS>);

    static_assert(not SciNoEqual<SciNo<std::ratio<2, 3>, -2>, RHS>);
    static_assert(SciNoNotEqual<SciNo<std::ratio<2, 3>, -2>, RHS>);

    static_assert(not SciNoEqual<SciNo<std::ratio<40, 6>, 2>, RHS>);
    static_assert(SciNoNotEqual<SciNo<std::ratio<40, 6>, 2>, RHS>);
  }

  TEST_CASE("Constructor and reductions") {
    SUBCASE("No reduction") {
      const int num = 5;
      const int den = 4;
      const int order = 1;
      static_assert(csm_units::SciNo<std::ratio<num, den>, order>::ord ==
                    order);
      static_assert(
          std::same_as<csm_units::SciNo<std::ratio<num, den>, order>::MagType,
                       std::ratio<num, den>>);
    }
    SUBCASE("Input mag < 1") {
      using LHS = csm_units::SciNo<std::ratio<3, 4>, 1>;
      static_assert(LHS::ord == 0);
      static_assert(std::ratio_equal_v<LHS::MagType, std::ratio<15, 2>>);
    }
    SUBCASE("Input mag < 0.1") {
      using LHS = csm_units::SciNo<std::ratio<3, 40>, 1>;
      static_assert(LHS::ord == -1);
      static_assert(std::ratio_equal_v<LHS::MagType, std::ratio<15, 2>>);
    }
    SUBCASE("Input mag > -1 && < 0") {
      using LHS = csm_units::SciNo<std::ratio<-3, 4>, 1>;
      static_assert(LHS::ord == 0);
      static_assert(std::ratio_equal_v<LHS::MagType, std::ratio<-15, 2>>);
    }
    SUBCASE("Input mag > 10") {
      using LHS = csm_units::SciNo<std::ratio<50, 3>, 1>;
      static_assert(LHS::ord == 2);
      static_assert(std::ratio_equal_v<LHS::MagType, std::ratio<5, 3>>);
    }
    SUBCASE("Input mag > 100") {
      using LHS = csm_units::SciNo<std::ratio<500, 3>, 1>;
      static_assert(LHS::ord == 3);
      static_assert(std::ratio_equal_v<LHS::MagType, std::ratio<5, 3>>);
    }
    SUBCASE("Order = 2, mag > 10") {
      using LHS = csm_units::SciNo<std::ratio<50, 3>, 2>;
      static_assert(LHS::ord == 3);
      static_assert(std::ratio_equal_v<LHS::MagType, std::ratio<5, 3>>);
    }
    SUBCASE("Order = -1, mag > 10") {
      using LHS = csm_units::SciNo<std::ratio<50, 3>, -1>;
      static_assert(LHS::ord == 0);
      static_assert(std::ratio_equal_v<LHS::MagType, std::ratio<5, 3>>);
    }
  }
  TEST_CASE("Multiply") {
    using LHS = SciNo<std::ratio<3, 4>, 0>;
    using RHS = SciNo<std::ratio<4, 3>, 0>;
    static_assert(SciNoEqual<SciNoMultiply<LHS, RHS>, SciNo<std::ratio<1>, 0>>);
  }

  TEST_CASE("Divide") {
    using LHS = SciNo<std::ratio<3, 4>, 0>;
    using RHS = SciNo<std::ratio<4, 3>, 0>;
    static_assert(
        SciNoEqual<SciNoDivide<LHS, RHS>, SciNo<std::ratio<9, 16>, 0>>);
    static_assert(
        SciNoEqual<SciNoDivide<LHS, RHS>, SciNo<std::ratio<45, 8>, -1>>);
  }

  // TEST_CASE("To Ratio") {
  //   {
  //     const auto scino = SciNo<std::ratio<3, 4>, 0>();

  //     static_assert(std::same_as<decltype(ToRatio(scino)), std::ratio<3,
  //     4>>);
  //   }
  //   {
  //     const auto scino = SciNo<std::ratio<30, 4>, 0>();

  //     static_assert(std::same_as<decltype(ToRatio(scino)), std::ratio<30,
  //     4>>);
  //   }

  //   {
  //     const auto scino = SciNo<std::ratio<3, 40>, 0>();

  //     static_assert(std::same_as<decltype(ToRatio(scino)), std::ratio<3,
  //     40>>);
  //   }
  // }
}

// NOLINTEND(modernize-use-trailing-return-type, misc-use-anonymous-namespace)

}  // namespace csm_units::test