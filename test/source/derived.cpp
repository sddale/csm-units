#include <doctest/doctest.h>

#include <csm_units/units.hpp>
#include <iostream>

namespace csm_units::test {

template <int LP, int MP, int TP>
using DBasic =
    Derived<Base<DimLength>, LP, Base<DimMass>, MP, Base<DimTime>, TP, double>;

// for polished test cases
using Meter = DBasic<1, 0, 0>;
using Seconds = DBasic<0, 0, 1>;
using Kilograms = DBasic<0, 1, 0>;

// velocity = m/s
using MeterPerSecond = DBasic<1, 0, -1>;

// NOLINTBEGIN(modernize-use-trailing-return-type)
TEST_SUITE("Derived") {
  // Tests to make sure that the derived class is working the way we expect

  // test to make sure the size of the class never exceeds the size of the data
  // member variable. Force all test cases to stop if it does.
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
    const auto length2_mass2 = DBasic<2, 2, 0>(20.0);
    const auto length1 = DBasic<1, 0, 0>(2.0);
    const auto mass1 = DBasic<0, 1, 0>(10.0);
    const auto base_dim_length = Base<DimLength>(4.0);
    const auto base_dim_mass = Base<DimMass>(2.0);

    const auto quotient_derived_derived = length2_mass2 / mass1;
    const auto quotient_derived_base = length2_mass2 / base_dim_length;
    const auto quotient_base_derived = base_dim_length / length1;
    const auto quotient_base_base = base_dim_length / base_dim_mass;
    const auto quotient_derived_double = length2_mass2 / 10.0;
    const auto quotient_double_derived = 40.0 / length2_mass2;

    CHECK(quotient_derived_derived.data == doctest::Approx(2.0));
    CHECK(quotient_derived_base.data == doctest::Approx(5.0));
    CHECK(quotient_base_derived.data == doctest::Approx(2.0));
    CHECK(quotient_base_base.data == doctest::Approx(2.0));
    CHECK(quotient_derived_double.data == doctest::Approx(2.0));
    CHECK(quotient_double_derived.data == doctest::Approx(2.0));

    CHECK(
        std::is_same_v<std::remove_const_t<decltype(quotient_derived_derived)>,
                       DBasic<2, 1, 0>>);
    CHECK(std::is_same_v<std::remove_const_t<decltype(quotient_derived_base)>,
                         DBasic<1, 2, 0>>);
    CHECK(std::is_same_v<std::remove_const_t<decltype(quotient_base_derived)>,
                         DBasic<0, 0, 0>>);
    CHECK(std::is_same_v<std::remove_const_t<decltype(quotient_base_base)>,
                         DBasic<1, -1, 0>>);
    CHECK(std::is_same_v<decltype(quotient_derived_double),
                         decltype(length2_mass2)>);
    CHECK(std::is_same_v<std::remove_const_t<decltype(quotient_double_derived)>,
                         DBasic<-2, -2, 0>>);
  }

  TEST_CASE("Multiplication") {
    // bases
    const auto len_base = Base<DimLength>(4.0);  // <1, 0, 0>
    const auto mass_base = Base<DimMass>(2.0);   // <0, 1, 0>

    // derived
    const auto len3_mass2 = DBasic<3, 2, 0>(20.0);
    const auto len1_time3 = DBasic<1, 0, 3>(50.0);
    const auto mass2_time2 = DBasic<0, 2, 2>(5.0);
    const auto len1_mass3_time2 = DBasic<1, 3, 2>(60.0);

    SUBCASE("Multiplication Combinations") {
      const auto deriv_deriv = len3_mass2 * len1_time3;
      const auto deriv_base = len1_mass3_time2 * mass_base;
      const auto base_deriv = len_base * mass2_time2;
      const auto base_base = len_base * mass_base;
      const auto double_deriv = 3.0 * len3_mass2;
      const auto deriv_double = len1_time3 * 5.0;

      CHECK(deriv_deriv.data == doctest::Approx(1000.0));
      CHECK(deriv_base.data == doctest::Approx(120.0));
      CHECK(base_deriv.data == doctest::Approx(20.0));
      CHECK(base_base.data == doctest::Approx(8.0));
      CHECK(double_deriv.data == doctest::Approx(60.0));
      CHECK(deriv_double.data == doctest::Approx(250.0));

      CHECK(std::is_same_v<std::remove_const_t<decltype(deriv_deriv)>,
                           DBasic<4, 2, 3>>);
      CHECK(std::is_same_v<std::remove_const_t<decltype(deriv_base)>,
                           DBasic<1, 4, 2>>);
      CHECK(std::is_same_v<std::remove_const_t<decltype(base_deriv)>,
                           DBasic<1, 2, 2>>);
      CHECK(std::is_same_v<std::remove_const_t<decltype(base_base)>,
                           DBasic<1, 1, 0>>);
    }

    SUBCASE("Multiplication Combinations 2") {
      const auto deriv_deriv = len1_time3 * mass2_time2;
      const auto deriv_base = len3_mass2 * len_base;
      const auto base_deriv = mass_base * len1_mass3_time2;
      const auto base_base = mass_base * len_base;
      const auto double_deriv = 10.0 * len1_time3;
      const auto deriv_double = mass2_time2 * 2.0;

      CHECK(deriv_deriv.data == doctest::Approx(250.0));
      CHECK(deriv_base.data == doctest::Approx(80.0));
      CHECK(base_deriv.data == doctest::Approx(120.0));
      CHECK(base_base.data == doctest::Approx(8.0));
      CHECK(double_deriv.data == doctest::Approx(500.0));
      CHECK(deriv_double.data == doctest::Approx(10.0));

      CHECK(std::is_same_v<std::remove_const_t<decltype(deriv_deriv)>,
                           DBasic<1, 2, 5>>);
      CHECK(std::is_same_v<std::remove_const_t<decltype(deriv_base)>,
                           DBasic<4, 2, 0>>);
      CHECK(std::is_same_v<std::remove_const_t<decltype(base_deriv)>,
                           DBasic<1, 4, 2>>);
      CHECK(std::is_same_v<std::remove_const_t<decltype(base_base)>,
                           DBasic<1, 1, 0>>);
    }

    SUBCASE("True Decimals") {
      const auto len = DBasic<1, 0, 0>(5.6839);
      const auto mass = DBasic<0, 1, 0>(42.0422);
      const double num = 2.9204203;

      const auto check1 = len * mass;
      const auto check2 = num * mass;

      CHECK(check1.data == doctest::Approx(238.963660));
      CHECK(check2.data == doctest::Approx(122.780894));
      CHECK(std::is_same_v<std::remove_const_t<decltype(check1)>,
                           DBasic<1, 1, 0>>);
      CHECK(std::is_same_v<std::remove_const_t<decltype(check2)>,
                           DBasic<0, 1, 0>>);
    }
  }

