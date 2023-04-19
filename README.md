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
using Units::Kelving;
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
|           28,602.83 |           34,961.58 |    4.2% |      1.81 | `add doubles`
|           40,414.22 |           24,743.77 |    1.8% |      2.41 | `add base length units`
|           39,873.02 |           25,079.61 |    1.5% |      2.39 | `add base mass units`
|           40,640.12 |           24,606.23 |    3.0% |      2.47 | `add base time units`
|           40,524.00 |           24,676.73 |    2.1% |      2.45 | `add base current units`
|           40,319.18 |           24,802.09 |    2.0% |      2.44 | `add base temperature units`
|           39,768.39 |           25,145.60 |    1.3% |      2.43 | `add base amount units`
|           39,584.90 |           25,262.16 |    0.6% |      2.37 | `add base luminosity units`
|           26,902.46 |           37,171.32 |    0.6% |      1.62 | `subtract doubles`
|           38,476.81 |           25,989.68 |    0.9% |      2.30 | `subtract base length units`
|           38,811.93 |           25,765.27 |    1.6% |      2.35 | `subtract base mass units`
|           38,300.49 |           26,109.33 |    1.1% |      2.30 | `subtract base time units`
|           38,596.69 |           25,908.96 |    0.6% |      2.31 | `subtract base current units`
|           38,479.63 |           25,987.77 |    0.5% |      2.29 | `subtract base temperature units`
|           39,114.89 |           25,565.71 |    2.1% |      2.34 | `subtract base amount units`
|           38,966.12 |           25,663.32 |    1.8% |      2.33 | `subtract base luminosity units`
|           27,150.50 |           36,831.74 |    0.4% |      1.66 | `multiply doubles`
|           49,145.82 |           20,347.61 |    0.9% |      2.95 | `multiply base length units`
|           49,173.60 |           20,336.11 |    0.6% |      2.97 | `multiply base mass units`
|           49,505.15 |           20,199.92 |    0.5% |      2.96 | `multiply base time units`
|           48,973.42 |           20,419.24 |    1.3% |      2.94 | `multiply base current units`
|           50,684.25 |           19,730.00 |    3.0% |      3.09 | `multiply base amount units`
|           49,247.60 |           20,305.56 |    0.7% |      2.94 | `multiply base luminosity units`
|           27,051.47 |           36,966.57 |    0.7% |      1.62 | `divide doubles`
|           36,959.18 |           27,056.88 |    0.6% |      2.22 | `divide base length units`
|           36,266.60 |           27,573.58 |    0.8% |      2.19 | `divide base mass units`
|           36,149.63 |           27,662.80 |    0.8% |      2.17 | `divide base time units`
|           36,319.22 |           27,533.63 |    1.3% |      2.18 | `divide base current units`
|           36,908.14 |           27,094.29 |    0.7% |      2.20 | `divide base amount units`
|           36,608.08 |           27,316.38 |    1.0% |      2.19 | `divide base luminosity units`
|          121,110.32 |            8,256.93 |    0.5% |      7.24 | `add derived meter units`
|          121,175.09 |            8,252.52 |    0.6% |      7.28 | `add derived kilogram units`
|          120,865.72 |            8,273.64 |    1.3% |      7.23 | `add derived second units`
|          121,289.94 |            8,244.71 |    0.7% |      7.33 | `add derived ampere units`
|          136,291.04 |            7,337.24 |    0.6% |      8.15 | `add derived fahrenheit units`
|          124,396.18 |            8,038.83 |    0.9% |      7.42 | `add derived kilomole units`
