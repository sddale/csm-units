/**  \file unit.hpp
 *   \brief This file defines a derived unit of any dimension and any system.
 *
 * The system refers to what standard the data is in. For example, the
 * International System of Units (SI) is a system in this sense. To define a new
 * unit please refer ot the instructions in the \link unitcast.hpp \endlink
 * file.
 */

#pragma once

#include <csm_units/concepts.hpp>
#include <ostream>

#include "unitbase.hpp"
#include "unitcast.hpp"
#include "util.hpp"

namespace csm_units {

template <UnitBaseType Base, StringLiteral Unit_Name, Arithmetic Data>
class Unit {
 public:
  using SI = Base;
  constexpr explicit Unit(Data value = 0.0) noexcept : data(value) {}

  constexpr explicit(false) Unit(SI new_base) noexcept
      : data(UnitCast<Unit>(std::forward<SI>(new_base)).data) {}

  template <StringLiteral UN, Arithmetic D>
  constexpr explicit(false) Unit(Unit<SI, UN, D> new_unit) noexcept
      : data(UnitCast<Unit>(
                 UnitCast<SI>(std::forward<decltype(new_unit)>(new_unit)))
                 .data) {}

  Data data;

  template <UnitType U>
  friend constexpr auto operator<=>(const Unit& lhs, const U& rhs) noexcept {
    return SI(lhs) <=> rhs;
  }

  template <UnitType U>
  friend constexpr auto operator==(const Unit& lhs, const U& rhs) noexcept
      -> bool {
    return SI(lhs) == rhs;
  }

  constexpr auto operator+=(const Base& rhs) noexcept -> auto& {
    auto temp = UnitCast<Base>(std::forward<Unit>(*this));
    temp = temp + rhs;
    data = UnitCast<Unit>(std::forward<Base>(temp)).data;
    return *this;
  }

  constexpr auto operator-=(const Base& rhs) noexcept -> auto& {
    auto temp = UnitCast<Base>(std::forward<Unit>(*this));
    temp = temp - rhs;
    data = UnitCast<Unit>(std::forward<Base>(temp)).data;
    return *this;
  }

  constexpr friend auto operator<<(std::ostream& out, Unit unit)
      -> std::ostream& {
    out << unit.data << ' ' << Unit_Name.value;
    return out;
  }

  friend constexpr auto operator-(Unit lhs) noexcept {
    lhs.data = -1 * lhs.data;
    return lhs;
  }
};

}  // namespace csm_units