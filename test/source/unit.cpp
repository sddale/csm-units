#include "source/csm_units/unit.hpp"

#include <doctest/doctest.h>

#include "source/csm_units/unitcast.hpp"

namespace csm_units::test {

// NOLINTBEGIN(modernize-use-trailing-return-type, misc-use-anonymous-namespace)

constexpr auto CHECK_TYPE = [](auto input, auto ref) {
  CHECK(std::is_same_v<std::remove_const_t<decltype(input)>,
                       std::remove_const_t<decltype(ref)>>);
};

constexpr auto CHECK_DBL_EQ = [](auto lhs, auto rhs) {
  CHECK_EQ(lhs, doctest::Approx(rhs));
};

TEST_SUITE("Unit") {
  TEST_CASE("Size") {
    const auto test = Kilogram(14.0);
    REQUIRE(sizeof(test) == sizeof(test.data));
  }

  TEST_CASE("Unit Tests") {
    SUBCASE("Unit-Unit Base Addition") {
      const auto kg_unit = Kilogram(3.0);
      const auto mass = Mass(4);
      const auto test = kg_unit + mass;
      CHECK_DBL_EQ(test.data, 7.0);
      CHECK_TYPE(test, Mass());
    }
    SUBCASE("Unit-Unit Addition") {
      const auto test = Gram(3.0) + Gram(4.0);
      CHECK_DBL_EQ(test.data, 0.007);
      CHECK_TYPE(test, Mass());
    }
  }

  TEST_CASE("Polished Test Case for psi and pascals") {
    using SqPressure = Exponents<-2, 2, -4, 0, 0, 0, 0>;

    const auto psi = Psi(31.6);
    const auto pascal = Pascal(23.5);
    SUBCASE("Conversion Checking") {
      // Pass pascals to psi and psi to pascals... to make sure conversion
      // works
      SUBCASE("Pressure->Psi") {
        const Psi test = Pressure(23.5);
        CHECK_DBL_EQ(test.data, 0.003408387);
        CHECK_TYPE(test, Psi());
      }
      SUBCASE("Pascal->Psi") {
        const Psi test = Pascal(23.5);
        CHECK_DBL_EQ(test.data, 0.003408387);
        CHECK_TYPE(test, Psi());
      }
      SUBCASE("Psi->Pascal") {
        const Pascal test = Psi(31.6);
        CHECK_DBL_EQ(test.data, 217874.3);
        CHECK_TYPE(test, Pascal());
      }
    }
    SUBCASE("PSI + PASCALS") {
      SUBCASE("Basic addition") {
        const auto test = psi + pascal;
        CHECK_DBL_EQ(test.data, 217897.8);
        CHECK_TYPE(test, Pressure());
      }
      SUBCASE("Force pascal result") {
        const Pascal test = psi + pascal;
        CHECK_DBL_EQ(test.data, 217897.8);
        CHECK_TYPE(test, Pascal());
      }
      SUBCASE("Force psi result") {
        const Psi test = psi + pascal;
        CHECK_DBL_EQ(test.data, 31.60340839);
        CHECK_TYPE(test, Psi());
      }
    }

    SUBCASE("PSI - PASCALS") {
      SUBCASE("Basic Subtraction") {
        const auto test = psi - pascal;
        CHECK_DBL_EQ(test.data, 217850.8);
        CHECK_TYPE(test, Pressure());
      }
      SUBCASE("Force pascal result") {
        const Pascal test = psi - pascal;
        CHECK_DBL_EQ(test.data, 217850.8);
        CHECK_TYPE(test, Pascal());
      }
      SUBCASE("Force psi result") {
        const Psi test = psi - pascal;
        CHECK_DBL_EQ(test.data, 31.596587195);
        CHECK_TYPE(test, Psi());
      }
    }

    SUBCASE("PASCALS - PSI") {
      SUBCASE("Basic Subtraction") {
        const auto test = pascal - psi;
        CHECK_DBL_EQ(test.data, -217850.8);
        CHECK_TYPE(test, Pressure());
      }
      SUBCASE("Force pascal result") {
        const Pascal test = pascal - psi;
        CHECK_DBL_EQ(test.data, -217850.8);
        CHECK_TYPE(test, Pascal());
      }
      SUBCASE("Force psi result") {
        const Psi test = pascal - psi;
        CHECK_DBL_EQ(test.data, -31.596587195);
        CHECK_TYPE(test, Psi());
      }
    }

    SUBCASE("PASCALS * PSI") {
      SUBCASE("Basic Multiplication") {
        const auto test = psi * pascal;
        CHECK_DBL_EQ(test.data, 5120046.05);
        CHECK_TYPE(test, UnitBase<SqPressure, double>());
      }
    }

    SUBCASE("PASCALS / PSI") {
      SUBCASE("Basic Division") {
        const auto test = pascal / psi;
        CHECK(test == doctest::Approx(0.000107860358));
      }
    }

    SUBCASE("Function Passing") {
      SUBCASE("Psi Parameter") {
        constexpr auto lambda = [](Psi input) { return input; };

        const auto test_pa = lambda(Pascal(23.5));
        CHECK_DBL_EQ(test_pa.data, 0.003408387);

        const auto test_psi = lambda(Psi(23.5));
        CHECK_DBL_EQ(test_psi.data, 23.5);
      }

      SUBCASE("Pascal Parameter") {
        constexpr auto lambda = [](Pascal input) { return input; };

        const auto test_pa = lambda(Pascal(31.6));
        CHECK_DBL_EQ(test_pa.data, 31.6);

        const auto test_psi = lambda(Psi(31.6));
        CHECK_DBL_EQ(test_psi.data, 217874.3);
      }

      SUBCASE("Base Pressure Parameter") {
        constexpr auto lambda = [](Pressure input) { return input; };

        const auto test_pa = lambda(Pascal(31.6));
        CHECK_DBL_EQ(test_pa.data, 31.6);

        const auto test_psi = lambda(Psi(31.6));
        CHECK_DBL_EQ(test_psi.data, 217874.3);
      }

      SUBCASE("Create a pascal from distance, time, and mass") {
        const auto dist = 3.0_m;
        const auto time = 2.0_s;

        const MPerS2 accel = dist / time / time;
        CHECK_DBL_EQ(accel.data, 0.75);

        const Newton force = accel * Kilogram(2);
        CHECK_DBL_EQ(force.data, 1.50);

        const auto area = 3.0_m * 3.0_m;
        const Pascal pres = force / area;
        CHECK_DBL_EQ(pres.data, 0.166667);

        const Pascal pres_lit =
            3.0_m * 2.0_kg / (2.0_s * 2.0_s * 3.0_m * 3.0_m);
        CHECK_DBL_EQ(pres_lit.data, 0.166667);
      }
    }
  }
}
//   TEST_CASE("Idea Test") {
//     const auto foo1 = Foo1(3.0);
//     const auto foo2 = Foo2(4.0);

//     const auto fooTest1 = foo1 + foo2;

//     const auto fooTest2 = foo2 + foo2;

//     CHECK_DBL_EQ(fooTest1.data,7.0);
//     CHECK(std::is_same_v<std::remove_const_t<decltype(fooTest1)>, Foo1>);

//     CHECK_DBL_EQ(fooTest2.data,8.0);
//     CHECK(std::is_same_v<std::remove_const_t<decltype(fooTest2)>, Foo1>);
//   }
// }

// NOLINTEND(modernize-use-trailing-return-type,misc-use-anonymous-namespace)

}  // namespace csm_units::test