#pragma once

#include "source/csm_units/Converter.hpp"
#include "source/csm_units/derived.hpp"
#include "source/csm_units/pressure.hpp"
#include "source/csm_units/temperature.hpp"

namespace csm_units {

// Pressure typedefs
template <class Converter>  // not sure how to handle this
using Pressure = Base<DimPressure, Converter>;
// template <class Converter>  // not sure how to handle this
// using Pressure =
//     Derived<Base<DimLength, Converter>, -1, Base<DimMass, Converter>, 1,
//             Base<DimTime, Converter>, -2>;

// Pressure typedefs
using Pascals = Pressure<NoConverter>;
using Bar = Pressure<BarConverter>;
using Atm = Pressure<AtmConverter>;
using Psi = Pressure<PsiConverter>;

// Temperature typedefs
template <class Converter>
using Temperature = Base<DimTemperature, Converter>;
using Kelvin = Temperature<NoConverter>;
using Celsius = Temperature<CelsiusConverter>;
using Fahrenheit = Temperature<FahrenheitConverter>;

}  // namespace csm_units