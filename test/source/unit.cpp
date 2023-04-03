#include "source/csm_units/unit.hpp"

#include <doctest/doctest.h>

namespace csm_units::test {

// NOLINTBEGIN(modernize-use-trailing-return-type)

TEST_SUITE("Unit") {
  TEST_CASE("Unit Tests") {
    SUBCASE("Unit-Unit Base Addition") {
      const auto kg_unit =
          Unit<UnitBase<Exponents<0, 1, 0, 0, 0, 0, 0>, double>, "kg", double>(
              3.0);
      const auto kg_unit_base =
          UnitBase<Exponents<0, 1, 0, 0, 0, 0, 0>, double>(4000.0);
      CHECK(true);

      const auto test = kg_unit + kg_unit_base;
      CHECK(test.data == doctest::Approx(7.0));
      CHECK(std::is_same_v<std::remove_const_t<decltype(test)>,
                           std::remove_const_t<decltype(kg_unit)>>);
    }
  }

  // TEST_CASE("Idea Test") {
  //   const auto foo1 = Foo1(3.0);
  //   const auto foo2 = Foo2(4.0);

  //   const auto fooTest1 = foo1 + foo2;

  //   const auto fooTest2 = foo2 + foo2;

  //   CHECK(fooTest1.data == doctest::Approx(7.0));
  //   CHECK(std::is_same_v<std::remove_const_t<decltype(fooTest1)>, Foo1>);

  //   CHECK(fooTest2.data == doctest::Approx(8.0));
  //   CHECK(std::is_same_v<std::remove_const_t<decltype(fooTest2)>, Foo1>);
  // }
}

// NOLINTEND(modernize-use-trailing-return-type)

}  // namespace csm_units::test