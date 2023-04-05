#include "source/csm_units/unit.hpp"

#include <doctest/doctest.h>

#include "source/csm_units/unitcast.hpp"

namespace csm_units::test {

// NOLINTBEGIN(modernize-use-trailing-return-type, misc-use-anonymous-namespace)

TEST_SUITE("Unit") {
  TEST_CASE("Size") {
    const auto test =
        Unit<UnitBase<Exponents<14, 14, 14, 0, 0, 0, 0>, double>, "kg", double>(
            14.0);
    REQUIRE(sizeof(test) == sizeof(test.data));
  }

  TEST_CASE("Unit Tests") {
    SUBCASE("Unit-Unit Base Addition") {
      const auto kg_unit =
          Unit<UnitBase<Exponents<0, 1, 0, 0, 0, 0, 0>, double>, "kg", double>(
              3.0);
      const auto kg_unit_base =
          UnitBase<Exponents<0, 1, 0, 0, 0, 0, 0>, double>(4000.0);
      CHECK(true);

      const auto test = kg_unit_base + kg_unit;
      CHECK(test.data == doctest::Approx(7000.0));
      CHECK(std::is_same_v<std::remove_const_t<decltype(test)>,
                           std::remove_const_t<decltype(kg_unit_base)>>);
    }

    SUBCASE("Unit-Unit Addition") {
      const auto kg_unit1 =
          Unit<UnitBase<Exponents<0, 1, 0, 0, 0, 0, 0>, double>, "kg", double>(
              3.0);
      const auto kg_unit2 =
          Unit<UnitBase<Exponents<0, 1, 0, 0, 0, 0, 0>, double>, "kg", double>(
              4.0);
      CHECK(true);

      const Unit<UnitBase<Exponents<0, 1, 0, 0, 0, 0, 0>, double>, "kg", double>
          test = kg_unit1 + kg_unit2;
      CHECK(test.data == doctest::Approx(7.0));
      CHECK(std::is_same_v<std::remove_const_t<decltype(test)>,
                           std::remove_const_t<decltype(kg_unit1)>>);
    }
  }

  TEST_CASE("Polished Test Case for psi and pascals") {
    auto CHECKTYPE = [](auto input, auto ref) {
      CHECK(std::is_same_v<std::remove_const_t<decltype(input)>,
                           std::remove_const_t<decltype(ref)>>);
    };

    using SqPressure = Exponents<-2, 2, -4, 0, 0, 0, 0>;

    const auto psi = Psi(31.6);
    const auto pascal = Pascal(23.5);

    SUBCASE("PSI + PASCALS : Basic Addition") {
      const auto test = psi + pascal;

      CHECK(test.data == doctest::Approx(217897.8));
      CHECKTYPE(test, Pressure());
    }

    SUBCASE("PSI + PASCALS : Force Unit psi Addition") {
      const Psi test = psi + pascal;

      CHECK(test.data == doctest::Approx(31.60340839));
      CHECKTYPE(test, Psi());
    }

    SUBCASE("PSI + PASCALS : Force Unit pascals Addition") {
      const Pascal test = psi + pascal;

      CHECK(test.data == doctest::Approx(217897.8));
      CHECKTYPE(test, Pascal());
    }

    SUBCASE("PSI - PASCALS : Basic Subtraction") {
      const auto test = psi - pascal;

      CHECK(test.data == doctest::Approx(217850.8));
      CHECKTYPE(test, Pressure());
    }

    SUBCASE("PSI - PASCALS : Force Unit psi Subtraction") {
      const Psi test = psi - pascal;

      CHECK(test.data == doctest::Approx(31.596587195));
      CHECKTYPE(test, Psi());
    }

    SUBCASE("PSI - PASCALS : Force Unit pascals Addition") {
      const Pascal test = psi - pascal;

      CHECK(test.data == doctest::Approx(217850.8));
      CHECKTYPE(test, Pascal());
    }

    SUBCASE("PASCALS - PSI : Basic Addition") {
      const auto test = pascal - psi;

      CHECK(test.data == doctest::Approx(-217850.8));
      CHECKTYPE(test, Pressure());
    }

    SUBCASE("PASCALS - PSI : Force Unit psi Addition") {
      const Psi test = pascal - psi;

      CHECK(test.data == doctest::Approx(-31.596587195));
      CHECKTYPE(test, Psi());
    }

    SUBCASE("PASCALS - PSI : Force Unit pascals Addition") {
      const Pascal test = pascal - psi;

      CHECK(test.data == doctest::Approx(-217850.8));
      CHECKTYPE(test, Pascal());
    }
    SUBCASE("PASCALS * PSI : Basic Multiplication") {
      const auto test = psi * pascal;

      CHECK(test.data == doctest::Approx(5120046.05));
      CHECKTYPE(test, UnitBase<SqPressure, double>());

      SUBCASE("PASCALS * PSI : Basic Multiplication") {
        const auto test = psi * pascal;

        CHECK(test.data == doctest::Approx(5120046.05));
        CHECK(std::is_same_v<std::remove_const_t<decltype(test)>,
                             UnitBase<SqPressure, double>>);
      }

      SUBCASE("PSI / PASCALS : Basic Division") {
        const auto test = pascal / psi;

        CHECK(test == doctest::Approx(0.000107860358));
        CHECK(std::is_same_v<std::remove_const_t<decltype(test)>, double>);
      }

      SUBCASE("PASCALS * PSI : Basic Multiplication") {
        const auto test = psi * pascal;

        CHECK(test.data == doctest::Approx(5.12005e+06));
        CHECK(std::is_same_v<std::remove_const_t<decltype(test)>,
                             UnitBase<SqPressure, double>>);
      }

      SUBCASE("Conversion Checking") {
        // Pass pascals to psi and psi to pascals... to make sure conversion
        // works
        const Psi test1 = Pressure(23.5);
        const Psi test2 = Pascal(23.5);
        const Pascal test3 = Psi(31.6);

        CHECK(test1.data == doctest::Approx(0.003408387));
        CHECK(std::is_same_v<std::remove_const_t<decltype(test1)>, Psi>);

        CHECK(test2.data == doctest::Approx(0.003408387));
        CHECK(std::is_same_v<std::remove_const_t<decltype(test2)>, Psi>);

        CHECK(test3.data == doctest::Approx(217874.3));
        CHECK(std::is_same_v<std::remove_const_t<decltype(test3)>, Pascal>);
      }

      SUBCASE("Function Passing") {
        SUBCASE("Psi Parameter") {
          auto lambda = [](Psi input) -> Psi { return input; };

          const auto test_pa = lambda(Pascal(23.5));
          CHECK(test_pa.data == doctest::Approx(0.003408387));

          const auto test_psi = lambda(Psi(23.5));
          CHECK(test_psi.data == doctest::Approx(23.5));
        }

        SUBCASE("Pascal Parameter") {
          auto lambda = [](Pascal input) -> Pascal { return input; };

          const auto test_pa = lambda(Pascal(31.6));
          CHECK(test_pa.data == doctest::Approx(31.6));

          const auto test_psi = lambda(Psi(31.6));
          CHECK(test_psi.data == doctest::Approx(217874.3));
        }

        SUBCASE("Base Pressure Parameter") {
          auto lambda = [](Pressure input) { return input; };

          const auto test_pa = lambda(Pascal(31.6));
          CHECK(test_pa.data == doctest::Approx(31.6));

          const auto test_psi = lambda(Psi(31.6));
          CHECK(test_psi.data == doctest::Approx(217874.3));
        }

        SUBCASE("Disallow Passing of Mismatched Dimensioned Parameter") {
          // auto lambda = [](Pressure input) { return input;
          // };

          // auto test_m = lambda(Meter(10));
          // auto foo = Meter(Pascal(2));
          // CHECK(test_m.data == doctest::Approx(31.6));
        }
      }
    }
  }
}
//   TEST_CASE("Idea Test") {
//     const auto foo1 = Foo1(3.0);
//     const auto foo2 = Foo2(4.0);

//     const auto fooTest1 = foo1 + foo2;

//     const auto fooTest2 = foo2 + foo2;

//     CHECK(fooTest1.data == doctest::Approx(7.0));
//     CHECK(std::is_same_v<std::remove_const_t<decltype(fooTest1)>, Foo1>);

//     CHECK(fooTest2.data == doctest::Approx(8.0));
//     CHECK(std::is_same_v<std::remove_const_t<decltype(fooTest2)>, Foo1>);
//   }
// }

// NOLINTEND(modernize-use-trailing-return-type,misc-use-anonymous-namespace)

}  // namespace csm_units::test