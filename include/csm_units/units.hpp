#pragma once

#include "source/csm_units/Converter.hpp"
#include "source/csm_units/derived.hpp"
#include "source/csm_units/pressure.hpp"
#include "source/csm_units/temperature.hpp"

namespace csm_units {

// Pressure typedefs
template <class Converter>
using Pressure = Base<DimPressure, Converter>;
// Once we get derived working with more than just the 3 we can change the above

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