  TEST_CASE("Addition") {
    // derived
    const auto len_obj = DBasic<1, 0, 0>(20.0);
    const auto len_same = DBasic<1, 0, 0>(10.0);
    const auto mass_obj = DBasic<0, 1, 0>(50.0);
    const auto mass_same = DBasic<0, 1, 0>(15.0);
    const auto deriv_obj = DBasic<1, 0, 2>(5.0);
    const auto deriv_same = DBasic<1, 0, 2>(10.0);

    // bases
    const auto len_base = Base<DimLength>(4.0);
    const auto mass_base = Base<DimMass>(6.0);

    SUBCASE("Addition Combinations") {
      const auto len_sum = len_obj + len_same;
      const auto mass_sum = mass_obj + mass_same;
      const auto deriv_sum = deriv_obj + deriv_same;
      const auto deriv_base = len_obj + len_base;
      const auto base_deriv = mass_base + mass_obj;

      CHECK(len_sum.data == doctest::Approx(30.0));
      CHECK(mass_sum.data == doctest::Approx(65.0));
      CHECK(deriv_sum.data == doctest::Approx(15.0));
      CHECK(deriv_base.data == doctest::Approx(24.0));
      CHECK(base_deriv.data == doctest::Approx(56.0));
      CHECK(std::is_same_v<std::remove_const_t<decltype(len_sum)>,
                           DBasic<1, 0, 0>>);
      CHECK(std::is_same_v<std::remove_const_t<decltype(mass_sum)>,
                           DBasic<0, 1, 0>>);
      CHECK(std::is_same_v<std::remove_const_t<decltype(deriv_sum)>,
                           DBasic<1, 0, 2>>);
      CHECK(std::is_same_v<std::remove_const_t<decltype(deriv_base)>,
                           DBasic<1, 0, 0>>);
      CHECK(std::is_same_v<std::remove_const_t<decltype(base_deriv)>,
                           DBasic<0, 1, 0>>);
    }

    SUBCASE("True Decimals") {}
  }

  TEST_CASE("Substraction") {}

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

    std::cout << std::endl
              << "Question 1" << std::endl
              << "The race car is traveling at a velocity of " << velocity.data
              << " m/s" << std::endl
              << std::endl;
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

    std::cout << "Question 2a" << std::endl
              << "The race car has an acceleration of " << acceleration.data
              << " m/s^2" << std::endl
              << std::endl;

    // The mass of the race car is 800 kg. Using the calculated acceleration
    // from above, what is the force on the car?
    const auto mass = Kilograms(800.0);

    // our answer is held here
    const auto force = mass * acceleration;
    CHECK(force.data == doctest::Approx(20000.0));
    CHECK(
        std::is_same_v<std::remove_const_t<decltype(force)>, DBasic<1, 1, -2>>);

    std::cout << "Question 2b" << std::endl
              << "The race car has a force of " << force.data
              << " N being applied to it." << std::endl
              << std::endl;
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

    std::cout << "Question 3" << std::endl
              << "The block has a density of " << density.data << " kg/m^3"
              << std::endl
              << std::endl;
  }
}
// NOLINTEND(modernize-use-trailing-return-type)
}  // namespace csm_units::test