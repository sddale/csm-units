#include <doctest/doctest.h>
#include <nanobench.h>

#include <csm_units/units.hpp>

namespace csm_units::test {

// NOLINTBEGIN(modernize-use-trailing-return-type,readability-identifier-length)
TEST_SUITE("Benchmarks") {
  TEST_CASE("Additions") {
    // do additions on double
    double x = 3.4;
    double y = 5.7;
    ankerl::nanobench::Bench().minEpochIterations(50000000).run(
        "Add doubles", [&]() { ankerl::nanobench::doNotOptimizeAway(x + y); });

    auto b1 = Length(3.4);
    auto b2 = Length(5.7);
    ankerl::nanobench::Bench().minEpochIterations(50000000).run(
        "Add csm_units base units",
        [&]() { ankerl::nanobench::doNotOptimizeAway(b1 + b2); });

    auto u1 = Meter(3.4);
    auto u2 = Meter(5.7);
    ankerl::nanobench::Bench().minEpochIterations(50000000).run(
        "Add csm_units derived units",
        [&]() { ankerl::nanobench::doNotOptimizeAway(u1 + u2); });
  }

  TEST_CASE("Subtractions") {
    double x = 3.4;
    double y = 5.7;
    ankerl::nanobench::Bench().minEpochIterations(50000000).run(
        "Subtract doubles",
        [&]() { ankerl::nanobench::doNotOptimizeAway(x - y); });

    auto b1 = Length(3.4);
    auto b2 = Length(5.7);
    ankerl::nanobench::Bench().minEpochIterations(50000000).run(
        "Subtract csm_units base units",
        [&]() { ankerl::nanobench::doNotOptimizeAway(b1 - b2); });

    auto u1 = Meter(3.4);
    auto u2 = Meter(5.7);
    ankerl::nanobench::Bench().minEpochIterations(50000000).run(
        "Subtract csm_units derived units",
        [&]() { ankerl::nanobench::doNotOptimizeAway(u1 - u2); });
  }
  TEST_CASE("Multiplications") {
    double x = 3.4;
    double y = 5.7;
    ankerl::nanobench::Bench().minEpochIterations(50000000).run(
        "Multiply doubles",
        [&]() { ankerl::nanobench::doNotOptimizeAway(x * y); });

    auto b1 = Length(3.4);
    auto b2 = Length(5.7);
    ankerl::nanobench::Bench().minEpochIterations(50000000).run(
        "Multiply csm_units base units",
        [&]() { ankerl::nanobench::doNotOptimizeAway(b1 * b2); });

    auto u1 = Meter(3.4);
    auto u2 = Meter(5.7);
    ankerl::nanobench::Bench().minEpochIterations(50000000).run(
        "Multiply csm_units derived units",
        [&]() { ankerl::nanobench::doNotOptimizeAway(u1 * u2); });
  }

  TEST_CASE("Divisions") {
    double x = 3.4;
    double y = 5.7;
    ankerl::nanobench::Bench().minEpochIterations(50000000).run(
        "Divide doubles",
        [&]() { ankerl::nanobench::doNotOptimizeAway(x / y); });

    auto b1 = Length(3.4);
    auto b2 = Length(5.7);
    ankerl::nanobench::Bench().minEpochIterations(50000000).run(
        "Divide csm_units base units",
        [&]() { ankerl::nanobench::doNotOptimizeAway(b1 / b2); });

    auto u1 = Meter(3.4);
    auto u2 = Meter(5.7);
    ankerl::nanobench::Bench().minEpochIterations(50000000).run(
        "Divide csm_units derived units",
        [&]() { ankerl::nanobench::doNotOptimizeAway(u1 / u2); });
  }
}

// NOLINTEND(modernize-use-trailing-return-type,readability-identifier-length)

}  // namespace csm_units::test