#include <doctest/doctest.h>
#include <nanobench.h>

#include <csm_units/units.hpp>

namespace csm_units::test {

// NOLINTBEGIN(modernize-use-trailing-return-type)

TEST_SUITE("Benchmarks") {
  TEST_CASE("Addition") {
    // do additions on double
    // double x = 3.4;
    // double y = 5.7;
    // ankerl::nanobench::Bench().minEpochIterations(5000).run(
    //     "add doubles", [&]() constexpr {
    //       for (int i = 0; i < 10000; ++i) {
    //         ankerl::nanobench::doNotOptimizeAway(x + y);
    //       }
    //     });

    // auto u1 = Length(3.4);
    // auto u2 = Length(5.7);
    // ankerl::nanobench::Bench().minEpochIterations(5000).run(
    //     "add Units", [&]() constexpr {
    //       for (int i = 0; i < 10000; ++i) {
    //         ankerl::nanobench::doNotOptimizeAway(u1 + u2);
    //       }
    //     });

    // auto m1 = Meter(3.4);
    // auto m2 = Meter(5.7);
    // ankerl::nanobench::Bench().minEpochIterations(5000).run(
    //     "add Units", [&]() constexpr {
    //       for (int i = 0; i < 10000; ++i) {
    //         ankerl::nanobench::doNotOptimizeAway(m1 + m2);
    //       }
    //     });

    // // do addition on Units
  }
}

// NOLINTEND(modernize-use-trailing-return-type)

}  // namespace csm_units::test