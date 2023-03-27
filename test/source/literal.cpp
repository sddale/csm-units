#include "source/csm_units/literal/literal.hpp"

#include <doctest/doctest.h>

#include <csm_units/units.hpp>
#include <type_traits>

namespace csm_units::test {

TEST_SUITE("test suite") {
  TEST_CASE("test case") {
    using literals::m;
    using literals::s;

    SUBCASE("Seconds") {
      const auto test = 1.0 <<= s;
      CHECK(test.data == doctest::Approx(1.0));
      CHECK(std::is_same_v<std::remove_const_t<decltype(test)>, Seconds>);
    }

    SUBCASE("Meter/Second") {
      {
        const auto test = 1.0 <<= m / s;
        CHECK(test.data == doctest::Approx(1.0));
        CHECK(std::is_same_v<std::remove_const_t<decltype(test)>,
                             DBasic<1, 0, -1, 0, 0, 0, 0>>);
      }
      {
        const auto test = 1.0 <<= literals::mps;
        CHECK(test.data == doctest::Approx(1.0));
        CHECK(std::is_same_v<std::remove_const_t<decltype(test)>,
                             DBasic<1, 0, -1, 0, 0, 0, 0>>);
      }
    }

    SUBCASE("Meter/Second/Second") {
      {
        const auto test = 1.0 <<= literals::mps / s;
        CHECK(test.data == doctest::Approx(1.0));
        CHECK(std::is_same_v<std::remove_const_t<decltype(test)>,
                             DBasic<1, 0, -2, 0, 0, 0, 0>>);
      }
      {
        const auto test = 1.0 <<= m / (s * s);
        CHECK(test.data == doctest::Approx(1.0));
        CHECK(std::is_same_v<std::remove_const_t<decltype(test)>,
                             DBasic<1, 0, -2, 0, 0, 0, 0>>);
      }
      {
        const auto test = 1.0 <<= m / s / s;
        CHECK(test.data == doctest::Approx(1.0));
        CHECK(std::is_same_v<std::remove_const_t<decltype(test)>,
                             DBasic<1, 0, -2, 0, 0, 0, 0>>);
      }
    }

    SUBCASE("Second/Meter") {
      const auto test = 1.0 <<= s / m;
      CHECK(test.data == doctest::Approx(1.0));
      CHECK(std::is_same_v<std::remove_const_t<decltype(test)>,
                           DBasic<-1, 0, 1, 0, 0, 0, 0>>);
    }
  }
}

}  // namespace csm_units::test
