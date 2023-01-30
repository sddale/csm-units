#pragma once

#include "source/csm_units/pressure.hpp"
#include "source/csm_units/temperature.hpp"

namespace csm_units {

// Pressure typedefs
using Pascals = Pressure<PascalsConverter>;
using Bar = Pressure<BarConverter>;
using Atm = Pressure<AtmConverter>;
using Psi = Pressure<PsiConverter>;

// Temperature typedefs
using Kelvin = Temperature<KelvinConverter>;
using Celsius = Temperature<CelsiusConverter>;
using Fahrenheit = Temperature<FahrenheitConverter>;

}