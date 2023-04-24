#include <doctest/doctest.h>
#include <nanobench.h>
#include <units/isq/si/length.h>

#include <csm_units/units.hpp>
// #include <units/isq/si/mass.h>

namespace csm_units::test {

// NOLINTBEGIN(modernize-use-trailing-return-type)
using namespace units::isq::si::references;
TEST_SUITE("Benchmarks") {
  TEST_CASE("Additions") {
    // do additions on double
    double x = 3.4;
    double y = 5.7;
    ankerl::nanobench::Bench().minEpochIterations(50000000).run(
        "add doubles", [&]() constexpr {
          ankerl::nanobench::doNotOptimizeAway(x + y);
        });

    auto comp1 = units::isq::si::length<units::isq::si::metre>(3.4);
    auto comp2 = units::isq::si::length<units::isq::si::metre>(5.7);
    ankerl::nanobench::Bench().minEpochIterations(50000000).run(
        "adding competitor's derived units", [&]() constexpr {
          ankerl::nanobench::doNotOptimizeAway(comp1 + comp2);
        });

    auto b1 = Length(3.4);
    auto b2 = Length(5.7);
    ankerl::nanobench::Bench().minEpochIterations(50000000).run(
        "add base units", [&]() constexpr {
          ankerl::nanobench::doNotOptimizeAway(b1 + b2);
        });

    auto u1 = Meter(3.4);
    auto u2 = Meter(5.7);
    ankerl::nanobench::Bench().minEpochIterations(50000000).run(
        "add derived units", [&]() constexpr {
          ankerl::nanobench::doNotOptimizeAway(u1 + u2);
        });
  }

  TEST_CASE("Subtractions") {
    double x = 3.4;
    double y = 5.7;
    ankerl::nanobench::Bench().minEpochIterations(50000000).run(
        "subtract doubles", [&]() constexpr {
          ankerl::nanobench::doNotOptimizeAway(x - y);
        });

    auto comp1 = units::isq::si::length<units::isq::si::metre>(3.4);
    auto comp2 = units::isq::si::length<units::isq::si::metre>(5.7);
    ankerl::nanobench::Bench().minEpochIterations(50000000).run(
        "subtract competitor's derived units", [&]() constexpr {
          ankerl::nanobench::doNotOptimizeAway(comp1 - comp2);
        });

    auto b1 = Length(3.4);
    auto b2 = Length(5.7);
    ankerl::nanobench::Bench().minEpochIterations(50000000).run(
        "subtract base units", [&]() constexpr {
          ankerl::nanobench::doNotOptimizeAway(b1 - b2);
        });

    auto u1 = Meter(3.4);
    auto u2 = Meter(5.7);
    ankerl::nanobench::Bench().minEpochIterations(50000000).run(
        "subtract derived units", [&]() constexpr {
          ankerl::nanobench::doNotOptimizeAway(u1 - u2);
        });
  }
  TEST_CASE("Multiplications") {
    double x = 3.4;
    double y = 5.7;
    ankerl::nanobench::Bench().minEpochIterations(50000000).run(
        "multiply doubles", [&]() constexpr {
          ankerl::nanobench::doNotOptimizeAway(x * y);
        });

    auto comp1 = units::isq::si::length<units::isq::si::metre>(3.4);
    auto comp2 = units::isq::si::length<units::isq::si::metre>(5.7);
    ankerl::nanobench::Bench().minEpochIterations(50000000).run(
        "multiplying competitor's derived units", [&]() constexpr {
          ankerl::nanobench::doNotOptimizeAway(comp1 * comp2);
        });

    auto b1 = Length(3.4);
    auto b2 = Length(5.7);
    ankerl::nanobench::Bench().minEpochIterations(50000000).run(
        "multiply base units", [&]() constexpr {
          ankerl::nanobench::doNotOptimizeAway(b1 * b2);
        });

    auto u1 = Meter(3.4);
    auto u2 = Meter(5.7);
    ankerl::nanobench::Bench().minEpochIterations(50000000).run(
        "multiply derived units", [&]() constexpr {
          ankerl::nanobench::doNotOptimizeAway(u1 * u2);
        });
  }

  TEST_CASE("Divisions") {
    double x = 3.4;
    double y = 5.7;
    ankerl::nanobench::Bench().minEpochIterations(50000000).run(
        "divide doubles", [&]() constexpr {
          ankerl::nanobench::doNotOptimizeAway(x / y);
        });

    auto comp1 = units::isq::si::length<units::isq::si::metre>(3.4);
    auto comp2 = units::isq::si::length<units::isq::si::metre>(5.7);
    ankerl::nanobench::Bench().minEpochIterations(50000000).run(
        "dividing competitor's derived units", [&]() constexpr {
          ankerl::nanobench::doNotOptimizeAway(comp1 / comp2);
        });

    auto b1 = Length(3.4);
    auto b2 = Length(5.7);
    ankerl::nanobench::Bench().minEpochIterations(50000000).run(
        "divide base units", [&]() constexpr {
          ankerl::nanobench::doNotOptimizeAway(b1 / b2);
        });

    auto u1 = Meter(3.4);
    auto u2 = Meter(5.7);
    ankerl::nanobench::Bench().minEpochIterations(50000000).run(
        "divide derived units", [&]() constexpr {
          ankerl::nanobench::doNotOptimizeAway(u1 / u2);
        });
  }
}

// NOLINTEND(modernize-use-trailing-return-type)

}  // namespace csm_units::test