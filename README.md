[![Actions Status](https://github.com/sddale/csm-units/workflows/MacOS/badge.svg)](https://github.com/sddale/csm-units/actions)
[![Actions Status](https://github.com/sddale/csm-units/workflows/Windows/badge.svg)](https://github.com/sddale/csm-units/actions)
[![Actions Status](https://github.com/sddale/csm-units/workflows/Ubuntu/badge.svg)](https://github.com/sddale/csm-units/actions)
[![Actions Status](https://github.com/sddale/csm-units/workflows/Style/badge.svg)](https://github.com/sddale/csm-units/actions)
[![Actions Status](https://github.com/sddale/csm-units/workflows/Install/badge.svg)](https://github.com/sddale/csm-units/actions)
<!-- [![codecov](https://codecov.io/gh/sddale/csm-units/branch/master/graph/badge.svg)](https://codecov.io/gh/sddale/csm-units) -->

<p align="center">
  <img src="https://www.mines.edu/wp-content/uploads/assets/logo_eee_rev_4c_r.png" height="100" width="auto" />
</p>

# csm-units

A C++20 library for descriptive units of measurements as drop-in replacements for fundamental types with minimal overhead.

## Features

- Static inheritance via C++20 concepts
- Implicit unit conversions
- Templated for arithmetic types
- Classes behave like fundamental types

## Example

### Before

```cpp
constexpr auto IdealGas(int n, double V double T) -> double {
  const auto R = 8.314;
  const auto P = n * R * T / V;
  return P;
}

constexpr void UseIG() {
  const int n = 2;
  const auto T = 300.0; // Units?
  const auto V = 10.1; // Units?
  auto pres = IdealGas(n,T,V); // No enforcement of incorrect parameter order
}
```

### After
```cpp
using Units::Mol;
using Units::CubicCm;
using Units::Kelvin;
using Units::Bar;

constexpr auto IdealGas(Mol n, CubicCm V, Kelvin T) -> Bar {
  const auto R = Units::IdealGasConst<Mol, CubicCm, Kelvin, Bar>();
  const Bar P = n * R * T / V;
  return P;
}

constexpr void UseIG() {
  const Mol n = 2;
  const Kelvin T = 300.0;
  const auto V = 10.1_cm3; // string literal operators
  // const auto pres = IdealGas(n,T,V); // Does not compile
  const auto pres = IdealGas(n,V,T);
}
```


### Benchmarking Results

|               ns/op |                op/s |    err% |     total | benchmark
|--------------------:|--------------------:|--------:|----------:|:----------
|                0.54 |    1,867,367,608.26 |    2.7% |      0.32 | `Add doubles`
|                0.52 |    1,923,414,224.98 |    0.4% |      0.32 | `Add csm_units base units`
|                0.52 |    1,915,263,728.78 |    0.5% |      0.32 | `Add csm_units derived units`
|                0.53 |    1,883,753,636.19 |    2.3% |      0.32 | `Subtract doubles`
|                0.53 |    1,895,742,883.89 |    1.6% |      0.32 | `Subtract csm_units base units`
|                0.52 |    1,914,325,480.01 |    1.1% |      0.32 | `Subtract csm_units derived units`
|                0.52 |    1,927,784,843.88 |    0.5% |      0.32 | `Multiply doubles`
|                0.52 |    1,914,542,860.57 |    0.9% |      0.32 | `Multiply csm_units base units`
|                0.52 |    1,924,046,509.83 |    0.5% |      0.31 | `Multiply csm_units derived units`
|                1.04 |      961,168,397.17 |    0.6% |      0.63 | `Divide doubles`
|                1.04 |      962,724,107.07 |    0.2% |      0.62 | `Divide csm_units base units`
|                1.04 |      964,780,415.08 |    0.4% |      0.62 | `Divide csm_units derived units`
