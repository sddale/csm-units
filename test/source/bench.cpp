#include <doctest/doctest.h>
#include <nanobench.h>

#include <csm_units/units.hpp>

namespace csm_units::test {

// NOLINTBEGIN(modernize-use-trailing-return-type)

TEST_SUITE("Benchmarks") {
  TEST_CASE("Base Additions") {
    // do additions on double
    double x = 3.4;
    double y = 5.7;
    ankerl::nanobench::Bench().minEpochIterations(5000).run(
        "add doubles", [&]() constexpr {
          for (int i = 0; i < 10000; ++i) {
            ankerl::nanobench::doNotOptimizeAway(x + y);
          }
        });

    auto l1 = Length(3.4);
    auto l2 = Length(5.7);
    ankerl::nanobench::Bench().minEpochIterations(5000).run(
        "add base length units", [&]() constexpr {
          for (int i = 0; i < 10000; ++i) {
            ankerl::nanobench::doNotOptimizeAway(l1 + l2);
          }
        });

    auto m1 = Mass(3.4);
    auto m2 = Mass(5.7);
    ankerl::nanobench::Bench().minEpochIterations(5000).run(
        "add base mass units", [&]() constexpr {
          for (int i = 0; i < 10000; ++i) {
            ankerl::nanobench::doNotOptimizeAway(m1 + m2);
          }
        });

    auto t1 = Time(3.4);
    auto t2 = Time(5.7);
    ankerl::nanobench::Bench().minEpochIterations(5000).run(
        "add base time units", [&]() constexpr {
          for (int i = 0; i < 10000; ++i) {
            ankerl::nanobench::doNotOptimizeAway(t1 + t2);
          }
        });

    auto e1 = ElectrCurrent(3.4);
    auto e2 = ElectrCurrent(5.7);
    ankerl::nanobench::Bench().minEpochIterations(5000).run(
        "add base current units", [&]() constexpr {
          for (int i = 0; i < 10000; ++i) {
            ankerl::nanobench::doNotOptimizeAway(e1 + e2);
          }
        });

    auto tp1 = Temperature(3.4);
    auto tp2 = Temperature(5.7);
    ankerl::nanobench::Bench().minEpochIterations(5000).run(
        "add base temperature units", [&]() constexpr {
          for (int i = 0; i < 10000; ++i) {
            ankerl::nanobench::doNotOptimizeAway(tp1 + tp2);
          }
        });

    auto a1 = Amount(3.4);
    auto a2 = Amount(5.7);
    ankerl::nanobench::Bench().minEpochIterations(5000).run(
        "add base amount units", [&]() constexpr {
          for (int i = 0; i < 10000; ++i) {
            ankerl::nanobench::doNotOptimizeAway(a1 + a2);
          }
        });

    auto lm1 = Luminosity(3.4);
    auto lm2 = Luminosity(5.7);
    ankerl::nanobench::Bench().minEpochIterations(5000).run(
        "add base luminosity units", [&]() constexpr {
          for (int i = 0; i < 10000; ++i) {
            ankerl::nanobench::doNotOptimizeAway(lm1 + lm2);
          }
        });

    auto meter1 = Meter(3.4);
    auto meter2 = Meter(5.7);
    ankerl::nanobench::Bench().minEpochIterations(5000).run(
        "add derived units", [&]() constexpr {
          for (int i = 0; i < 10000; ++i) {
            ankerl::nanobench::doNotOptimizeAway(meter1 + meter2);
          }
        });
  }

  TEST_CASE("Base Subtractions") {
    // do subtractions on double
    double x = 3.4;
    double y = 5.7;
    ankerl::nanobench::Bench().minEpochIterations(5000).run(
        "subtract doubles", [&]() constexpr {
          for (int i = 0; i < 10000; ++i) {
            ankerl::nanobench::doNotOptimizeAway(x - y);
          }
        });

    auto l1 = Length(3.4);
    auto l2 = Length(5.7);
    ankerl::nanobench::Bench().minEpochIterations(5000).run(
        "subtract base length units", [&]() constexpr {
          for (int i = 0; i < 10000; ++i) {
            ankerl::nanobench::doNotOptimizeAway(l1 - l2);
          }
        });

    auto m1 = Mass(3.4);
    auto m2 = Mass(5.7);
    ankerl::nanobench::Bench().minEpochIterations(5000).run(
        "subtract base mass units", [&]() constexpr {
          for (int i = 0; i < 10000; ++i) {
            ankerl::nanobench::doNotOptimizeAway(m1 - m2);
          }
        });

    auto t1 = Time(3.4);
    auto t2 = Time(5.7);
    ankerl::nanobench::Bench().minEpochIterations(5000).run(
        "subtract base time units", [&]() constexpr {
          for (int i = 0; i < 10000; ++i) {
            ankerl::nanobench::doNotOptimizeAway(t1 - t2);
          }
        });

    auto e1 = ElectrCurrent(3.4);
    auto e2 = ElectrCurrent(5.7);
    ankerl::nanobench::Bench().minEpochIterations(5000).run(
        "subtract base current units", [&]() constexpr {
          for (int i = 0; i < 10000; ++i) {
            ankerl::nanobench::doNotOptimizeAway(e1 - e2);
          }
        });

    auto tp1 = Temperature(3.4);
    auto tp2 = Temperature(5.7);
    ankerl::nanobench::Bench().minEpochIterations(5000).run(
        "subtract base temperature units", [&]() constexpr {
          for (int i = 0; i < 10000; ++i) {
            ankerl::nanobench::doNotOptimizeAway(tp1 - tp2);
          }
        });

    auto a1 = Amount(3.4);
    auto a2 = Amount(5.7);
    ankerl::nanobench::Bench().minEpochIterations(5000).run(
        "subtract base amount units", [&]() constexpr {
          for (int i = 0; i < 10000; ++i) {
            ankerl::nanobench::doNotOptimizeAway(a1 - a2);
          }
        });

    auto lm1 = Luminosity(3.4);
    auto lm2 = Luminosity(5.7);
    ankerl::nanobench::Bench().minEpochIterations(5000).run(
        "subtract base luminosity units", [&]() constexpr {
          for (int i = 0; i < 10000; ++i) {
            ankerl::nanobench::doNotOptimizeAway(lm1 - lm2);
          }
        });

    auto meter1 = Meter(3.4);
    auto meter2 = Meter(5.7);
    ankerl::nanobench::Bench().minEpochIterations(5000).run(
        "subtract derived units", [&]() constexpr {
          for (int i = 0; i < 10000; ++i) {
            ankerl::nanobench::doNotOptimizeAway(meter1 - meter2);
          }
        });
  }

  TEST_CASE("Base Multiplications") {
    // do subtractions on double
    double x = 3.4;
    double y = 5.7;
    ankerl::nanobench::Bench().minEpochIterations(5000).run(
        "multiply doubles", [&]() constexpr {
          for (int i = 0; i < 10000; ++i) {
            ankerl::nanobench::doNotOptimizeAway(x * y);
          }
        });

    auto l1 = Length(3.4);
    auto l2 = Length(5.7);
    ankerl::nanobench::Bench().minEpochIterations(5000).run(
        "multiply base length units", [&]() constexpr {
          for (int i = 0; i < 10000; ++i) {
            ankerl::nanobench::doNotOptimizeAway(l1 * l2);
          }
        });

    auto m1 = Mass(3.4);
    auto m2 = Mass(5.7);
    ankerl::nanobench::Bench().minEpochIterations(5000).run(
        "multiply base mass units", [&]() constexpr {
          for (int i = 0; i < 10000; ++i) {
            ankerl::nanobench::doNotOptimizeAway(m1 * m2);
          }
        });

    auto t1 = Time(3.4);
    auto t2 = Time(5.7);
    ankerl::nanobench::Bench().minEpochIterations(5000).run(
        "multiply base time units", [&]() constexpr {
          for (int i = 0; i < 10000; ++i) {
            ankerl::nanobench::doNotOptimizeAway(t1 * t2);
          }
        });

    auto e1 = ElectrCurrent(3.4);
    auto e2 = ElectrCurrent(5.7);
    ankerl::nanobench::Bench().minEpochIterations(5000).run(
        "multiply base current units", [&]() constexpr {
          for (int i = 0; i < 10000; ++i) {
            ankerl::nanobench::doNotOptimizeAway(e1 * e2);
          }
        });

    auto a1 = Amount(3.4);
    auto a2 = Amount(5.7);
    ankerl::nanobench::Bench().minEpochIterations(5000).run(
        "multiply base amount units", [&]() constexpr {
          for (int i = 0; i < 10000; ++i) {
            ankerl::nanobench::doNotOptimizeAway(a1 * a2);
          }
        });

    auto lm1 = Luminosity(3.4);
    auto lm2 = Luminosity(5.7);
    ankerl::nanobench::Bench().minEpochIterations(5000).run(
        "multiply base luminosity units", [&]() constexpr {
          for (int i = 0; i < 10000; ++i) {
            ankerl::nanobench::doNotOptimizeAway(lm1 * lm2);
          }
        });

    auto meter1 = Meter(3.4);
    auto meter2 = Meter(5.7);
    ankerl::nanobench::Bench().minEpochIterations(5000).run(
        "multiply derived units", [&]() constexpr {
          for (int i = 0; i < 10000; ++i) {
            ankerl::nanobench::doNotOptimizeAway(meter1 * meter2);
          }
        });
  }

  TEST_CASE("Base Divisions") {
    // do divisions on double
    double x = 3.4;
    double y = 5.7;
    ankerl::nanobench::Bench().minEpochIterations(5000).run(
        "divide doubles", [&]() constexpr {
          for (int i = 0; i < 10000; ++i) {
            ankerl::nanobench::doNotOptimizeAway(x / y);
          }
        });

    auto l1 = Length(3.4);
    auto l2 = Length(5.7);
    ankerl::nanobench::Bench().minEpochIterations(5000).run(
        "divide base length units", [&]() constexpr {
          for (int i = 0; i < 10000; ++i) {
            ankerl::nanobench::doNotOptimizeAway(l1 / l2);
          }
        });

    auto m1 = Mass(3.4);
    auto m2 = Mass(5.7);
    ankerl::nanobench::Bench().minEpochIterations(5000).run(
        "divide base mass units", [&]() constexpr {
          for (int i = 0; i < 10000; ++i) {
            ankerl::nanobench::doNotOptimizeAway(m1 / m2);
          }
        });

    auto t1 = Time(3.4);
    auto t2 = Time(5.7);
    ankerl::nanobench::Bench().minEpochIterations(5000).run(
        "divide base time units", [&]() constexpr {
          for (int i = 0; i < 10000; ++i) {
            ankerl::nanobench::doNotOptimizeAway(t1 / t2);
          }
        });

    auto e1 = ElectrCurrent(3.4);
    auto e2 = ElectrCurrent(5.7);
    ankerl::nanobench::Bench().minEpochIterations(5000).run(
        "divide base current units", [&]() constexpr {
          for (int i = 0; i < 10000; ++i) {
            ankerl::nanobench::doNotOptimizeAway(e1 / e2);
          }
        });

    auto a1 = Amount(3.4);
    auto a2 = Amount(5.7);
    ankerl::nanobench::Bench().minEpochIterations(5000).run(
        "divide base amount units", [&]() constexpr {
          for (int i = 0; i < 10000; ++i) {
            ankerl::nanobench::doNotOptimizeAway(a1 / a2);
          }
        });

    auto lm1 = Luminosity(3.4);
    auto lm2 = Luminosity(5.7);
    ankerl::nanobench::Bench().minEpochIterations(5000).run(
        "divide base luminosity units", [&]() constexpr {
          for (int i = 0; i < 10000; ++i) {
            ankerl::nanobench::doNotOptimizeAway(lm1 / lm2);
          }
        });

    auto meter1 = Meter(3.4);
    auto meter2 = Meter(5.7);
    ankerl::nanobench::Bench().minEpochIterations(5000).run(
        "divide derived units", [&]() constexpr {
          for (int i = 0; i < 10000; ++i) {
            ankerl::nanobench::doNotOptimizeAway(meter1 / meter2);
          }
        });
  }
}

// NOLINTEND(modernize-use-trailing-return-type)

}  // namespace csm_units::test