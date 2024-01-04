/**  \file psi.hpp
 *   \brief This file is used to define the unit Psi derived from the base
 * dimension for Pressure.
 *
 *   The following wikipedia page can explain <a
 * href="https://en.wikipedia.org/wiki/Psi">Psi</a> if needed.
 */

// TODO: Monolithic units (lbf in this case)

// #pragma once

// #include "../../definition.hpp"
// #include "../../unit.hpp"
// #include "dimension.hpp"

// namespace csm_units {

// namespace definition {

// using PoundForcePerSqInch = Definition<Pressure, std::ratio<393701, 10000>>;

// }

// using PoundForcePerSqInch = Unit<definition::PoundForcePerSqInch>;

// namespace literals {

// constexpr auto in =  // NOLINT(readability-identifier-length)
//     definition::PoundForcePerSqInch();

// constexpr auto operator""_in(long double data) noexcept {
//   return PoundForcePerSqInch(static_cast<PoundForcePerSqInch::type>(data));
// }

// constexpr auto operator""_in(unsigned long long data) noexcept {
//   return PoundForcePerSqInch(static_cast<PoundForcePerSqInch::type>(data));
// }

// }  // namespace literals

// }  // namespace csm_units