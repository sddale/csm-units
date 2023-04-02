#include <doctest/doctest.h>

#include <csm_units/units.hpp>
#include <cstdint>

namespace csm_units::test {

// velocity = m/s
using MeterPerSecond = UnitBase<Exponents<1, 0, -1, 0, 0, 0, 0>, double>;
using Meter = UnitBase<Exponents<1, 0, 0, 0, 0, 0, 0>, double>;
using Kilograms = UnitBase<Exponents<0, 1, 0, 0, 0, 0, 0>, double>;
using Seconds = UnitBase<Exponents<0, 0, 1, 0, 0, 0, 0>, double>;
using Ampere = UnitBase<Exponents<0, 0, 0, 1, 0, 0, 0>, double>;
using Kelvin = UnitBase<Exponents<0, 0, 0, 0, 1, 0, 0>, double>;
using Mole = UnitBase<Exponents<0, 0, 0, 0, 0, 1, 0>, double>;
using Candela = UnitBase<Exponents<0, 0, 0, 0, 0, 0, 1>, double>;

// class KilogramConverter {
//  public:
//   [[nodiscard]] constexpr static auto ToBase(double data, intmax_t N)
//   noexcept
//       -> double {
//     if (N < 0) {
//       for (auto i = N; i < 0; ++i) {
//         data /= 1000;
//       }
//     } else {
//       for (auto i = 0; i < N; ++i) {
//         data *= 1000;
//       }
//     }
//     return data;
//   }

//   [[nodiscard]] constexpr static auto FromBase(double data, intmax_t N)
//   noexcept
//       -> double {
//     return ToBase(data, -N);
//   }
// };

// class PoundConverter {
//  public:
//   [[nodiscard]] constexpr static auto ToBase(double data, intmax_t N)
//   noexcept
//       -> double {
//     if (N < 0) {
//       for (auto i = N; i < 0; ++i) {
//         data /= 453.59237;
//       }
//     } else {
//       for (auto i = 0; i < N; ++i) {
//         data *= 453.59237;
//       }
//     }
//     return data;
//   }

//   [[nodiscard]] constexpr static auto FromBase(double data, intmax_t N)
//   noexcept
//       -> double {
//     return ToBase(data, -N);
//   }
// };

// class FeetPerInchesSquaredConverter {
//  public:
//   [[nodiscard]] constexpr static auto ToBase(double data, intmax_t N)
//   noexcept
//       -> double {
//     if (N < 0) {
//       for (auto i = N; i < 0; ++i) {
//         data /= 144 / 0.3048;
//       }
//     } else {
//       for (auto i = 0; i < N; ++i) {
//         data *= 144 / 0.3048;
//       }
//     }
//     return data;
//   }

//   [[nodiscard]] constexpr static auto FromBase(double data, intmax_t N)
//   noexcept
//       -> double {
//     return ToBase(data, -N);
//   }
// };

// using Pascals =
//     UnitBase<Exponents<-1, 1, -2, 0, 0, 0, 0>,
//              Converters<NoConverter, KilogramConverter, NoConverter>,
//              Prefixes<>, double>;
// using Psi = UnitBase<
//     Exponents<1, 1, -2, 0, 0, 0, 0>,
//     Converters<FeetPerInchesSquaredConverter, PoundConverter, NoConverter>,
//     Prefixes<>, double>;

// NOLINTBEGIN(modernize-use-trailing-return-type)
TEST_SUITE("UnitBase") {
  // Tests to make sure that the unit class is working the way we expect

  //     test to make sure the size of the class never exceeds the size of the
  //     data member variable. Force all test cases to stop if it does.
  TEST_CASE("Size") {
    const auto test = UnitBase<Exponents<14, 14, 14, 0, 0, 0, 0>, double>(14.0);
    REQUIRE(sizeof(test) == sizeof(test.data));
  }

  TEST_CASE("Literals temp") {
    const auto meterLength = 40.0_m;
    const auto ref = Meter(40.0);

    CHECK(ref.data == meterLength.data);
    CHECK(std::is_same_v<decltype(ref), decltype(meterLength)>);

    const auto kgMass = 40.0_kg;
    const auto ref2 = Kilograms(40.0);

    CHECK(ref2.data == kgMass.data);
    CHECK(std::is_same_v<decltype(ref2), decltype(kgMass)>);

    const auto secTime = 40.0_s;
    const auto ref3 = Seconds(40.0);

    CHECK(ref3.data == secTime.data);
    CHECK(std::is_same_v<decltype(ref3), decltype(secTime)>);

    const auto ampCurrent = 40.0_A;
    const auto ref4 = Ampere(40.0);

    CHECK(ref4.data == ampCurrent.data);
    CHECK(std::is_same_v<decltype(ref4), decltype(ampCurrent)>);

    const auto tempKel = 40.0_K;
    const auto ref5 = Kelvin(40.0);

    CHECK(ref5.data == tempKel.data);
    CHECK(std::is_same_v<decltype(ref5), decltype(tempKel)>);

    const auto amtMol = 40.0_mol;
    const auto ref6 = Mole(40.0);

    CHECK(ref6.data == amtMol.data);
    CHECK(std::is_same_v<decltype(ref6), decltype(amtMol)>);

    const auto lumCd = 40.0_cd;
    const auto ref7 = Candela(40.0);

    CHECK(ref7.data == lumCd.data);
    CHECK(std::is_same_v<decltype(ref7), decltype(lumCd)>);
  }

  TEST_CASE("Objects") {
    SUBCASE("DimLength") {
      const auto test_length_pow1 =
          UnitBase<Exponents<1, 0, 0, 0, 0, 0, 0>, double>(13.0);
      const auto test_length_pow2 =
          UnitBase<Exponents<2, 0, 0, 0, 0, 0, 0>, double>(13.0);

      CHECK(test_length_pow1.data == doctest::Approx(13.0));
      CHECK(test_length_pow2.data == doctest::Approx(13.0));
    }

    SUBCASE("DimMass") {
      const auto test_mass_pow1 =
          UnitBase<Exponents<0, 1, 0, 0, 0, 0, 0>, double>(13.0);
      const auto test_mass_pow2 =
          UnitBase<Exponents<0, 2, 0, 0, 0, 0, 0>, double>(13.0);

      CHECK(test_mass_pow1.data == doctest::Approx(13.0));
      CHECK(test_mass_pow2.data == doctest::Approx(13.0));
    }

    SUBCASE("DimTime") {
      const auto test_time_pow1 =
          UnitBase<Exponents<0, 0, 1, 0, 0, 0, 0>, double>(13.0);
      const auto test_time_pow2 =
          UnitBase<Exponents<0, 0, 2, 0, 0, 0, 0>, double>(13.0);

      CHECK(test_time_pow1.data == doctest::Approx(13.0));
      CHECK(test_time_pow2.data == doctest::Approx(13.0));
    }

    SUBCASE("Mix of All 3") {
      const auto length1_mass1_time1 =
          UnitBase<Exponents<1, 1, 1, 0, 0, 0, 0>, double>(13.0);
      const auto length2_mass2_time2 =
          UnitBase<Exponents<2, 2, 2, 0, 0, 0, 0>, double>(13.0);
      const auto arbitrary_mix_up =
          UnitBase<Exponents<3, 1, 4, 0, 0, 0, 0>, double>(13.0);

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

    SUBCASE("UnitBase/UnitBase") {
      test_div(UnitBase<Exponents<3, 6, 8, 0, 0, 0, 0>, double>(20.0),
               UnitBase<Exponents<1, 2, 3, 0, 0, 0, 0>, double>(10.0), 2.0,
               UnitBase<Exponents<2, 4, 5, 0, 0, 0, 0>, double>(), 0.5,
               UnitBase<Exponents<-2, -4, -5, 0, 0, 0, 0>, double>());

      test_div(UnitBase<Exponents<1, 2, 3, 0, 0, 0, 0>, double>(24.0),
               UnitBase<Exponents<1, 2, 3, 0, 0, 0, 0>, double>(12.0), 2.0, 0.0,
               0.5, 0.0);
    }

    // SUBCASE("UnitBase/Base") {
    //   test_div(UnitBase<Exponents<3, 2, 4>, double>(20.0), Base<DimLength>,
    //   double>(4.0), 5.0,
    //            UnitBase<Exponents<2, 2, 4>, double>(), 0.2,
    //            UnitBase<Exponents<-2, -2, -4>, double>());
    // }

    // SUBCASE("Base/Base") {
    //   test_div(Base<DimLength>, double>(4.0), Base<DimMass>,
    //   double>(2.0), 2.0,
    //            UnitBase<Exponents<1, -1, 0>, double>(), 0.5,
    //            UnitBase<Exponents<-1, 1, 0>, double>());
    // }

    SUBCASE("UnitBase/Double") {
      test_div(UnitBase<Exponents<1, 2, 3, 0, 0, 0, 0>, double>(40.0), 10.0,
               4.0, UnitBase<Exponents<1, 2, 3, 0, 0, 0, 0>, double>(), 0.25,
               UnitBase<Exponents<-1, -2, -3, 0, 0, 0, 0>, double>());
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

    SUBCASE("UnitBase * UnitBase") {
      test_mult(UnitBase<Exponents<3, 2, 0, 0, 0, 0, 0>, double>(20.0),
                UnitBase<Exponents<1, 0, 3, 0, 0, 0, 0>, double>(50.0), 1000.0,
                UnitBase<Exponents<4, 2, 3, 0, 0, 0, 0>, double>());

      test_mult(UnitBase<Exponents<-1, -2, -3, 0, 0, 0, 0>, double>(3.0),
                UnitBase<Exponents<1, 2, 3, 0, 0, 0, 0>, double>(12.0), 36.0,
                0.0);
    }

    // SUBCASE("UnitBase * Base") {
    //   test_mult(UnitBase<Exponents<3, 2, 4>(20.0),
    //   Base<DimLength>(4.0), 80.0,
    //             UnitBase<Exponents<4, 2, 4>());

    //   test_mult(UnitBase<Exponents<1, 4, 7>(32.0), Base<DimTime>(3.0), 96.0,
    //             UnitBase<Exponents<1, 4, 8>());

    //   test_mult(UnitBase<Exponents<1, 5, 6>(16.0),
    //   Base<DimLength>(4.0), 64.0,
    //             UnitBase<Exponents<2, 5, 6>());
    // }

    // SUBCASE("Base * Base") {
    //   test_mult(Base<DimLength>(4.0), Base<DimMass>(2.0), 8.0,
    //             UnitBase<Exponents<1, 1, 0>());

    //   test_mult(Base<DimLength>(3.0), Base<DimTime>(8.0), 24.0,
    //             UnitBase<Exponents<1, 0, 1>());

    //   test_mult(Base<DimMass>(5.0), Base<DimTime>(6.0), 30.0,
    //             UnitBase<Exponents<0, 1, 1>());

    //   test_mult(Base<DimLength>(1.0), Base<DimLength>(7.0), 7.0,
    //             UnitBase<Exponents<2, 0, 0>());

    //   test_mult(Base<DimMass>(10.0), Base<DimMass>(12.0), 120.0,
    //             UnitBase<Exponents<0, 2, 0>());

    //   test_mult(Base<DimTime>(9.0), Base<DimTime>(11.0), 99.0,
    //             UnitBase<Exponents<0, 0, 2>());
    // }

    SUBCASE("UnitBase * Double") {
      test_mult(UnitBase<Exponents<1, 2, 3, 0, 0, 0, 0>, double>(40.0), 10.0,
                400.0, UnitBase<Exponents<1, 2, 3, 0, 0, 0, 0>, double>());

      test_mult(UnitBase<Exponents<2, 1, 4, 0, 0, 0, 0>, double>(20.0), 5.0,
                100.0, UnitBase<Exponents<2, 1, 4, 0, 0, 0, 0>, double>());
    }
  }

  TEST_CASE("Addition") {
    constexpr auto test_sum = [](auto first, auto second, auto exp_sum) {
      const auto sum_ans = first + second;
      const auto inv_sum = second + first;

      CHECK(sum_ans.data == doctest::Approx(exp_sum));
      CHECK(inv_sum.data == doctest::Approx(exp_sum));
    };

    SUBCASE("UnitBase + UnitBase") {
      test_sum(UnitBase<Exponents<3, 2, 0, 0, 0, 0, 0>, double>(20.0),
               UnitBase<Exponents<3, 2, 0, 0, 0, 0, 0>, double>(50.0), 70.0);

      test_sum(UnitBase<Exponents<-1, -2, -3, 0, 0, 0, 0>, double>(3.0),
               UnitBase<Exponents<-1, -2, -3, 0, 0, 0, 0>, double>(12.0), 15.0);
    }

    // SUBCASE("UnitBase + Base") {
    //   test_sum(UnitBase<Exponents<1, 0, 0>(20.0),
    //   Base<DimLength>(4.0), 24.0);

    //   test_sum(UnitBase<Exponents<0, 0, 1>(32.0), Base<DimTime>(3.0), 35.0);

    //   test_sum(UnitBase<Exponents<0, 1, 0>(16.0), Base<DimMass>(4.0), 20.0);
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

    SUBCASE("UnitBase - UnitBase") {
      test_diff(UnitBase<Exponents<3, 6, 8, 0, 0, 0, 0>, double>(20.0),
                UnitBase<Exponents<3, 6, 8, 0, 0, 0, 0>, double>(10.0), 10.0,
                UnitBase<Exponents<3, 6, 8, 0, 0, 0, 0>, double>(), -10.0);

      test_diff(UnitBase<Exponents<1, 2, 3, 0, 0, 0, 0>, double>(24.0),
                UnitBase<Exponents<1, 2, 3, 0, 0, 0, 0>, double>(12.0), 12.0,
                UnitBase<Exponents<1, 2, 3, 0, 0, 0, 0>, double>(), -12.0);
    }

    // SUBCASE("UnitBase - Base") {
    //   test_diff(UnitBase<Exponents<1, 0, 0>(20.0),
    //   Base<DimLength>(4.0), 16.0,
    //             UnitBase<Exponents<1, 0, 0>(), -16.0);
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
                         UnitBase<Exponents<1, 0, -1, 0, 0, 0, 0>, double>>);

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
                         UnitBase<Exponents<1, 0, -2, 0, 0, 0, 0>, double>>);

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
    CHECK(std::is_same_v<std::remove_const_t<decltype(force)>,
                         UnitBase<Exponents<1, 1, -2, 0, 0, 0, 0>, double>>);

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
                         UnitBase<Exponents<-3, 1, 0, 0, 0, 0, 0>, double>>);

    // std::cout << "Question 3" << std::endl
    //           << "The block has a density of " << density.data << " kg/m^3"
    //           << std::endl
    //           << std::endl;
  }

  // TEST_CASE("Polished Test Case for Pascals to PSI") {
  //   const auto pascal = Pascals(2.0);

  //   const auto psi = Psi(Psi::FromBase(Pascals::ToBase(pascal.data)));

  //   CHECK(psi.data == doctest::Approx(0.0093329024));
  // }

  // TEST_CASE("Polished Test Case for Pascals to PSI") {
  //   const auto psi = Psi(2.0);

  //   const auto pascals = Pascals(Pascals::FromBase(Psi::ToBase(psi.data)));

  //   CHECK(pascals.data == doctest::Approx(428.5912157));
  // }
}
// NOLINTEND(modernize-use-trailing-return-type)
}  // namespace csm_units::test