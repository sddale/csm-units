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


###Benchmarking Results

|               ns/op |                op/s |    err% |     total | benchmark
|--------------------:|--------------------:|--------:|----------:|:----------
|           28,164.14 |           35,506.14 |    1.9% |      1.74 | `add doubles`
|           40,769.63 |           24,528.06 |    1.0% |      2.53 | `add base length units`
|           40,521.54 |           24,678.23 |    0.8% |      2.45 | `add base mass units`
|           40,968.73 |           24,408.86 |    2.0% |      2.47 | `add base time units`
|           39,798.97 |           25,126.28 |    0.7% |      2.40 | `add base current units`
|           39,709.83 |           25,182.68 |    0.4% |      2.38 | `add base temperature units`
|           39,500.88 |           25,315.89 |    0.6% |      2.37 | `add base amount units`
|           39,840.65 |           25,099.99 |    0.8% |      2.40 | `add base luminosity units`
|          106,848.94 |            9,359.01 |    0.7% |      6.40 | `add derived units`
|           27,005.49 |           37,029.51 |    0.7% |      1.61 | `subtract doubles`
|           38,288.10 |           26,117.77 |    0.7% |      2.30 | `subtract base length units`
|           38,011.47 |           26,307.85 |    0.4% |      2.29 | `subtract base mass units`
|           38,331.91 |           26,087.92 |    0.9% |      2.29 | `subtract base time units`
|           38,149.99 |           26,212.33 |    0.4% |      2.32 | `subtract base current units`
|           39,053.80 |           25,605.70 |    2.5% |      2.35 | `subtract base temperature units`
|           38,185.86 |           26,187.70 |    0.3% |      2.28 | `subtract base amount units`
|           38,506.68 |           25,969.52 |    1.4% |      2.33 | `subtract base luminosity units`
|          104,654.86 |            9,555.22 |    0.6% |      6.25 | `subtract derived units`
|           27,110.53 |           36,886.03 |    1.3% |      1.62 | `multiply doubles`
|           49,536.82 |           20,187.00 |    0.6% |      2.96 | `multiply base length units`
|           48,996.50 |           20,409.62 |    0.9% |      2.93 | `multiply base mass units`
|           49,362.96 |           20,258.10 |    0.7% |      2.95 | `multiply base time units`
|           49,285.34 |           20,290.01 |    1.6% |      3.00 | `multiply base current units`
|           49,665.99 |           20,134.50 |    0.9% |      2.99 | `multiply base amount units`
|           49,311.65 |           20,279.18 |    0.8% |      3.00 | `multiply base luminosity units`
|          120,651.88 |            8,288.31 |    0.7% |      7.21 | `multiply derived units`
|           26,955.15 |           37,098.67 |    0.4% |      1.62 | `divide doubles`
|           36,341.46 |           27,516.78 |    1.0% |      2.21 | `divide base length units`
|           36,614.77 |           27,311.38 |    0.5% |      2.20 | `divide base mass units`
|           36,887.65 |           27,109.35 |    0.5% |      2.21 | `divide base time units`
|           36,105.63 |           27,696.51 |    0.4% |      2.17 | `divide base current units`
|           36,319.82 |           27,533.18 |    0.7% |      2.18 | `divide base amount units`
|           36,315.46 |           27,536.49 |    0.4% |      2.18 | `divide base luminosity units`
|          114,583.26 |            8,727.28 |    0.8% |      6.85 | `divide derived units`
