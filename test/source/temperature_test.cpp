#include <doctest/doctest.h>

#include <csm_units/temperature.hpp>

namespace csm_units::test {

TEST_CASE("Temperature") {
    Temperature temperature(78);
    CHECK(temperature.temp == 78);
}

}
