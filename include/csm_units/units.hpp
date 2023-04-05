#pragma once

// #include "source/csm_units/converter.hpp"
#include "source/csm_units/exponents.hpp"
#include "source/csm_units/pressure.hpp"
#include "source/csm_units/temperature.hpp"
#include "source/csm_units/unit.hpp"
#include "source/csm_units/unitbase.hpp"

namespace csm_units {

// Pressure type
// using Pressure =
//     UnitBase<Exponents<-1, 1, 2, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1>, double>;

// // Pressure units
// using Pascals = Unit<Pressure, "pascals", double>;

// Converter logic must be updated elsewhere before proper non-si pressure
// aliases can be built
// using Psi = Unit<Pressure, "psi", double>;

// // Temperature type
// template <class Converter>
// using Temperature =
//     UnitBase<Exponents<0, 0, 1, 0, 0, 0, 0>,
//          Converters<NoConverter, NoConverter, Converter>, Prefixes<>,
//          double>;

// // Temperature units
// using Celsius = Temperature<CelsiusConverter>;
// using Fahrenheit = Temperature<FahrenheitConverter>;

}  // namespace csm_units