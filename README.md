[![MacOS](https://github.com/sddale/csm-units/actions/workflows/macos.yml/badge.svg)](https://github.com/sddale/csm-units/actions/workflows/macos.yml)
[![Windows](https://github.com/sddale/csm-units/actions/workflows/windows.yml/badge.svg)](https://github.com/sddale/csm-units/actions/workflows/windows.yml)
[![Ubuntu](https://github.com/sddale/csm-units/actions/workflows/ubuntu.yml/badge.svg)](https://github.com/sddale/csm-units/actions/workflows/ubuntu.yml)
[![Style](https://github.com/sddale/csm-units/actions/workflows/style.yml/badge.svg)](https://github.com/sddale/csm-units/actions/workflows/style.yml)
[![Install](https://github.com/sddale/csm-units/actions/workflows/install.yml/badge.svg)](https://github.com/sddale/csm-units/actions/workflows/install.yml)

<p align="center">
  <img src="https://www.mines.edu/wp-content/uploads/assets/logo_eee_rev_4c_r.png" height="100" width="auto" />
</p>

# csm-units

A C++20/23 library for descriptive units of measurements as drop-in replacements for fundamental types with minimal overhead.

## Features

- Implicit unit conversions
- Build any unit of arbitrary dimension
- Templated for arithmetic types
- Classes behave like fundamental types
- No memory overhead
- No performance overhead with `constexpr`

## Example

### Before

- Nondescript, error-prone

```cpp
constexpr auto IdealGas(int n, double V, double T) {
  const auto R = 8.3145; // Units?
  const auto P = n * R * T / V;
  return P;
}

constexpr auto UseIG() {
  const auto T = 300.0; // Units?
  const auto V = 10.1; // Units?
  return IdealGas(2, T, V); // No enforcement of incorrect parameter order
}
```

### After

- Self-documents, implicit unit correction

```cpp
#include <csm_units/units.hpp>

using namespace csm_units;
using namespace csm_units::literals;

constexpr auto IdealGas(Kilomole n, Unit<L> volume, Unit<degF> temperature) {
  const auto R = 8.3145 * m3 * Pa / (K * mol);

  const Bar P = n * R * temperature / volume;  // implicit conversion
  return P;
};

constexpr auto UseIG() {
  return IdealGas(2_mol, 10.1_m3,
                  100.0_degC);  // implicit parameter conversions
};
```


### Benchmarking Results

|               ns/op | benchmark
|--------------------:|:----------
|                0.54 | `Add doubles`
|                0.52 | `Add csm_units`
|                0.53 | `Subtract doubles`
|                0.53 | `Subtract csm_units`
|                0.52 | `Multiply doubles`
|                0.52 | `Multiply csm_units`
|                1.04 | `Divide doubles`
|                1.04 | `Divide csm_units`

