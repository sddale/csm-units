#include <doctest/doctest.h>

#include <csm_units/units.hpp>

namespace csm_units::test {

using Kilograms = DBasic<0, 1, 0>;

// velocity = m/s
using MeterPerSecond = DBasic<1, 0, -1>;

// using Pascals = Unit<Exponents<1,-1,-2>, Converters<NoConverter, KilogramConverter, NoConverter>, Prefixes<>, double>;
// using Psi = Unit<Exponents<1,1,-2>, Converters<FeetPerInchesSquaredConverter, PoundConverter, NoConverter>, Prefixes<>, double>;

// class KilogramConverter {
//  public:
//   [[nodiscard]] constexpr static auto ToBase(double data, int N) noexcept
//       -> double {
//     if (N < 0) {
//       for (int i = N; i < 0; ++i) {
//         data /= 1000;
//       }
//     } else {
//       for (int i = 0; i < N; ++i) {
//         data *= 1000;
//       }
//     }
//     return data;
//   }

//   [[nodiscard]] constexpr static auto FromBase(double data, int N) noexcept
//       -> double {
//     return ToBase(data, -N);
//   }
// };

// class PoundConverter {
//  public:
//   [[nodiscard]] constexpr static auto ToBase(double data, int N) noexcept
//       -> double {
//     if (N < 0) {
//       for (int i = N; i < 0; ++i) {
//         data /= 453.59237;
//       }
//     } else {
//       for (int i = 0; i < N; ++i) {
//         data *= 453.59237;
//       }
//     }
//     return data;
//   }

//   [[nodiscard]] constexpr static auto FromBase(double data, int N) noexcept
//       -> double {
//     return ToBase(data, -N);
//   }
// };

// class FeetPerInchesSquaredConverter {
//  public:
//   [[nodiscard]] constexpr static auto ToBase(double data, int N) noexcept
//       -> double {
//     if (N < 0) {
//       for (int i = N; i < 0; ++i) {
//         data /= 144 / 0.3048;
//       }
//     } else {
//       for (int i = 0; i < N; ++i) {
//         data *= 144 / 0.3048;
//       }
//     }
//     return data;
//   }

//   [[nodiscard]] constexpr static auto FromBase(double data, int N) noexcept
//       -> double {
//     return ToBase(data, -N);
//   }
// };

// NOLINTBEGIN(modernize-use-trailing-return-type)
TEST_SUITE("Unit") {
  // Tests to make sure that the unit class is working the way we expect

  // test to make sure the size of the class never exceeds the size of the data
  // member variable. Force all test cases to stop if it does.

  // TEST_CASE("Literals temp") {
  //   const auto meterLength = 40.0_m;
  //   const auto ref = Meter(40.0);

  //   CHECK(ref.data == meterLength.data);
  //   // CHECK(std::is_same_v<decltype(ref), decltype(meterLength)>);

  //   const auto kgMass = 40.0_kg;
  //   const auto ref3 = Kilograms(40.0);

  //   CHECK(ref3.data == kgMass.data);
  //   // CHECK(std::is_same_v<decltype(ref3), decltype(kgMass)>);

  //   const auto timeSec = 40.0_s;
  //   const auto ref2 = Seconds(40.0);

  //   CHECK(ref2.data == timeSec.data);
  //   // CHECK(std::is_same_v<decltype(ref2), decltype(timeSec)>);
  // }

  TEST_CASE("Size") {
    const auto test = DBasic<14, 14, 14>(14.0);
    REQUIRE(sizeof(test) == sizeof(test.data));
  }

  TEST_CASE("Objects") {
    SUBCASE("DimLength") {
      const auto test_length_pow1 = DBasic<1, 0, 0>(13.0);
      const auto test_length_pow2 = DBasic<2, 0, 0>(13.0);

      CHECK(test_length_pow1.data == doctest::Approx(13.0));
      CHECK(test_length_pow2.data == doctest::Approx(13.0));
    }

    SUBCASE("DimMass") {
      const auto test_mass_pow1 = DBasic<0, 1, 0>(13.0);
      const auto test_mass_pow2 = DBasic<0, 2, 0>(13.0);

      CHECK(test_mass_pow1.data == doctest::Approx(13.0));
      CHECK(test_mass_pow2.data == doctest::Approx(13.0));
    }

    SUBCASE("DimTime") {
      const auto test_time_pow1 = DBasic<0, 0, 1>(13.0);
      const auto test_time_pow2 = DBasic<0, 0, 2>(13.0);

      CHECK(test_time_pow1.data == doctest::Approx(13.0));
      CHECK(test_time_pow2.data == doctest::Approx(13.0));
    }

    SUBCASE("Mix of All 3") {
      const auto length1_mass1_time1 = DBasic<1, 1, 1>(13.0);
      const auto length2_mass2_time2 = DBasic<2, 2, 2>(13.0);
      const auto arbitrary_mix_up = DBasic<3, 1, 4>(13.0);

      CHECK(length1_mass1_time1.data == doctest::Approx(13.0));
      CHECK(length2_mass2_time2.data == doctest::Approx(13.0));
      CHECK(arbitrary_mix_up.data == doctest::Approx(13.0));
    }
  }

  TEST_CASE("Division") {
    // may have to refactor

    constexpr auto test_div = [](auto num, auto den, auto exp_quot, auto quot,
                                 auto exp_inv, auto inv) {
      const auto quotient = num / den;
      const auto inverse_quotient = den / num;

      if constexpr (std::is_same_v<decltype(num), decltype(den)>) {
        CHECK(quotient == doctest::Approx(exp_quot));

        CHECK(inverse_quotient == doctest::Approx(exp_inv));
      } else {
        CHECK(quotient.data == doctest::Approx(exp_quot));

        CHECK(inverse_quotient.data == doctest::Approx(exp_inv));
      }

      CHECK(std::is_same_v<std::remove_const_t<decltype(quotient)>,
                           std::remove_const_t<decltype(quot)>>);

      CHECK(std::is_same_v<std::remove_const_t<decltype(inverse_quotient)>,
                           std::remove_const_t<decltype(inv)>>);
    };

    SUBCASE("Unit/Unit") {
      test_div(DBasic<3, 6, 8>(20.0), DBasic<1, 2, 3>(10.0), 2.0,
               DBasic<2, 4, 5>(), 0.5, DBasic<-2, -4, -5>());

      test_div(DBasic<1, 2, 3>(24.0), DBasic<1, 2, 3>(12.0), 2.0, 0.0, 0.5,
               0.0);
    }

    // SUBCASE("Unit/Base") {
    //   test_div(DBasic<3, 2, 4>(20.0), Base<DimLength>(4.0), 5.0,
    //            DBasic<2, 2, 4>(), 0.2, DBasic<-2, -2, -4>());
    // }

    // SUBCASE("Base/Base") {
    //   test_div(Base<DimLength>(4.0), Base<DimMass>(2.0), 2.0,
    //            DBasic<1, -1, 0>(), 0.5, DBasic<-1, 1, 0>());
    // }

    SUBCASE("Unit/Double") {
      test_div(DBasic<1, 2, 3>(40.0), 10.0, 4.0, DBasic<1, 2, 3>(), 0.25,
               DBasic<-1, -2, -3>());
    }
  }

  TEST_CASE("Multiplication") {
    constexpr auto test_mult = [](auto first, auto second, auto exp_prod,
                                  auto prod) {
      const auto product = first * second;
      const auto inverse_product = second * first;

      if constexpr (std::is_convertible_v<decltype(product), double>) {
        CHECK(product == doctest::Approx(exp_prod));

        CHECK(inverse_product == doctest::Approx(exp_prod));
      } else {
        CHECK(product.data == doctest::Approx(exp_prod));

        CHECK(inverse_product.data == doctest::Approx(exp_prod));
      }

      CHECK(std::is_same_v<std::remove_const_t<decltype(product)>,
                           std::remove_const_t<decltype(prod)>>);

      CHECK(std::is_same_v<std::remove_const_t<decltype(inverse_product)>,
                           std::remove_const_t<decltype(prod)>>);
    };

    SUBCASE("Unit * Unit") {
      test_mult(DBasic<3, 2, 0>(20.0), DBasic<1, 0, 3>(50.0), 1000.0,
                DBasic<4, 2, 3>());

      test_mult(DBasic<-1, -2, -3>(3.0), DBasic<1, 2, 3>(12.0), 36.0, 0.0);
    }

    // SUBCASE("Unit * Base") {
    //   test_mult(DBasic<3, 2, 4>(20.0), Base<DimLength>(4.0), 80.0,
    //             DBasic<4, 2, 4>());

    //   test_mult(DBasic<1, 4, 7>(32.0), Base<DimTime>(3.0), 96.0,
    //             DBasic<1, 4, 8>());

    //   test_mult(DBasic<1, 5, 6>(16.0), Base<DimLength>(4.0), 64.0,
    //             DBasic<2, 5, 6>());
    // }

    // SUBCASE("Base * Base") {
    //   test_mult(Base<DimLength>(4.0), Base<DimMass>(2.0), 8.0,
    //             DBasic<1, 1, 0>());

    //   test_mult(Base<DimLength>(3.0), Base<DimTime>(8.0), 24.0,
    //             DBasic<1, 0, 1>());

    //   test_mult(Base<DimMass>(5.0), Base<DimTime>(6.0), 30.0,
    //             DBasic<0, 1, 1>());

    //   test_mult(Base<DimLength>(1.0), Base<DimLength>(7.0), 7.0,
    //             DBasic<2, 0, 0>());

    //   test_mult(Base<DimMass>(10.0), Base<DimMass>(12.0), 120.0,
    //             DBasic<0, 2, 0>());

    //   test_mult(Base<DimTime>(9.0), Base<DimTime>(11.0), 99.0,
    //             DBasic<0, 0, 2>());
    // }

    SUBCASE("Unit * Double") {
      test_mult(DBasic<1, 2, 3>(40.0), 10.0, 400.0, DBasic<1, 2, 3>());

      test_mult(DBasic<2, 1, 4>(20.0), 5.0, 100.0, DBasic<2, 1, 4>());
    }
  }

  TEST_CASE("Addition") {
    constexpr auto test_sum = [](auto first, auto second, auto exp_sum) {
      const auto sum_ans = first + second;
      const auto inv_sum = second + first;

      CHECK(sum_ans.data == doctest::Approx(exp_sum));
      CHECK(inv_sum.data == doctest::Approx(exp_sum));
    };

    SUBCASE("Unit + Unit") {
      test_sum(DBasic<3, 2, 0>(20.0), DBasic<3, 2, 0>(50.0), 70.0);

      test_sum(DBasic<-1, -2, -3>(3.0), DBasic<-1, -2, -3>(12.0), 15.0);
    }

    // SUBCASE("Unit + Base") {
    //   test_sum(DBasic<1, 0, 0>(20.0), Base<DimLength>(4.0), 24.0);

    //   test_sum(DBasic<0, 0, 1>(32.0), Base<DimTime>(3.0), 35.0);

    //   test_sum(DBasic<0, 1, 0>(16.0), Base<DimMass>(4.0), 20.0);
    // }

    // SUBCASE("Base + Base") {
    //   test_sum(Base<DimLength>(4.0), Base<DimLength>(2.0), 6.0);

    //   test_sum(Base<DimTime>(3.0), Base<DimTime>(8.0), 11.0);

    //   test_sum(Base<DimMass>(5.0), Base<DimMass>(6.0), 11.0);
    // }
  }

  TEST_CASE("Substraction") {
    constexpr auto test_diff = [](auto first, auto second, auto exp_diff,
                                  auto diff, auto exp_inv) {
      const auto difference = first - second;
      const auto inv_diff = second - first;

      CHECK(difference.data == doctest::Approx(exp_diff));
      CHECK(inv_diff.data == doctest::Approx(exp_inv));

      CHECK(std::is_same_v<std::remove_const_t<decltype(difference)>,
                           std::remove_const_t<decltype(diff)>>);

      CHECK(std::is_same_v<std::remove_const_t<decltype(inv_diff)>,
                           std::remove_const_t<decltype(diff)>>);
    };

    SUBCASE("Unit - Unit") {
      test_diff(DBasic<3, 6, 8>(20.0), DBasic<3, 6, 8>(10.0), 10.0,
                DBasic<3, 6, 8>(), -10.0);

      test_diff(DBasic<1, 2, 3>(24.0), DBasic<1, 2, 3>(12.0), 12.0,
                DBasic<1, 2, 3>(), -12.0);
    }

    // SUBCASE("Unit - Base") {
    //   test_diff(DBasic<1, 0, 0>(20.0), Base<DimLength>(4.0), 16.0,
    //             DBasic<1, 0, 0>(), -16.0);
    // }

    // SUBCASE("Base - Base") {
    //   test_diff(Base<DimMass>(4.0), Base<DimMass>(2.0), 2.0,
    //   Base<DimMass>(0.0),
    //             -2.0);
    // }
  }

  // showcase for 2/22 meeting
  TEST_CASE("Polished Test Case Calculating Velocity") {
    // A race car is traveling at a constant velocity and travels 100 meters in
    // 10 seconds. What is the race car's velocity?
    const auto distance = Meter(100.0);
    const auto time = Seconds(10.0);

    // our answer is held here
    const auto velocity = distance / time;
    CHECK(velocity.data == doctest::Approx(10.0));
    CHECK(std::is_same_v<std::remove_const_t<decltype(velocity)>,
                         DBasic<1, 0, -1>>);

    // std::cout << std::endl
    //           << "Question 1" << std::endl
    //           << "The race car is traveling at a velocity of " <<
    //           velocity.data
    //           << " m/s" << std::endl
    //           << std::endl;
  }

  TEST_CASE("Polished Test Case Calculating Acceleration") {
    // A race car has a 50 m/s change in velocity in 2 seconds. What is the
    // acceleration of the race car?
    const auto velocity_delta = MeterPerSecond(50.0);
    const auto time = Seconds(2.0);

    // our answer is held here
    const auto acceleration = velocity_delta / time;
    CHECK(acceleration.data == doctest::Approx(25.0));
    CHECK(std::is_same_v<std::remove_const_t<decltype(acceleration)>,
                         DBasic<1, 0, -2>>);

    // std::cout << "Question 2a" << std::endl
    //           << "The race car has an acceleration of " << acceleration.data
    //           << " m/s^2" << std::endl
    //           << std::endl;

    // The mass of the race car is 800 kg. Using the calculated acceleration
    // from above, what is the force on the car?
    const auto mass = Kilograms(800.0);

    // our answer is held here
    const auto force = mass * acceleration;
    CHECK(force.data == doctest::Approx(20000.0));
    CHECK(
        std::is_same_v<std::remove_const_t<decltype(force)>, DBasic<1, 1, -2>>);

    // std::cout << "Question 2b" << std::endl
    //           << "The race car has a force of " << force.data
    //           << " N being applied to it." << std::endl
    //           << std::endl;
  }

  TEST_CASE("Polished Test Case Calculating Density") {
    // A block of constant density has a length of 0.5 m, a width of 0.25 m, a
    // height of 0.1 m, and a mass of 3 kg. What is the block's density?
    const auto length = Meter(0.5);
    const auto width = Meter(0.25);
    const auto height = Meter(0.1);
    const auto mass = Kilograms(3.0);

    // our answer is held here
    const auto density = mass / (length * width * height);
    CHECK(density.data == doctest::Approx(240.0));
    CHECK(std::is_same_v<std::remove_const_t<decltype(density)>,
                         DBasic<-3, 1, 0>>);

    // std::cout << "Question 3" << std::endl
    //           << "The block has a density of " << density.data << " kg/m^3"
    //           << std::endl
    //           << std::endl;
  }

  // TEST_CASE("Polished Test Case for Pascals to PSI") {
  //   const auto pascal = Pascals(2.0);

  //   const auto psi = Psi(Psi::FromBase(Pascals::ToBase(pascal.data, Exponents<-1, 1, -2>()), Exponents<1, 1, -2>()));

  //   CHECK(psi.data == doctest::Approx(0.0093329024));
  // }

  // TEST_CASE("Polished Test Case for Pascals to PSI") {
  //   const auto psi = Psi(2.0);

  //   const auto pascals = Pascals(Pascals::FromBase(Psi::ToBase(psi.data, Exponents<1, 1, -2>()), Exponents<-1, 1, -2>()));

  //   CHECK(pascals.data == doctest::Approx(428.5912157));
  // }
}
// NOLINTEND(modernize-use-trailing-return-type)
}  // namespace csm_units::test