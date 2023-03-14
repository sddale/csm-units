
#include "source/csm_units/converter.hpp"

#include <doctest/doctest.h>

#include <cmath>

#include "source/csm_units/exponents.hpp"

namespace csm_units::test {

class MassConverter {
 public:
  // do nothing in either of the below because we do not want to convert
  [[nodiscard]] constexpr static auto ToBase(double data, int N) noexcept
      -> double {
    if (N < 0) {
      for (int i = N; i < 0; ++i) {
        data /= 3.5;
      }
    } else {
      for (int i = 0; i < N; ++i) {
        data *= 3.5;
      }
    }
    return data;
  }

  [[nodiscard]] constexpr static auto FromBase(double data, int N) noexcept
      -> double {
    if (N < 0) {
      for (int i = N; i < 0; ++i) {
        data /= (1 / 3.5);
      }
    } else {
      for (int i = 0; i < N; ++i) {
        data *= (1 / 3.5);
      }
    }
    return data;
  }
};

class TimeConverter {
 public:
  // do nothing in either of the below because we do not want to convert
  [[nodiscard]] constexpr static auto ToBase(double data, int N) noexcept
      -> double {
    if (N < 0) {
      for (int i = N; i < 0; ++i) {
        data /= 1.8;
      }
    } else {
      for (int i = 0; i < N; ++i) {
        data *= 1.8;
      }
    }
    return data;
  }

  [[nodiscard]] constexpr static auto FromBase(double data, int N) noexcept
      -> double {
    if (N < 0) {
      for (int i = N; i < 0; ++i) {
        data /= (1 / 1.8);
      }
    } else {
      for (int i = 0; i < N; ++i) {
        data *= (1 / 1.8);
      }
    }

    return data;
  }
};

class LengthConverter {
 public:
  // do nothing in either of the below because we do not want to convert
  [[nodiscard]] constexpr static auto ToBase(double data, int N) noexcept
      -> double {
    if (N < 0) {
      for (int i = N; i < 0; ++i) {
        data /= 0.7;
      }
    } else {
      for (int i = 0; i < N; ++i) {
        data *= 0.7;
      }
    }
    return data;
  }
  [[nodiscard]] constexpr static auto FromBase(double data, int N) noexcept
      -> double {
    if (N < 0) {
      for (int i = N; i < 0; ++i) {
        data /= (1 / 0.7);
      }
    } else {
      for (int i = 0; i < N; ++i) {
        data *= (1 / 0.7);
      }
    }
    return data;
  }
};

// NOLINTBEGIN(modernize-use-trailing-return-type)

TEST_SUITE("Converters") {
  TEST_CASE("To Base") {
    SUBCASE("Positive Exp") {
      const auto test =
          Converters<LengthConverter, MassConverter, TimeConverter>::ToBase(
              2.0, Exponents<2, 3, 4>());
      const double ref = 441.082908;

      CHECK(test == doctest::Approx(ref));
    }

    SUBCASE("Negative Exp") {
      const auto test =
          Converters<LengthConverter, MassConverter, TimeConverter>::ToBase(
              7.3, Exponents<-2, -3, -4>());
      const double ref = 0.0331003531;

      CHECK(test == doctest::Approx(ref));
    }
  }

  TEST_CASE("From Base") {
    SUBCASE("Positive Exp") {
      const auto test =
          Converters<LengthConverter, MassConverter, TimeConverter>::FromBase(
              2.0, Exponents<2, 3, 4>());
      const double ref = 0.0090685899;

      CHECK(test == doctest::Approx(ref));
    }

    SUBCASE("Negative Exp") {
      const auto test =
          Converters<LengthConverter, MassConverter, TimeConverter>::FromBase(
              7.3, Exponents<-2, -3, -4>());
      const double ref = 1609.952614;

      CHECK(test == doctest::Approx(ref));
    }
  }

  // TODO(Sander & Manas): Test with real units i.e. mph to kmps
}

// NOLINTEND(modernize-use-trailing-return-type)

}  // namespace csm_units::test