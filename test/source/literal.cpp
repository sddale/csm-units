// #include "source/csm_units/literal/literal.hpp"

#include <doctest/doctest.h>

#include <csm_units/units.hpp>
#include <type_traits>

// NOLINTBEGIN(modernize-use-trailing-return-type)

TEST_SUITE("test suite") {
  using namespace csm_units;
  TEST_CASE("test case") {
    using csm_units::literals::m;
    using csm_units::literals::s;

    SUBCASE("Second") {
      const auto test = 1.0 * s;
      CHECK(test.data == doctest::Approx(1.0));
      CHECK(std::is_same_v<std::remove_const_t<decltype(test)>,
                           UnitBase<Exponents<0, 0, 1, 0, 0, 0, 0>, double>>);
    }

    SUBCASE("Meter/Second") {
      {
        const auto test = 1.0 * m / s;
        CHECK(test.data == doctest::Approx(1.0));
        CHECK(
            std::is_same_v<std::remove_const_t<decltype(test)>,
                           UnitBase<Exponents<1, 0, -1, 0, 0, 0, 0>, double>>);
      }
      {
        const auto test = 1.0 * literals::mps;
        CHECK(test.data == doctest::Approx(1.0));
        CHECK(
            std::is_same_v<std::remove_const_t<decltype(test)>,
                           UnitBase<Exponents<1, 0, -1, 0, 0, 0, 0>, double>>);
      }
    }

    SUBCASE("1/Meter") {
      {
        const auto test = 1.0 / m;
        CHECK(test.data == doctest::Approx(1.0));
        CHECK(
            std::is_same_v<std::remove_const_t<decltype(test)>,
                           UnitBase<Exponents<-1, 0, 0, 0, 0, 0, 0>, double>>);
      }
    }

    SUBCASE("Meter/Second/Second") {
      {
        const auto test = 1.0 * literals::mps / s;
        CHECK(test.data == doctest::Approx(1.0));
        CHECK(
            std::is_same_v<std::remove_const_t<decltype(test)>,
                           UnitBase<Exponents<1, 0, -2, 0, 0, 0, 0>, double>>);
      }
      {
        const auto test = 1.0 * m / (s * s);
        CHECK(test.data == doctest::Approx(1.0));
        CHECK(
            std::is_same_v<std::remove_const_t<decltype(test)>,
                           UnitBase<Exponents<1, 0, -2, 0, 0, 0, 0>, double>>);
      }
      {
        const auto test = 1.0 * m / s / s;
        CHECK(test.data == doctest::Approx(1.0));
        CHECK(
            std::is_same_v<std::remove_const_t<decltype(test)>,
                           UnitBase<Exponents<1, 0, -2, 0, 0, 0, 0>, double>>);
      }
    }

    SUBCASE("Second/Meter") {
      const auto test = 1.0 * s / m;
      CHECK(test.data == doctest::Approx(1.0));
      CHECK(std::is_same_v<std::remove_const_t<decltype(test)>,
                           UnitBase<Exponents<-1, 0, 1, 0, 0, 0, 0>, double>>);
    }
  }
}

// NOLINTEND(modernize-use-trailing-return-type)
