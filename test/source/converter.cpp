#include <doctest/doctest.h>

#include <csm_units/concepts.hpp>
#include <source/csm_units/definition.hpp>
#include <source/csm_units/exponents.hpp>
#include <source/csm_units/unit.hpp>
// #include <csm_units/units.hpp>
#include <gcem.hpp>

#ifndef CSMUNITS_VALUE_TYPE
#define CSMUNITS_VALUE_TYPE double
#endif

namespace csm_units::test {

constexpr auto CHECK_UNIT_EQ = [](IsUnit auto lhs, IsUnit auto rhs) {
  CHECK_EQ(lhs.data, doctest::Approx(rhs.data));
};

constexpr auto CHECK_DBL_EQ = [](auto lhs, auto rhs) {
  CHECK_EQ(lhs, doctest::Approx(rhs));
};

namespace definition {
using Rankine =
    Definition<Exponents<0, 0, 0, 0, 1, 0, 0>, std::ratio<1>, std::ratio<1>,
               std::ratio<1>, std::ratio<1>, std::ratio<9, 5>>;

using SquareRankine =
    Definition<Exponents<0, 0, 0, 0, 2, 0, 0>, std::ratio<1>, std::ratio<1>,
               std::ratio<1>, std::ratio<1>, std::ratio<9, 5>>;

using Kelvin = Definition<Exponents<0, 0, 0, 0, 1, 0, 0>>;

}  // namespace definition

constexpr auto R =  // NOLINT(readability-identifier-length)
    definition::Rankine();

using Rankine = Unit<decltype(R), double>;
using Kelvin = Unit<definition::Kelvin, double>;
using Celsius = Unit<definition::Kelvin, double, std::ratio<5463, 20>>;
// using Fahrenheit = Unit<decltype(R), double, std::ratio<45967, 100>>;
using Fahrenheit = Unit<decltype(R), double, std::ratio<45967, 180>>;

// NOLINTBEGIN(modernize-use-trailing-return-type, misc-use-anonymous-namespace)

TEST_SUITE("Conversion Operators") {
  TEST_CASE("Definition") {
    static_assert(
        std::is_same_v<Unit<definition::Rankine, double>, decltype(1.0 * R)>);
    static_assert(std::is_same_v<Unit<definition::SquareRankine, double>,
                                 decltype(1.0 * R * R)>);
    static_assert(std::is_same_v<Unit<definition::SquareRankine, double>,
                                 decltype(Rankine(1.0) * R)>);
  }
}

TEST_SUITE("Unit") {
  TEST_CASE("Size") {
    static_assert(sizeof(CSMUNITS_VALUE_TYPE) ==
                  sizeof(Unit<definition::Kelvin>));
    static_assert(sizeof(double) == sizeof(Unit<definition::Kelvin, double>));
    static_assert(sizeof(float) == sizeof(Unit<definition::Kelvin, float>));
    static_assert(sizeof(double) ==
                  sizeof(decltype(Unit<definition::Kelvin, double>() *
                                  Unit<definition::Kelvin, float>())));
    static_assert(sizeof(double) ==
                  sizeof(decltype(Unit<definition::Kelvin, float>() *
                                  Unit<definition::Kelvin, double>())));
    static_assert(sizeof(double) ==
                  sizeof(decltype(Unit<definition::Kelvin, double>() /
                                  Unit<definition::Kelvin, float>())));
    static_assert(sizeof(double) ==
                  sizeof(decltype(Unit<definition::Kelvin, float>() /
                                  Unit<definition::Kelvin, double>())));
  }
  TEST_CASE("Comparison") {
    static_assert(Rankine(100.) == Kelvin(100. * 5 / 9));
    static_assert(Rankine(100.) != Kelvin(101. * 5 / 9));
    static_assert(Rankine(100.) <= Kelvin(100. * 5 / 9));
    static_assert(not(Rankine(100.) <= Kelvin(99. * 5 / 9)));
    static_assert(Rankine(100.) < Kelvin(101. * 5 / 9));
    static_assert(not(Rankine(100.) < Kelvin(100. * 5 / 9)));
    static_assert(Rankine(100.) >= Kelvin(100. * 5 / 9));
    static_assert(Rankine(101.) >= Kelvin(100. * 5 / 9));
    static_assert(not(Rankine(99.) >= Kelvin(100. * 5 / 9)));
    static_assert(Rankine(101.) > Kelvin(100. * 5 / 9));
    static_assert(not(Rankine(100.) > Kelvin(100. * 5 / 9)));
  }
  TEST_CASE("Get() and .data") {
    static_assert(Rankine(100.).Get() == 100.);
    static_assert(Rankine(100.).data == Kelvin(100. * 5 / 9).data);
    static_assert(Rankine(100.).data == 100. * 5 / 9);
    static_assert(Kelvin(100.).Get() == Kelvin(100.).data);
  }
  TEST_CASE("Unary negative") {
    static_assert(-Rankine(100.) == -Kelvin(100. * 5 / 9));
  }
  TEST_CASE("Subtraction") {
    SUBCASE("Operator-=") {
      {
        auto val = Kelvin(100.);
        val -= Kelvin(99.);
        CHECK_DBL_EQ(val.Get(), Kelvin(1.).Get());
      }
      {
        auto val = Rankine(100.);
        val -= Rankine(99.);
        CHECK_DBL_EQ(val.data, 1. * 5 / 9);
        CHECK_DBL_EQ(val.Get(), Kelvin(1.).Get());
      }
    }
    SUBCASE("Binary operator-") {
      {
        const auto result = Kelvin(100.) - Kelvin(99);
        CHECK_DBL_EQ(result.Get(), Kelvin(1.).Get());
      }
      {
        const auto result = Rankine(100.) - Rankine(99);
        CHECK_DBL_EQ(result.data, 1. * 5 / 9);
        CHECK_DBL_EQ(result.Get(), Kelvin(1.).Get());
      }
    }
  }
  TEST_CASE("Addition") {
    SUBCASE("Operator+=") {
      {
        auto val = Kelvin(100.);
        val += Kelvin(99.);
        CHECK_DBL_EQ(val.Get(), Kelvin(199.).Get());
      }
      {
        auto val = Rankine(100.);
        val += Rankine(99.);
        CHECK_DBL_EQ(val.data, 199. * 5 / 9);
        CHECK_DBL_EQ(val.Get(), Kelvin(199.).Get());
      }
    }
    SUBCASE("Binary operator-") {
      {
        const auto result = Kelvin(100.) + Kelvin(99);
        CHECK_DBL_EQ(result.Get(), Kelvin(199.).Get());
      }
      {
        const auto result = Rankine(100.) + Rankine(99);
        CHECK_DBL_EQ(result.data, 199. * 5 / 9);
        CHECK_DBL_EQ(result.Get(), Kelvin(199.).Get());
      }
    }
  }
}
TEST_SUITE("Relative Unit") {
  TEST_CASE("Comparison") {
    CHECK_UNIT_EQ(Fahrenheit(100.), Rankine(100 + 459.67));
    static_assert(Fahrenheit(90.) != Rankine(100 + 459.67));
    static_assert(Fahrenheit(90.).data < Rankine(100 + 459.67).data);
    static_assert(Fahrenheit(90.) <= Rankine(100 + 459.67));
    static_assert(Fahrenheit(101.) >= Rankine(100 + 459.67));
    static_assert(Fahrenheit(101.) > Rankine(100 + 459.67));
    CHECK_DBL_EQ(Fahrenheit(100).data, Celsius(37.7778).data);
    CHECK(Fahrenheit(101).data != doctest::Approx(Celsius(37.7778).data));
  }
  TEST_CASE("Get() and .data") {
    CHECK_DBL_EQ(Fahrenheit(100.).Get(), 100);
    CHECK_DBL_EQ(Fahrenheit(100.).data, Celsius(37.7778).data);
    CHECK_DBL_EQ(Fahrenheit(100.).data, Rankine(100 + 459.67).data);
    CHECK_EQ(Fahrenheit(100.).data,
             doctest::Approx(Kelvin((100 - 32) * 5. / 9 + 273.15).Get()));
  }
  TEST_CASE("Unary operator-") {
    CHECK_UNIT_EQ(-Fahrenheit(100.), -Rankine(100 + 459.67));
  }
  TEST_CASE("Subtraction") {
    SUBCASE("Operator-=") {
      {
        auto result = Celsius(5) -= Celsius(3);
        CHECK_DBL_EQ(result.data, 2.);
        CHECK_DBL_EQ(result.Get(), Celsius(2 - 273.15).Get());
      }

      {
        auto result = Fahrenheit(5) -= Fahrenheit(3);
        CHECK_DBL_EQ(result.data, 2. * 5 / 9);
        CHECK_DBL_EQ(result.Get(), Fahrenheit(2 - 459.67).Get());
      }
    }
    SUBCASE("Binary operator-") {
      {
        const auto result = Celsius(5) - Celsius(3);
        CHECK_DBL_EQ(result.data, 2.);
        CHECK_DBL_EQ(result.SI(), 2.);
        CHECK_DBL_EQ(result.Get(), Celsius(2 - 273.15).Get());
      }
      {
        const auto result = Fahrenheit(5) - Fahrenheit(3);
        CHECK_DBL_EQ(result.data, 2. * 5 / 9);
        CHECK_DBL_EQ(result.Get(), Fahrenheit(2 - 459.67).Get());
      }
      {
        const auto result = Celsius(5) - Fahrenheit(37.4);
        CHECK_DBL_EQ(result.data, 2.);
        CHECK_DBL_EQ(result.Get(), Celsius(2 - 273.15).Get());
      }
    }
    // CHECK_DBL_EQ(farenheit.Get(),  Fahrenheit(1.).Get());
  }
  TEST_CASE("Addition") {
    SUBCASE("Operator+=") {
      {
        const auto result = Celsius(5) += Celsius(3);
        CHECK_DBL_EQ(result.data, 8 + 2 * 273.15);
        CHECK_DBL_EQ(result.SI(), 8 + 2 * 273.15);
        CHECK_DBL_EQ(result.Get(), Celsius(8 + 273.15).Get());
      }
      {
        const auto result = Fahrenheit(5) += Fahrenheit(3);
        CHECK_DBL_EQ(result.data, (8. + 2 * 459.67) * 5 / 9);
        CHECK_DBL_EQ(result.Get(), Fahrenheit(8 + 459.67).Get());
      }
      {
        const auto result = Celsius(5) += Fahrenheit(37.4);
        CHECK_DBL_EQ(result.data, 8 + 2 * 273.15);
        CHECK_DBL_EQ(result.Get(), Celsius(8 + 273.15).Get());
      }
    }
    SUBCASE("Binary operator+") {
      {
        const auto result = Celsius(5) + Celsius(3);
        CHECK_DBL_EQ(result.data, 8 + 2 * 273.15);
        CHECK_DBL_EQ(result.Get(), Celsius(8 + 273.15).Get());
      }
      {
        const auto result = Fahrenheit(5) + Fahrenheit(3);
        CHECK_DBL_EQ(result.data, (8. + 2 * 459.67) * 5 / 9);
        CHECK_DBL_EQ(result.Get(), Fahrenheit(8 + 459.67).Get());
      }
      {
        const auto result = Celsius(5) + Fahrenheit(37.4);
        CHECK_DBL_EQ(result.data, 8 + 2 * 273.15);
        CHECK_DBL_EQ(Celsius(Fahrenheit(5)).Get(), -15);
        CHECK_DBL_EQ(Fahrenheit(Celsius(5)).Get(), 41);
        CHECK_DBL_EQ(Celsius(Kelvin(300)).Get(), 300 - 273.15);
        CHECK_DBL_EQ(Kelvin(Celsius(300)).Get(), 300 + 273.15);
        CHECK_DBL_EQ(Fahrenheit(Rankine(1000)).Get(), 540.33);
        CHECK_DBL_EQ(result.Get(), Celsius(8 + 273.15).Get());
      }
    }
  }
}

// NOLINTEND(modernize-use-trailing-return-type, misc-use-anonymous-namespace)

}  // namespace csm_units::test