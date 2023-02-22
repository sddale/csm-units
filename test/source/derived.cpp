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
    // working for now
    const auto length2_mass2 = DBasic<2, 2, 0>(20.0);
    const auto length1 = DBasic<1, 0, 0>(2.0);
    const auto check = length2_mass2 * length1;

    CHECK(check.data == doctest::Approx(40.0));
    CHECK(
        std::is_same_v<std::remove_const_t<decltype(check)>, DBasic<3, 2, 0>>);
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

    std::cout << "Question 2b" << std::endl
              << "The race car has a force of " << force.data
              << " N being applied to it." << std::endl
              << std::endl;
  }
}
// NOLINTEND(modernize-use-trailing-return-type)
}  // namespace csm_units::test