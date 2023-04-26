#include <doctest/doctest.h>
#include <nanobench.h>
// #include <units/isq/si/length.h>

#include <csm_units/units.hpp>

namespace csm_units::test {

// NOLINTBEGIN(modernize-use-trailing-return-type)
// using namespace units::isq::si::references;
TEST_SUITE("Benchmarks") {
  TEST_CASE("Additions") {
    // do additions on double
    double x = 3.4;
    double y = 5.7;
    ankerl::nanobench::Bench().minEpochIterations(50000000).run(
        "Add doubles", [&]() { ankerl::nanobench::doNotOptimizeAway(x + y); });

    // ankerl::nanobench::Rng rng;
    // ankerl::nanobench::ScopeGuard group1("asdf");
    // a way to Add csm_units groups, but ScoeGuard not found in nanobench?? huh

    // competitor
    // auto comp1 = units::isq::si::length<units::isq::si::metre>(3.4);
    // auto comp2 = units::isq::si::length<units::isq::si::metre>(5.7);
    // ankerl::nanobench::Bench().minEpochIterations(50000000).run(
    //     "Add mpusz/units derived units", [&]() constexpr {
    //       ankerl::nanobench::doNotOptimizeAway(comp1 + comp2);
    //     });

    auto b1 = Length(3.4);
    auto b2 = Length(5.7);
    ankerl::nanobench::Bench().minEpochIterations(50000000).run(
        "Add csm_units base units", [&]() constexpr {
          ankerl::nanobench::doNotOptimizeAway(b1 + b2);
        });

    auto u1 = Meter(3.4);
    auto u2 = Meter(5.7);
    ankerl::nanobench::Bench().minEpochIterations(50000000).run(
        "Add csm_units derived units", [&]() constexpr {
          ankerl::nanobench::doNotOptimizeAway(u1 + u2);
        });
  }

  TEST_CASE("Subtractions") {
    double x = 3.4;
    double y = 5.7;
    ankerl::nanobench::Bench().minEpochIterations(50000000).run(
        "Subtract doubles", [&]() constexpr {
          ankerl::nanobench::doNotOptimizeAway(x - y);
        });

    // competitor
    // auto comp1 = units::isq::si::length<units::isq::si::metre>(3.4);
    // auto comp2 = units::isq::si::length<units::isq::si::metre>(5.7);
    // ankerl::nanobench::Bench().minEpochIterations(50000000).run(
    //     "Subtract mpusz/units derived units", [&]() constexpr {
    //       ankerl::nanobench::doNotOptimizeAway(comp1 - comp2);
    //     });

    auto b1 = Length(3.4);
    auto b2 = Length(5.7);
    ankerl::nanobench::Bench().minEpochIterations(50000000).run(
        "Subtract csm_units base units", [&]() constexpr {
          ankerl::nanobench::doNotOptimizeAway(b1 - b2);
        });

    auto u1 = Meter(3.4);
    auto u2 = Meter(5.7);
    ankerl::nanobench::Bench().minEpochIterations(50000000).run(
        "Subtract csm_units derived units", [&]() constexpr {
          ankerl::nanobench::doNotOptimizeAway(u1 - u2);
        });
  }
  TEST_CASE("Multiplications") {
    double x = 3.4;
    double y = 5.7;
    ankerl::nanobench::Bench().minEpochIterations(50000000).run(
        "Multiply doubles", [&]() constexpr {
          ankerl::nanobench::doNotOptimizeAway(x * y);
        });

    // competitor
    // auto comp1 = units::isq::si::length<units::isq::si::metre>(3.4);
    // auto comp2 = units::isq::si::length<units::isq::si::metre>(5.7);
    // ankerl::nanobench::Bench().minEpochIterations(50000000).run(
    //     "Multiply mpusz/units derived units", [&]() constexpr {
    //       ankerl::nanobench::doNotOptimizeAway(comp1 * comp2);
    //     });

    auto b1 = Length(3.4);
    auto b2 = Length(5.7);
    ankerl::nanobench::Bench().minEpochIterations(50000000).run(
        "Multiply csm_units base units", [&]() constexpr {
          ankerl::nanobench::doNotOptimizeAway(b1 * b2);
        });

    auto u1 = Meter(3.4);
    auto u2 = Meter(5.7);
    ankerl::nanobench::Bench().minEpochIterations(50000000).run(
        "Multiply csm_units derived units", [&]() constexpr {
          ankerl::nanobench::doNotOptimizeAway(u1 * u2);
        });
  }

  TEST_CASE("Divisions") {
    double x = 3.4;
    double y = 5.7;
    ankerl::nanobench::Bench().minEpochIterations(50000000).run(
        "Divide doubles", [&]() constexpr {
          ankerl::nanobench::doNotOptimizeAway(x / y);
        });

    // competitor
    // auto comp1 = units::isq::si::length<units::isq::si::metre>(3.4);
    // auto comp2 = units::isq::si::length<units::isq::si::metre>(5.7);
    // ankerl::nanobench::Bench().minEpochIterations(50000000).run(
    //     "Divide mpusz/units derived units", [&]() constexpr {
    //       ankerl::nanobench::doNotOptimizeAway(comp1 / comp2);
    //     });

    auto b1 = Length(3.4);
    auto b2 = Length(5.7);
    ankerl::nanobench::Bench().minEpochIterations(50000000).run(
        "Divide csm_units base units", [&]() constexpr {
          ankerl::nanobench::doNotOptimizeAway(b1 / b2);
        });

    auto u1 = Meter(3.4);
    auto u2 = Meter(5.7);
    ankerl::nanobench::Bench().minEpochIterations(50000000).run(
        "Divide csm_units derived units", [&]() constexpr {
          ankerl::nanobench::doNotOptimizeAway(u1 / u2);
        });
  }
}

// NOLINTEND(modernize-use-trailing-return-type)

}  // namespace csm_units::test