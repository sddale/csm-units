#include <doctest/doctest.h>

#include <csm_units/units.hpp>

namespace csm_units::test {

// NOLINTBEGIN(modernize-use-trailing-return-type)
TEST_SUITE("Temperature") {
  TEST_CASE("Kelvin to Kelvin") {
    SUBCASE("Kelvin Test 0") {
      const auto temperature = Kelvin(34.0);
      CHECK(temperature.data == doctest::Approx(34.0));
      CHECK(KelvinConverter::ToBase(temperature.data) == doctest::Approx(34.0));
    }
    SUBCASE("Kelvin Test 1") {
      const auto temperature = Kelvin(300.4543);
      CHECK(temperature.data == doctest::Approx(300.4543));
      CHECK(KelvinConverter::ToBase(temperature.data) ==
            doctest::Approx(300.4543));
    }
  }

  TEST_CASE("Fahrenheit to Kelvin") {
    SUBCASE("Fahrenheit Test 0") {
      const auto temperature = Fahrenheit(32.0);
      CHECK(temperature.data == doctest::Approx(32.0));
      CHECK(FahrenheitConverter::ToBase(temperature.data) ==
            doctest::Approx(273.15));
    }
    SUBCASE("Fahrenheit Test 1") {
      const auto temperature = Fahrenheit(-32.554);
      CHECK(temperature.data == doctest::Approx(-32.554));
      CHECK(FahrenheitConverter::ToBase(temperature.data) ==
            doctest::Approx(237.28677));
    }
    SUBCASE("Fahrenheit Test 2") {
      const auto temperature = Fahrenheit(150.58483948747);
      CHECK(temperature.data == doctest::Approx(150.58483948747));
      CHECK(FahrenheitConverter::ToBase(temperature.data) ==
            doctest::Approx(339.03044444));
    }
  }

  TEST_CASE("Celsius to Kelvin") {
    SUBCASE("Celsius Test 0") {
      const auto temperature = Celsius(0.0);
      CHECK(temperature.data == doctest::Approx(0.0));
      CHECK(CelsiusConverter::ToBase(temperature.data) ==
            doctest::Approx(273.15));
    }
    SUBCASE("Celsius Test 1") {
      const auto temperature = Celsius(-132.34211111);
      CHECK(temperature.data == doctest::Approx(-132.34211111));
      CHECK(CelsiusConverter::ToBase(temperature.data) ==
            doctest::Approx(140.807889));
    }
    SUBCASE("Celsius Test 2") {
      const auto temperature = Celsius(120.453);
      CHECK(temperature.data == doctest::Approx(120.453));
      CHECK(CelsiusConverter::ToBase(temperature.data) ==
            doctest::Approx(393.603));
    }
  }

  // seems out of place right now
  TEST_CASE("Size") {
    const auto temp = Kelvin(1.0);
    REQUIRE(sizeof(temp) == sizeof(temp.data));  // converter requires 0 bytes
  }

  TEST_SUITE("Operator Overloading Tests") {
    TEST_CASE("Kelvin - Same Unit") {
      const auto temp = Kelvin(273.15);
      const auto sameTemp = Kelvin(273.15);
      const auto lowTemp = Kelvin(88.45);
      const auto highTemp = Kelvin(456.32);

      CHECK(temp > lowTemp);
      CHECK(temp < highTemp);
      CHECK(temp >= lowTemp);
      CHECK(temp <= highTemp);
      CHECK(temp >= sameTemp);
      CHECK(temp <= sameTemp);
      CHECK(temp == sameTemp);
      CHECK(lowTemp < highTemp);
      CHECK(lowTemp <= highTemp);
      CHECK(temp != lowTemp);
      CHECK_FALSE(lowTemp > highTemp);
      CHECK_FALSE(highTemp <= lowTemp);
    }

    TEST_CASE("Fahrenheit - Same Unit") {
      const auto temp = Fahrenheit(66.34);
      const auto sameTemp = Fahrenheit(66.34);
      const auto lowTemp = Fahrenheit(-56.8);
      const auto highTemp = Fahrenheit(127.84);

      CHECK(temp > lowTemp);
      CHECK(temp < highTemp);
      CHECK(temp >= lowTemp);
      CHECK(temp <= highTemp);
      CHECK(temp >= sameTemp);
      CHECK(temp <= sameTemp);
      CHECK(temp == sameTemp);
      CHECK(lowTemp < highTemp);
      CHECK(lowTemp <= highTemp);
      CHECK(temp != highTemp);
      CHECK_FALSE(lowTemp > highTemp);
      CHECK_FALSE(highTemp <= lowTemp);
    }

    TEST_CASE("Celsius - Same Unit") {
      const auto temp = Celsius(0.0);
      const auto sameTemp = Celsius(0.0);
      const auto lowTemp = Celsius(-34.8);
      const auto highTemp = Celsius(94.33);

      CHECK(temp > lowTemp);
      CHECK(temp < highTemp);
      CHECK(temp >= lowTemp);
      CHECK(temp <= highTemp);
      CHECK(temp >= sameTemp);
      CHECK(temp <= sameTemp);
      CHECK(temp == sameTemp);
      CHECK(lowTemp < highTemp);
      CHECK(lowTemp <= highTemp);
      CHECK(highTemp != lowTemp);
      CHECK_FALSE(lowTemp > highTemp);
      CHECK_FALSE(highTemp <= lowTemp);
    }

    TEST_CASE("Different Unit Comparisons") {
      SUBCASE("All Unit Comparison 0") {
        // all these are the same
        const auto tempCelsius = Celsius(0.0);
        const auto tempKelvin = Kelvin(273.15);
        const auto tempFahrenheit = Fahrenheit(32.0);
        CHECK(tempCelsius == tempKelvin);
        CHECK(tempCelsius == tempFahrenheit);
        CHECK(tempKelvin == tempFahrenheit);
        CHECK(tempCelsius >= tempKelvin);
        CHECK(tempCelsius <= tempFahrenheit);
        CHECK(tempKelvin >= tempFahrenheit);
        CHECK_FALSE(tempCelsius < tempKelvin);
        CHECK_FALSE(tempCelsius < tempFahrenheit);
        CHECK_FALSE(tempKelvin > tempFahrenheit);
      }

      SUBCASE("All Unit Comparison 1") {
        // all these are the same
        const auto tempCelsius = Celsius(100.0);
        const auto tempKelvin = Kelvin(373.15);
        const auto tempFahrenheit = Fahrenheit(212.0);

        CHECK(tempCelsius == tempKelvin);
        CHECK(tempCelsius == tempFahrenheit);
        CHECK(tempKelvin == tempFahrenheit);
        CHECK(tempCelsius >= tempKelvin);
        CHECK(tempCelsius <= tempFahrenheit);
        CHECK(tempKelvin >= tempFahrenheit);
        CHECK_FALSE(tempCelsius < tempKelvin);
        CHECK_FALSE(tempCelsius < tempFahrenheit);
        CHECK_FALSE(tempKelvin > tempFahrenheit);
      }

      SUBCASE("All Unit Comparison 2") {
        // all these are the same
        const auto tempCelsius = Celsius(24.0);
        const auto tempKelvin = Kelvin(297.15);
        const auto tempFahrenheit = Fahrenheit(75.2);

        CHECK(tempCelsius == tempKelvin);
        CHECK(tempCelsius == tempFahrenheit);
        CHECK(tempKelvin == tempFahrenheit);
        CHECK(tempCelsius >= tempKelvin);
        CHECK(tempCelsius <= tempFahrenheit);
        CHECK(tempKelvin >= tempFahrenheit);
        CHECK_FALSE(tempCelsius < tempKelvin);
        CHECK_FALSE(tempCelsius < tempFahrenheit);
        CHECK_FALSE(tempKelvin > tempFahrenheit);
      }
    }

    TEST_CASE("Comparisons With Int/Double Types") {
      const auto tempCelsius = Celsius(24.0);
      const auto tempKelvin = Kelvin(297.15);
      const auto tempFahrenheit = Fahrenheit(75.2);

      SUBCASE("Integer Comparisons") {
        int low_num = -50;
        int num = 22;
        int high_num = 80;

        CHECK(tempCelsius < high_num);
        CHECK(tempCelsius >= num);
        CHECK(tempKelvin > high_num);
        CHECK(tempKelvin != low_num);
        CHECK(tempFahrenheit <= high_num);
        CHECK_FALSE(tempFahrenheit == num);
      }

      SUBCASE("Double Comparisons") {
        double low_num = -50.47;
        double num = 22.78;
        double high_num = 80.556;

        CHECK(tempCelsius < high_num);
        CHECK(tempCelsius >= num);
        CHECK(tempKelvin > high_num);
        CHECK(tempKelvin != low_num);
        CHECK(tempFahrenheit <= high_num);
        CHECK_FALSE(tempFahrenheit == high_num);
      }
    }

    TEST_CASE("Assignment Operator Overload") {
      [[maybe_unused]] const auto tempKelvin = Kelvin(273.15);
      [[maybe_unused]] const auto tempKelvin2 =
          tempKelvin;  // this is not working
    }
  }

  TEST_CASE("Copy Constructor") {
    const auto tempKelvin = Kelvin(325.0);
    const auto tempCelsius = Celsius(68.45);
    const auto tempFahrenheit = Fahrenheit(98.45);

    // 1. Kelvin(325) gets constructed
    // 2. Outer Kelvin make a copy
    // 3. Foo gets copy

    // 1. Kelvin(325) is an r-value ("temporary")
    // 2. Outer Kelvin move constructor gets called
    // 3. Move assignment operator

    // recommend: std::vector move semantics
    SUBCASE("Same Unit Copies") {
      // using default copy constructor
      const auto tempKelObject = Kelvin(tempKelvin);
      const auto tempCelObject = Celsius(tempCelsius);
      const auto tempFahObject = Fahrenheit(tempFahrenheit);

      CHECK(tempKelObject.data == doctest::Approx(325.0));
      CHECK(tempCelObject.data == doctest::Approx(68.45));
      CHECK(tempFahObject.data == doctest::Approx(98.45));
      CHECK(FahrenheitConverter::ToBase(tempFahObject.data) ==
            doctest::Approx(310.066));
      CHECK(CelsiusConverter::ToBase(tempCelObject.data) ==
            doctest::Approx(341.6));
      CHECK(KelvinConverter::ToBase(tempKelObject.data) ==
            doctest::Approx(325.0));
      //
    }

    SUBCASE("Different Unit Copies (other copy constructor)") {
      // not sure how to go about this
    }
  }

  // TEST_CASE("Move Constructor") {
  //   auto tempKelvin = Kelvin(325.0);
  //   auto tempCelsius = Celsius(68.45);
  //   auto tempFahrenheit = Fahrenheit(98.45);

  //   SUBCASE("Same Unit Copies") {
  //     // using default copy constructor
  //     const auto tempObject = std::move(tempKelvin);
  //     const auto tempKelObject = Kelvin(std::move(tempKelvin));
  //     const auto tempCelObject = Celsius(tempCelsius);
  //     const auto tempFahObject = Fahrenheit(tempFahrenheit);

  //     CHECK(tempKelObject.data == doctest::Approx(325.0));
  //     CHECK(tempCelObject.data == doctest::Approx(68.45));
  //     CHECK(tempFahObject.data == doctest::Approx(98.45));
  //     CHECK(FahrenheitConverter::ToBase(tempFahObject.data) ==
  //           doctest::Approx(310.066));
  //     CHECK(CelsiusConverter::ToBase(tempCelObject.data) ==
  //           doctest::Approx(341.6));
  //     CHECK(KelvinConverter::ToBase(tempKelObject.data) ==
  //           doctest::Approx(325.0));
  //     //
  //   }

  //   SUBCASE("Different Unit Copies (other copy constructor)") {
  //     // not sure how to go about this
  //   }
  // }
}
// NOLINTEND(modernize-use-trailing-return-type)

}  // namespace csm_units::test