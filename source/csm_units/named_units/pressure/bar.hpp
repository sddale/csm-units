/**  \file bar.hpp
 *   \brief This file is used to define the unit Bar derived from the base
 * dimension for Pressure.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Bar_(unit)">Bar</a> if needed.
 */

// TODO: MonolithicUnit

// #pragma once

// #include "../../definition.hpp"
// #include "../../unit.hpp"
// #include "dimension.hpp"

// namespace csm_units {

// namespace definition {

// using Bar = Definition<Pressure, NoConv>;

// }

// using Bar = Unit<definition::Bar>;

// namespace literals {

// constexpr auto bar =  // NOLINT(readability-identifier-length)
//     definition::Bar();

// constexpr auto operator""_bar(long double data) noexcept {
//   return Bar(static_cast<Bar::type>(data));
// }

// constexpr auto operator""_bar(unsigned long long data) noexcept {
//   return Bar(static_cast<Bar::type>(data));
// }

// }  // namespace literals

// }  // namespace csm_units