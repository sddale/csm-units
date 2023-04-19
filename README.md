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

|--------------------:|--------------------:|--------:|----------:|:----------
|           29,644.76 |           33,732.77 |    3.7% |      1.88 | `add doubles`
|           40,063.52 |           24,960.37 |    1.8% |      2.50 | `add base units`
|          126,874.72 |            7,881.79 |    2.1% |      7.62 | `add derived units`
|           27,312.42 |           36,613.37 |    1.3% |      1.65 | `subtract doubles`
|           38,710.22 |           25,832.97 |    1.9% |      2.47 | `subtract base units`
|          107,211.46 |            9,327.36 |    1.6% |      6.43 | `subtract derived units`
|           27,410.18 |           36,482.80 |    1.9% |      1.65 | `multiply doubles`
|           49,373.45 |           20,253.80 |    0.5% |      3.00 | `multiply base units`
|          121,449.66 |            8,233.86 |    0.7% |      7.25 | `multiply derived units`
|           27,172.66 |           36,801.69 |    0.8% |      1.63 | `divide doubles`
|           37,040.62 |           26,997.39 |    0.5% |      2.21 | `divide base units`
|          114,213.69 |            8,755.52 |    0.6% |      6.89 | `divide derived units`
