#pragma once

#include <compare>
#include <csm_units/concepts.hpp>
#include <ratio>
#include <type_traits>

#include "Converter.hpp"

namespace csm_units {

template <class Dimension, class Converter = NoConverter,
          class Ratio = std::ratio<1, 1>, Arithmetic Data = double>
class Base {
  template <class T>
  using OtherBase = Base<Dimension, T, Data>;

 public:
  constexpr explicit Base(double value) noexcept : data(value) {}

  // copy constructor for units of the same dimensions and converter
  constexpr Base(const Base& other) noexcept = default;

  // copy constructor for units of the same dimension and different converter
  template <class T>
  constexpr Base(const OtherBase<T>& other) noexcept
      : data(Converter::FromBase(T::ToBase(other.data))) {}

  template <class T>
  constexpr auto operator=(const Base<Dimension, T, Data>& other) noexcept
      -> Base& {
    if (this == &other) {
      return *this;
    }
    if constexpr (std::is_same_v<Converter, T>) {
      data = other.data;
    } else {
      data = Converter::FromBase(T::ToBase(other.data));
    }
    return *this;
  }

  // Comparison operator overloads
  constexpr auto operator<=>(Arithmetic auto rhs) const noexcept {
    return data <=> rhs;
  }

  template <class T, class R>
  constexpr auto operator<=>(
      const Base<Dimension, T, R, Data>& rhs) const noexcept {
    if constexpr (std::is_same_v<Converter, T>) {
      return data <=> rhs.data;
    } else {
      return Converter::ToBase(data) <=> T::ToBase(rhs.data);
    }
  }

  constexpr auto operator==(Arithmetic auto rhs) const noexcept -> bool {
    return data == rhs;
  }

  template <class T>
  constexpr auto operator==(const OtherBase<T>& rhs) const noexcept {
    if constexpr (std::is_same_v<Converter, T>) {
      return data == rhs.data;
    } else {
      return Converter::ToBase(data) == T::ToBase(rhs.data);
    }
  }

  Data data;
};

}  // namespace csm_units
