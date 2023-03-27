#pragma once

#include "source/csm_units/converter.hpp"
#include "source/csm_units/exponents.hpp"
#include "source/csm_units/pressure.hpp"
#include "source/csm_units/temperature.hpp"
#include "source/csm_units/unit.hpp"

namespace csm_units {

// Pressure type
template <class Converter>
using Pressure = Unit<Exponents<-1, 1, 2, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1>,
                      Converters<>, Prefixes<>, double>;

// Pressure units
using Pascals = Pressure<NoConverter>;

// Converter logic must be updated elsewhere before proper non-si pressure
// aliases can be built
using Bar = Pressure<BarConverter>;
using Atm = Pressure<AtmConverter>;
using Psi = Pressure<PsiConverter>;

// Temperature type
// template <ConverterType Converter>
// using Temperature =
//     Unit<Exponents<0, 0, 1>, Converters<Converter>, Prefixes<>, double>;

// Temperature units
// using Kelvin = Temperature<NoConverter>;
// using Celsius = Temperature<CelsiusConverter>;
// using Fahrenheit = Temperature<FahrenheitConverter>;

}  // namespace csm_units