#include "source/csm_units/unit.hpp"

#include <doctest/doctest.h>

#include "source/csm_units/unitcast.hpp"

namespace csm_units::test {

// NOLINTBEGIN(modernize-use-trailing-return-type)

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
    using Psi =
        Unit<UnitBase<Exponents<-1, 1, -2, 0, 0, 0, 0>, double>, "psi", double>;

    using Pascals = Unit<UnitBase<Exponents<-1, 1, -2, 0, 0, 0, 0>, double>,
                         "pascals", double>;

    const auto psi = Psi(31.6);
    const auto pascals = Pascals(23.5);

    SUBCASE("PSI + PASCALS : Basic Addition") {
      const auto test = psi + pascals;

      CHECK(test.data == doctest::Approx(217897.8));
      CHECK(std::is_same_v<std::remove_const_t<decltype(test)>,
                           UnitBase<Exponents<-1, 1, -2, 0, 0, 0, 0>, double>>);
    }

    SUBCASE("PSI + PASCALS : Force Unit psi Addition") {
      const Psi test = psi + pascals;

      CHECK(test.data == doctest::Approx(31.60340839));
      CHECK(std::is_same_v<std::remove_const_t<decltype(test)>, Psi>);
    }

    SUBCASE("PSI + PASCALS : Force Unit pascals Addition") {
      const Pascals test = psi + pascals;

      CHECK(test.data == doctest::Approx(217897.8));
      CHECK(std::is_same_v<std::remove_const_t<decltype(test)>, Pascals>);
    }

    SUBCASE("PSI - PASCALS : Basic Addition") {
      const auto test = psi - pascals;

      CHECK(test.data == doctest::Approx(217850.8));
      CHECK(std::is_same_v<std::remove_const_t<decltype(test)>,
                           UnitBase<Exponents<-1, 1, -2, 0, 0, 0, 0>, double>>);
    }

    SUBCASE("PSI - PASCALS : Force Unit psi Addition") {
      const Psi test = psi - pascals;

      CHECK(test.data == doctest::Approx(31.596587195));
      CHECK(std::is_same_v<std::remove_const_t<decltype(test)>, Psi>);
    }

    SUBCASE("PSI - PASCALS : Force Unit pascals Addition") {
      const Pascals test = psi - pascals;

      CHECK(test.data == doctest::Approx(217850.8));
      CHECK(std::is_same_v<std::remove_const_t<decltype(test)>, Pascals>);
    }

    SUBCASE("PASCALS - PSI : Basic Addition") {
      const auto test = pascals - psi;

      CHECK(test.data == doctest::Approx(-217850.8));
      CHECK(std::is_same_v<std::remove_const_t<decltype(test)>,
                           UnitBase<Exponents<-1, 1, -2, 0, 0, 0, 0>, double>>);
    }

    SUBCASE("PASCALS - PSI : Force Unit psi Addition") {
      const Psi test = pascals - psi;

      CHECK(test.data == doctest::Approx(-31.596587195));
      CHECK(std::is_same_v<std::remove_const_t<decltype(test)>, Psi>);
    }

    SUBCASE("PASCALS - PSI : Force Unit pascals Addition") {
      const Pascals test = pascals - psi;

      CHECK(test.data == doctest::Approx(-217850.8));
      CHECK(std::is_same_v<std::remove_const_t<decltype(test)>, Pascals>);
    }

    SUBCASE("PSI * PASCALS : Basic Multiplication") {
      const auto test = pascals * psi;

      CHECK(test.data == doctest::Approx(5120046.05));
      CHECK(std::is_same_v<std::remove_const_t<decltype(test)>,
                           UnitBase<Exponents<-2, 2, -4, 0, 0, 0, 0>, double>>);
    }

    SUBCASE("PASCALS * PSI : Basic Multiplication") {
      const auto test = psi * pascals;

      CHECK(test.data == doctest::Approx(5120046.05));
      CHECK(std::is_same_v<std::remove_const_t<decltype(test)>,
                           UnitBase<Exponents<-2, 2, -4, 0, 0, 0, 0>, double>>);
    }

    SUBCASE("PSI / PASCALS : Basic Division") {
      const auto test = pascals / psi;

      CHECK(test == doctest::Approx(0.000107860358));
      CHECK(std::is_same_v<std::remove_const_t<decltype(test)>, double>);
    }

    SUBCASE("PASCALS * PSI : Basic Multiplication") {
      const auto test = psi / pascals;

      CHECK(test == doctest::Approx(9271.24680851));
      CHECK(std::is_same_v<std::remove_const_t<decltype(test)>, double>);
    }

    SUBCASE("Conversion Checking") {
      // Pass pascals to psi and psi to pascals... to make sure conversion works
      const Psi test1 =
          UnitBase<Exponents<-1, 1, -2, 0, 0, 0, 0>, double>(23.5);
      const Psi test2 = Pascals(23.5);
      const Pascals test3 = Psi(31.6);

      CHECK(test1.data == doctest::Approx(0.003408387));
      CHECK(std::is_same_v<std::remove_const_t<decltype(test1)>, Psi>);

      CHECK(test2.data == doctest::Approx(0.003408387));
      CHECK(std::is_same_v<std::remove_const_t<decltype(test2)>, Psi>);

      CHECK(test3.data == doctest::Approx(217874.3));
      CHECK(std::is_same_v<std::remove_const_t<decltype(test3)>, Pascals>);
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

// NOLINTEND(modernize-use-trailing-return-type)

}  // namespace csm_units::test