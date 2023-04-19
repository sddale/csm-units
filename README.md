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
|           27,952.91 |           35,774.45 |    3.0% |      1.72 | `add doubles`
|           40,300.55 |           24,813.56 |    0.6% |      2.42 | `add base units`
|          121,969.87 |            8,198.75 |    1.0% |      7.32 | `add derived units`
|           26,740.07 |           37,397.06 |    0.5% |      1.61 | `subtract doubles`
|           38,402.03 |           26,040.29 |    1.5% |      2.33 | `subtract base units`
|          104,437.66 |            9,575.09 |    0.4% |      6.31 | `subtract derived units`
|           26,739.71 |           37,397.56 |    0.4% |      1.63 | `multiply doubles`
|           49,031.65 |           20,394.99 |    0.9% |      2.95 | `multiply base units`
|          121,122.91 |            8,256.08 |    1.1% |      7.25 | `multiply derived units`
|           27,327.16 |           36,593.63 |    0.9% |      1.67 | `divide doubles`
|           36,950.23 |           27,063.43 |    0.7% |      2.25 | `divide base units`
|          116,889.74 |            8,555.07 |    2.7% |      7.15 | `divide derived units`
