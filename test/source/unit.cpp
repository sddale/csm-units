
#include "source/csm_units/unit.hpp"

#include <doctest/doctest.h>

#include <csm_units/units.hpp>

#include "source/csm_units/exponents.hpp"
#include "source/csm_units/literal/literal.hpp"
#include "source/csm_units/unitcast.hpp"

namespace csm_units::test {

// NOLINTBEGIN(modernize-use-trailing-return-type, misc-use-anonymous-namespace)

constexpr auto CHECK_TYPE = [](auto input, auto ref) {
  CHECK(std::is_same_v<std::remove_const_t<decltype(input)>,
                       std::remove_const_t<decltype(ref)>>);
};

constexpr auto CHECK_DBL_EQ = [](auto lhs, auto rhs) {
  CHECK_EQ(lhs, doctest::Approx(rhs));
};

constexpr auto test_sum = [](auto first, auto second, auto base,
                             auto exp_default_sum, auto exp_first_sum,
                             auto exp_second_sum) {
  const auto default_sum_ans = first + second;
  const decltype(first) forced_first_ans = first + second;
  const decltype(second) forced_sec_ans = first + second;

  const auto default_inv = second + first;
  const decltype(first) forced_first_inv = second + first;
  const decltype(second) forced_sec_inv = second + first;

  CHECK(default_sum_ans.data == doctest::Approx(exp_default_sum));
  CHECK(forced_first_ans.data == doctest::Approx(exp_first_sum));
  CHECK(forced_sec_ans.data == doctest::Approx(exp_second_sum));
  CHECK_TYPE(default_sum_ans, base);
  CHECK_TYPE(forced_first_ans, first);
  CHECK_TYPE(forced_sec_ans, second);

  CHECK(default_inv.data == doctest::Approx(exp_default_sum));
  CHECK(forced_first_inv.data == doctest::Approx(exp_first_sum));
  CHECK(forced_sec_inv.data == doctest::Approx(exp_second_sum));
  CHECK_TYPE(default_inv, base);
  CHECK_TYPE(forced_first_inv, first);
  CHECK_TYPE(forced_sec_inv, second);

  decltype(first) test_first = first;
  decltype(second) test_second = second;

  test_first += second;
  test_second += first;

  CHECK(test_first.data == doctest::Approx(forced_first_ans.data));
  CHECK(test_second.data == doctest::Approx(forced_sec_inv.data));
};

constexpr auto test_diff = [](auto first, auto second, auto base,
                              auto exp_default_diff, auto exp_first_diff,
                              auto exp_second_diff) {
  const auto default_diff_ans = first - second;
  const decltype(first) forced_first_ans = first - second;
  const decltype(second) forced_sec_ans = first - second;

  const auto default_inv = second - first;
  const decltype(first) forced_first_inv = second - first;
  const decltype(second) forced_sec_inv = second - first;

  CHECK(default_diff_ans.data == doctest::Approx(exp_default_diff));
  CHECK(forced_first_ans.data == doctest::Approx(exp_first_diff));
  CHECK(forced_sec_ans.data == doctest::Approx(exp_second_diff));
  CHECK_TYPE(default_diff_ans, base);
  CHECK_TYPE(forced_first_ans, first);
  CHECK_TYPE(forced_sec_ans, second);

  CHECK(default_inv.data == doctest::Approx(-exp_default_diff));
  CHECK(forced_first_inv.data == doctest::Approx(-exp_first_diff));
  CHECK(forced_sec_inv.data == doctest::Approx(-exp_second_diff));
  CHECK_TYPE(default_inv, base);
  CHECK_TYPE(forced_first_inv, first);
  CHECK_TYPE(forced_sec_inv, second);

  decltype(first) test_first = first;
  decltype(second) test_second = second;

  test_first -= second;
  test_second -= first;

  CHECK(test_first.data == doctest::Approx(forced_first_ans.data));
  CHECK(test_second.data == doctest::Approx(forced_sec_inv.data));
};

constexpr auto test_temp_diff = [](auto first, auto second, auto base,
                                   auto exp_default_diff, auto exp_first_diff,
                                   auto exp_second_diff, auto exp_default_inv,
                                   auto exp_first_inv, auto exp_second_inv) {
  const auto default_diff_ans = first - second;
  const decltype(first) forced_first_ans = first - second;
  const decltype(second) forced_sec_ans = first - second;

  const auto default_inv = second - first;
  const decltype(first) forced_first_inv = second - first;
  const decltype(second) forced_sec_inv = second - first;

  CHECK(default_diff_ans.data == doctest::Approx(exp_default_diff));
  CHECK(forced_first_ans.data == doctest::Approx(exp_first_diff));
  CHECK(forced_sec_ans.data == doctest::Approx(exp_second_diff));
  CHECK_TYPE(default_diff_ans, base);
  CHECK_TYPE(forced_first_ans, first);
  CHECK_TYPE(forced_sec_ans, second);

  CHECK(default_inv.data == doctest::Approx(exp_default_inv));
  CHECK(forced_first_inv.data == doctest::Approx(exp_first_inv));
  CHECK(forced_sec_inv.data == doctest::Approx(exp_second_inv));
  CHECK_TYPE(default_inv, base);
  CHECK_TYPE(forced_first_inv, first);
  CHECK_TYPE(forced_sec_inv, second);

  decltype(first) test_first = first;
  decltype(second) test_second = second;

  test_first -= second;
  test_second -= first;

  CHECK(test_first.data == doctest::Approx(exp_first_diff));
  CHECK(test_second.data == doctest::Approx(exp_second_inv));
};

constexpr auto test_mult = [](auto first, auto second, auto default_ans_type,
                              auto forced_ans_type, auto exp_default_ans,
                              auto exp_forced_ans) {
  const auto default_diff_ans = first * second;
  const decltype(forced_ans_type) forced_ans = first * second;

  const auto default_inv = second * first;
  const decltype(forced_ans_type) forced_inv = second * first;

  if constexpr (std::is_convertible_v<decltype(default_ans_type), double>) {
    CHECK_DBL_EQ(default_diff_ans, exp_default_ans);
    CHECK_DBL_EQ(forced_ans, exp_forced_ans);

    CHECK_DBL_EQ(default_inv, exp_default_ans);
    CHECK_DBL_EQ(forced_inv, exp_forced_ans);
  } else {
    CHECK_DBL_EQ(default_diff_ans.data, exp_default_ans);
    CHECK_DBL_EQ(forced_ans.data, exp_forced_ans);

    CHECK_DBL_EQ(default_inv.data, exp_default_ans);
    CHECK_DBL_EQ(forced_inv.data, exp_forced_ans);
  }

  CHECK_TYPE(default_diff_ans, default_ans_type);

  CHECK_TYPE(default_inv, default_ans_type);
};

constexpr auto test_div =
    [](auto first, auto second, auto default_ans_type, auto forced_ans_type,
       auto default_inv_type, auto forced_inv_type, auto exp_default_ans,
       auto exp_forced_ans, auto exp_default_inv, auto exp_forced_inv) {
      const auto default_diff_ans = first / second;
      const decltype(forced_ans_type) forced_ans = first / second;

      const auto default_inv = second / first;
      const decltype(forced_inv_type) forced_inv = second / first;

      if constexpr (std::is_convertible_v<decltype(default_ans_type), double>) {
        CHECK_DBL_EQ(default_diff_ans, exp_default_ans);
        CHECK_DBL_EQ(forced_ans, exp_forced_ans);

        CHECK_DBL_EQ(default_inv, exp_default_inv);
        CHECK_DBL_EQ(forced_inv, exp_forced_inv);
      } else {
        CHECK_DBL_EQ(default_diff_ans.data, exp_default_ans);
        CHECK_DBL_EQ(forced_ans.data, exp_forced_ans);

        CHECK_DBL_EQ(default_inv.data, exp_default_inv);
        CHECK_DBL_EQ(forced_inv.data, exp_forced_inv);
      }

      CHECK_TYPE(default_diff_ans, default_ans_type);

      CHECK_TYPE(default_inv, default_inv_type);
    };

TEST_SUITE("Unit") {
  TEST_CASE("Size") {
    const auto test = Kilogram(14.0);
    REQUIRE(sizeof(test) == sizeof(test.data));
  }

  TEST_CASE("Unit Tests") {
    SUBCASE("Unit-Unit Base Addition") {
      const auto kg_unit = Kilogram(3.0);
      const auto mass = Mass(4);
      const auto test = kg_unit + mass;
      CHECK_DBL_EQ(test.data, 7.0);
      CHECK_TYPE(test, Mass());
    }

    SUBCASE("Unit-Unit Addition") {
      const auto test = Gram(3.0) + Gram(4.0);
      CHECK_DBL_EQ(test.data, 0.007);
      CHECK_TYPE(test, Mass());
    }

    // Below is the start of in depth tests on different bases to make sure
    // everything is working as expected
    SUBCASE("Length Tests") {
      // Base Length and Unit Meter have tests on 4 types of arithmetic. All
      // others only have tests on addition to prove that unit casting works for
      // all of them
      SUBCASE("Base Length Tests") {
        SUBCASE("Addition Tests") {
          test_sum(Length(34.7), Length(13.6), Length(), 48.3, 48.3, 48.3);
          test_sum(Length(6.3), Meter(3.5), Length(), 9.8, 9.8, 9.8);
          test_sum(Length(6.3), CentiMeter(3.5), Length(), 6.335, 6.335, 633.5);
          test_sum(Length(6.3), MilliMeter(3.5), Length(), 6.3035, 6.3035,
                   6303.5);
          test_sum(Length(6.3), KiloMeter(3.5), Length(), 3506.3, 3506.3,
                   3.5063);
          test_sum(Length(6.3), Inch(2.3), Length(), 6.35842, 6.35842, 250.331);
          test_sum(Length(14.6), Feet(32.5), Length(), 24.506, 24.506,
                   80.40026);
          test_sum(Length(13.4), Yard(24.7), Length(), 35.98568, 35.98568,
                   39.35442);
          test_sum(Length(23.8), Miles(45.9), Length(), 73892.69, 73892.69,
                   45.91478863);
        }

        SUBCASE("Subtraction Tests") {
          test_diff(Length(12.3), Length(15.4), Length(), -3.1, -3.1, -3.1);
          test_diff(Length(45.89), KiloMeter(3.9), Length(), -3854.11, -3854.11,
                    -3.85411);
        }

        SUBCASE("Multiplication Tests") {
          // Base * Base
          test_mult(Length(23.8), Length(12.9), Area(), SqFt(), 307.02,
                    3304.73578);
          // Base * Unit
          test_mult(Length(23.8), Yard(12.9), Area(), SqFt(), 280.739088,
                    3021.850393701);
          // Base * double
          test_mult(Length(3.2), 29.7, Length(), Miles(), 95.04, 0.059055118);
          // Base * inv_base
          test_mult(Length(67.2), InvLength(12.9), 0.0, 0.0, 866.88, 866.88);
          // Base * inv_unit
          test_mult(Length(5.8), InvMeter(3.2), 0.0, 0.0, 18.56, 18.56);
        }

        SUBCASE("Division Tests") {
          // Base / Base
          test_div(Length(25.5), Length(5.5), 0.0, 0.0, 0.0, 0.0, 4.636363636,
                   4.636363636, 0.2156862745, 0.2156862745);
          // Base / Unit - result double
          test_div(Length(48.6), CentiMeter(1234.6), 0.0, 0.0, 0.0, 0.0,
                   3.936497651, 3.936497651, 0.2540329218, 0.2540329218);
          // Base / Different Unit
          test_div(Length(23.5), Gram(3.2),
                   UnitBase<Exponents<1, -1, 0, 0, 0, 0, 0>, double>(),
                   UnitBase<Exponents<1, -1, 0, 0, 0, 0, 0>, double>(),
                   UnitBase<Exponents<-1, 1, 0, 0, 0, 0, 0>, double>(),
                   UnitBase<Exponents<-1, 1, 0, 0, 0, 0, 0>, double>(), 7343.75,
                   7343.75, 0.0001361702128, 0.0001361702128);
          // Base / double
          test_div(Length(45.7), 6.9, Length(), KiloMeter(), InvLength(),
                   InvMeter(), 6.623188406, 0.0066231884, 0.1509846827,
                   0.1509846827);
        }
      }

      SUBCASE("Unit Meter Tests") {
        SUBCASE("Addition Tests") {
          test_sum(Meter(23.8), Meter(13.2), Length(), 37.0, 37.0, 37.0);
          test_sum(Meter(6.3), CentiMeter(3.5), Length(), 6.335, 6.335, 633.5);
          test_sum(Meter(6.3), MilliMeter(3.5), Length(), 6.3035, 6.3035,
                   6303.5);
          test_sum(Meter(6.3), KiloMeter(3.5), Length(), 3506.3, 3506.3,
                   3.5063);
          test_sum(Meter(6.3), Inch(2.3), Length(), 6.35842, 6.35842, 250.331);
          test_sum(Meter(14.6), Feet(32.5), Length(), 24.506, 24.506, 80.40026);
          test_sum(Meter(13.4), Yard(24.7), Length(), 35.98568, 35.98568,
                   39.35442);
          test_sum(Meter(23.8), Miles(45.9), Length(), 73892.69, 73892.69,
                   45.91478863);
        }

        SUBCASE("Subtraction Tests") {
          test_diff(Meter(12.3), Meter(15.4), Length(), -3.1, -3.1, -3.1);
          test_diff(Meter(45.89), Length(3.9), Length(), 41.99, 41.99, 41.99);
          test_diff(Meter(12.3), Feet(15.4), Length(), 7.60608, 7.60608,
                    24.95433071);
        }

        SUBCASE("Multiplication Tests") {
          // Unit * Unit
          test_mult(Meter(23.8), Inch(12.9), Area(), SqFt(), 7.798308,
                    83.940288714);
          // Unit * double
          test_mult(Meter(3.2), 29.7, Length(), Miles(), 95.04, 0.059055118);
          // Unit * inv_base
          test_mult(Meter(67.2), InvLength(12.9), 0.0, 0.0, 866.88, 866.88);
          // Unit * inv_unit
          test_mult(Meter(5.8), InvMeter(3.2), 0.0, 0.0, 18.56, 18.56);
        }

        SUBCASE("Division Tests") {
          // Unit / Unit - result double
          test_div(Meter(34.6), MilliMeter(3.6), 0.0, 0.0, 0.0, 0.0,
                   9611.111111, 9611.111111, 0.0001040462428, 0.0001040462428);
          // Unit / Different Unit
          // Unit / double
        }
      }

      SUBCASE("Unit cm Tests") {
        test_sum(CentiMeter(23.8), CentiMeter(13.2), Length(), 0.37, 37.0,
                 37.0);
        test_sum(CentiMeter(6.3), MilliMeter(3.5), Length(), 0.0665, 6.65,
                 66.5);
        test_sum(CentiMeter(6.3), KiloMeter(3.5), Length(), 3500.063, 350006.3,
                 3.500063);
        test_sum(CentiMeter(6.3), Inch(2.3), Length(), 0.1214202769,
                 12.14202769, 4.7803163);
        test_sum(CentiMeter(14.6), Feet(32.5), Length(), 10.052, 1005.2,
                 32.97900262);
        test_sum(CentiMeter(13.4), Yard(24.7), Length(), 22.71968, 2271.968,
                 24.846544182);
        test_sum(CentiMeter(23.8), Miles(45.9), Length(), 73869.128, 7386912.8,
                 45.9001481349);
      }

      SUBCASE("Unit mm Tests") {
        test_sum(MilliMeter(23.8), MilliMeter(13.2), Length(), 0.037, 37.0,
                 37.0);
        test_sum(MilliMeter(6.3), KiloMeter(3.5), Length(), 3500.0035,
                 3500003.5, 3.5000035);
        test_sum(MilliMeter(6.3), Inch(2.3), Length(), 0.06472, 64.72,
                 2.5480315);
        test_sum(MilliMeter(14.6), Feet(32.5), Length(), 9.9206, 9920.6,
                 32.5479003);
        test_sum(MilliMeter(13.4), Yard(24.7), Length(), 22.59908, 22599.08,
                 24.714654418);
        test_sum(MilliMeter(23.8), Miles(45.9), Length(), 73869.0238,
                 73869023.8, 45.90008338801);
      }

      SUBCASE("Unit km Tests") {
        test_sum(KiloMeter(23.8), KiloMeter(13.2), Length(), 37000.0, 37.0,
                 37.0);
        test_sum(KiloMeter(6.3), Inch(2.3), Length(), 6300.05842, 6.30005842,
                 248033.796063);
        test_sum(KiloMeter(14.6), Feet(32.5), Length(), 14609.906, 14.609906,
                 47932.7624672);
        test_sum(KiloMeter(13.4), Yard(24.7), Length(), 13422.58568,
                 13.42258568, 14679.118197725);
        test_sum(KiloMeter(23.8), Miles(45.9), Length(), 97668.89, 97.66889,
                 60.688634624);
      }

      SUBCASE("Unit Inch Tests") {
        test_sum(Inch(23.8), Inch(13.2), Length(), 0.9398, 37.0, 37.0);
        test_sum(Inch(14.6), Feet(32.5), Length(), 10.27684, 404.6,
                 33.71666667);
        test_sum(Inch(13.4), Yard(24.7), Length(), 22.92604, 902.6, 25.072222);
        test_sum(Inch(23.8), Miles(45.9), Length(), 73869.49412, 2908247.8,
                 45.9003756313);
      }

      SUBCASE("Unit Feet Tests") {
        test_sum(Feet(23.8), Feet(13.2), Length(), 11.2776, 37.0, 37.0);
        test_sum(Feet(13.4), Yard(24.7), Length(), 26.67, 87.5, 29.16667);
        test_sum(Feet(23.8), Miles(45.9), Length(), 73876.14384, 242375.8,
                 45.904507576);
      }

      SUBCASE("Unit Yard Tests") {
        test_sum(Yard(23.8), Yard(13.2), Length(), 33.8328, 37.0, 37.0);
        test_sum(Yard(23.8), Miles(45.9), Length(), 73890.65232, 80807.8,
                 45.91352273);
      }

      SUBCASE("Unit Miles Tests") {
        test_sum(Miles(23.8), Miles(13.2), Length(), 59545.7, 37.0, 37.0);
      }
    }

    SUBCASE("Mass Tests") {
      // Testing to make sure casts in mass work. The above length tests test to
      // make sure arthmetic works in unit and unit base. The below tests just
      // make sure we can convert from and to kilogram and gram
      test_sum(Mass(32.4), Kilogram(2.7), Mass(), 35.1, 35.1, 35.1);
      test_sum(Kilogram(123.5), Gram(24.5), Mass(), 123.5245, 123.5245,
               123524.5);
    }
    SUBCASE("Time Tests") {
      // Testing to make sure casts in time work. The above length tests test to
      // make sure arthmetic works in unit and unit base. The below tests just
      // make sure we can convert from and to seconds, minutes, and hours.
      test_sum(Time(32.4), Second(2.7), Time(), 35.1, 35.1, 35.1);
      test_sum(Hours(123.5), Minutes(24.5), Time(), 446070.0, 123.9083333,
               7434.5);
    }
    SUBCASE("Electric Current Tests") {
      SUBCASE("Electric Current Additions") {
        test_sum(ElectrCurrent(7.2), Ampere(3.4), ElectrCurrent(), 10.6, 10.6,
                 10.6);
        test_sum(ElectrCurrent(4.8), Milliampere(5421.44), ElectrCurrent(),
                 10.22144, 10.22144, 10221.44);
        test_sum(Milliampere(4567.22), Ampere(34.5), ElectrCurrent(), 39.06722,
                 39067.22, 39.06722);
      }
      SUBCASE("Electric Current Subtractions") {
        test_diff(ElectrCurrent(7.2), Ampere(3.4), ElectrCurrent(), 3.8, 3.8,
                  3.8);
        test_diff(ElectrCurrent(14.8), Milliampere(5421.44), ElectrCurrent(),
                  9.37856, 9.37856, 9378.56);
        test_diff(Milliampere(45677.22), Ampere(4.5), ElectrCurrent(), 41.17722,
                  41177.22, 41.17722);
      }
      SUBCASE("Electric Current Multiplications") {
        test_mult(ElectrCurrent(8.7), Ampere(5.3), SqrElectrCurrent(),
                  SqrAmpere(), 46.11, 46.11);
        test_mult(ElectrCurrent(8.7), Milliampere(5300), SqrElectrCurrent(),
                  SqrMilliamp(), 46.11, 46110000);
      }
      SUBCASE("Electric Current Divisions") {}
    }
    SUBCASE("Temperature Tests") {
      SUBCASE("Temperature Additions") {
        test_sum(Temperature(72.4), Kelvin(43.3), Temperature(), 115.7, 115.7,
                 115.7);
        test_sum(Temperature(348.9), Celsius(98.4), Temperature(), 720.45,
                 720.45, 447.3);
        test_sum(Temperature(239.6), Fahrenheit(108.4), Temperature(),
                 555.19444, 555.19444, 539.679992);
        test_sum(Celsius(120.5), Fahrenheit(43.3), Temperature(), 673.0778,
                 399.9278, 751.87004);
      }
      SUBCASE("Temperature Subtractions") {
        test_temp_diff(Temperature(343.8), Kelvin(209.9), Temperature(), 133.9,
                       133.9, 133.9, -133.9, -133.9, -133.9);
        test_temp_diff(Temperature(123.45), Celsius(88.8), Temperature(),
                       -238.5, -238.5, -511.65, 238.5, 238.5, -34.65);
        test_temp_diff(Temperature(436.1), Fahrenheit(12.3), Temperature(),
                       173.8944, 173.8944, -146.66008, -173.8944, -173.8944,
                       -772.67992);
        test_temp_diff(Celsius(120.5), Fahrenheit(43.3), Temperature(),
                       114.2222, -158.9278, -254.07004, -114.2222, -387.3722,
                       -665.26996);
      }
      // No point in multiplying and dividing temperature
    }
    SUBCASE("Amount Tests") {
      SUBCASE("Additions") {
        test_sum(Amount(45.8), Mole(32.6), Amount(), 78.4, 78.4, 78.4);
        test_sum(Amount(560.97), Kilomole(23.9), Amount(), 24460.97, 24460.97,
                 24.46097);
        test_sum(Kilomole(4.3), Mole(560.3), Amount(), 4860.3, 4.8603, 4860.3);
      }
      SUBCASE("Subtractions") {
        test_diff(Amount(67.4), Mole(32.9), Amount(), 34.5, 34.5, 34.5);
        test_diff(Amount(3245.8), Kilomole(2.4), Amount(), 845.8, 845.8,
                  0.8458);
        test_diff(Kilomole(7.3), Mole(560.3), Amount(), 6739.7, 6.7397, 6739.7);
      }
      SUBCASE("Multiplications") {
        test_mult(Amount(8.7), Mole(5.3), SqrAmount(), SqrMole(), 46.11, 46.11);
        test_mult(Amount(806.7), Kilomole(5.3), SqrAmount(), SqrKilomole(),
                  4275510, 4.27551);
      }
      SUBCASE("Divisions") {}
    }
    SUBCASE("Luminosity Tests") {
      SUBCASE("Additions") {
        test_sum(Luminosity(43.5), Candela(87.4), Luminosity(), 130.9, 130.9,
                 130.9);
      }
      SUBCASE("Subtractions") {
        test_diff(Luminosity(76.8), Candela(32.8), Luminosity(), 44.0, 44.0,
                  44.0);
      }
      SUBCASE("Multiplications") {
        test_mult(Luminosity(3.2), Candela(5.4), SqrLuminosity(), SqrCandela(),
                  17.28, 17.28);
      }
      SUBCASE("Divisions") {}
    }
  }

  TEST_CASE("Polished Test Case for psi and pascals") {
    using SqPressure = Exponents<-2, 2, -4, 0, 0, 0, 0>;

    const auto psi = Psi(31.6);
    const auto pascal = Pascal(23.5);
    SUBCASE("Conversion Checking") {
      // Pass pascals to psi and psi to pascals... to make sure conversion
      // works
      SUBCASE("Pressure->Psi") {
        const Psi test = Pressure(23.5);
        CHECK_DBL_EQ(test.data, 0.003408387);
        CHECK_TYPE(test, Psi());
      }
      SUBCASE("Pascal->Psi") {
        const Psi test = Pascal(23.5);
        CHECK_DBL_EQ(test.data, 0.003408387);
        CHECK_TYPE(test, Psi());
      }
      SUBCASE("Psi->Pascal") {
        const Pascal test = Psi(31.6);
        CHECK_DBL_EQ(test.data, 217874.3);
        CHECK_TYPE(test, Pascal());
      }
    }
    SUBCASE("PSI + PASCALS") {
      SUBCASE("Basic addition") {
        const auto test = psi + pascal;
        CHECK_DBL_EQ(test.data, 217897.8);
        CHECK_TYPE(test, Pressure());
      }
      SUBCASE("Force pascal result") {
        const Pascal test = psi + pascal;
        CHECK_DBL_EQ(test.data, 217897.8);
        CHECK_TYPE(test, Pascal());
      }
      SUBCASE("Force psi result") {
        const Psi test = psi + pascal;
        CHECK_DBL_EQ(test.data, 31.60340839);
        CHECK_TYPE(test, Psi());
      }
    }

    SUBCASE("PSI - PASCALS") {
      SUBCASE("Basic Subtraction") {
        const auto test = psi - pascal;
        CHECK_DBL_EQ(test.data, 217850.8);
        CHECK_TYPE(test, Pressure());
      }
      SUBCASE("Force pascal result") {
        const Pascal test = psi - pascal;
        CHECK_DBL_EQ(test.data, 217850.8);
        CHECK_TYPE(test, Pascal());
      }
      SUBCASE("Force psi result") {
        const Psi test = psi - pascal;
        CHECK_DBL_EQ(test.data, 31.596587195);
        CHECK_TYPE(test, Psi());
      }
    }

    SUBCASE("PASCALS - PSI") {
      SUBCASE("Basic Subtraction") {
        const auto test = pascal - psi;
        CHECK_DBL_EQ(test.data, -217850.8);
        CHECK_TYPE(test, Pressure());
      }
      SUBCASE("Force pascal result") {
        const Pascal test = pascal - psi;
        CHECK_DBL_EQ(test.data, -217850.8);
        CHECK_TYPE(test, Pascal());
      }
      SUBCASE("Force psi result") {
        const Psi test = pascal - psi;
        CHECK_DBL_EQ(test.data, -31.596587195);
        CHECK_TYPE(test, Psi());
      }
    }

    SUBCASE("PASCALS * PSI") {
      SUBCASE("Basic Multiplication") {
        const auto test = psi * pascal;
        CHECK_DBL_EQ(test.data, 5120046.05);
        CHECK_TYPE(test, UnitBase<SqPressure, double>());
      }
    }

    SUBCASE("PASCALS / PSI") {
      SUBCASE("Basic Division") {
        const auto test = pascal / psi;
        CHECK(test == doctest::Approx(0.000107860358));
      }
    }

    SUBCASE("Function Passing") {
      SUBCASE("Psi Parameter") {
        constexpr auto lambda = [](Psi input) { return input; };

        const auto test_pa = lambda(Pascal(23.5));
        CHECK_DBL_EQ(test_pa.data, 0.003408387);

        const auto test_psi = lambda(Psi(23.5));
        CHECK_DBL_EQ(test_psi.data, 23.5);
      }

      SUBCASE("Pascal Parameter") {
        constexpr auto lambda = [](Pascal input) { return input; };

        const auto test_pa = lambda(Pascal(31.6));
        CHECK_DBL_EQ(test_pa.data, 31.6);

        const auto test_psi = lambda(Psi(31.6));
        CHECK_DBL_EQ(test_psi.data, 217874.3);
      }

      SUBCASE("Base Pressure Parameter") {
        constexpr auto lambda = [](Pressure input) { return input; };

        const auto test_pa = lambda(Pascal(31.6));
        CHECK_DBL_EQ(test_pa.data, 31.6);

        const auto test_psi = lambda(Psi(31.6));
        CHECK_DBL_EQ(test_psi.data, 217874.3);
      }

      SUBCASE("Create a pascal from distance, time, and mass") {
        const auto dist = 3.0_m;
        const auto time = 2.0_s;

        const MPerS2 accel = dist / time / time;
        CHECK_DBL_EQ(accel.data, 0.75);

        const Newton force = accel * Kilogram(2);
        CHECK_DBL_EQ(force.data, 1.50);

        const auto area = 3.0_m * 3.0_m;
        const Pascal pres = force / area;
        CHECK_DBL_EQ(pres.data, 0.166667);

        const Pascal pres_lit =
            3.0_m * 2.0_kg / (2.0_s * 2.0_s * 3.0_m * 3.0_m);
        CHECK_DBL_EQ(pres_lit.data, 0.166667);
      }
    }
  }

  // TODO: Density illustrative example
  TEST_CASE("Polished Test Case for Density") {
    SUBCASE("Creating kg/m^3 from base units, KgPerL, and base density") {
      const KgPerM3 test1 =
          Kilogram(53.2) / Meter(3.0) / Meter(3.0) / Meter(3.0);

      const KgPerM3 test2 = KgPerL(24.7);

      const KgPerM3 test3 = Density(32.9);

      CHECK(test1.data == doctest::Approx(1.97037037));
      CHECK(test2.data == doctest::Approx(24700));
      CHECK(test3.data == doctest::Approx(32.9));
    }

    SUBCASE("Creating kg/L from base units, KgPerM3, and base density") {
      const KgPerL test1 = Kilogram(137.98) / Liter(4.7);
      const KgPerL test2 = KgPerM3(345.2);
      const KgPerL test3 = Density(32789.76);

      CHECK(test1.data == doctest::Approx(29.35744681));
      CHECK(test2.data == doctest::Approx(0.3452));
      CHECK(test3.data == doctest::Approx(32.78976));
    }
  }

  // NOLINTBEGIN(readability-identifier-length)
  TEST_CASE("Polished Ideal Gas Law Test") {
    using csm_units::literals::J;
    using csm_units::literals::K;
    using csm_units::literals::m3;
    using csm_units::literals::mol;

    constexpr auto IdealGasLaw = [](Temperature T, Volume V, Amount n, auto R) {
      return n * R * T / V;
    };

    SUBCASE("R - Correct Units") {
      const auto n = 13.0_mol;
      const auto R = 8.31446 <<= J / mol / K;  // 8.3145 J/mol K
      const auto T = 293.15_K;
      const auto V = 30.0 <<= m3;

      const Pascal P = IdealGasLaw(T, V, n, R);
      CHECK_DBL_EQ(P.data, 1056.2);
    }

    SUBCASE("R - Correct Units") {
      const auto n = 13.0_mol;
      const auto R =
          Liter(0.083144626) * Bar(1) / Kelvin(1) / Mole(1);  // 8.3145 J/mol K
      const auto T = 293.15_K;
      const auto V = 30.0 <<= m3;

      const Pascal P = IdealGasLaw(T, V, n, R);
      CHECK_DBL_EQ(P.data, 1056.2);

      const Psi P2 = IdealGasLaw(T, V, n, R);
      CHECK_DBL_EQ(P2.data, 0.153188859);
    }
  }
  // NOLINTEND(readability-identifier-length)
}

// NOLINTEND(modernize-use-trailing-return-type,misc-use-anonymous-namespace)

}  // namespace csm_units::test