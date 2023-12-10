/**  \file concepts.hpp
 *   \brief This file provides the requirements for each type so that we are
 * able to enforce specific classes in templates and function parameters.
 */

#pragma once
#include <concepts>  // IWYU pragma: keep (incorrect warning)
#include <type_traits>

namespace csm_units::concepts {

/**
 * \brief This concept enforces arithmetics.
 */
template <class T>
concept Arithmetic = std::is_arithmetic_v<T>;

/**
 * \brief This concept enforces that a class is a ratio.
 */
template <class T>
concept Ratio = requires {
  { T::num } -> std::convertible_to<int>;
  { T::den } -> std::convertible_to<int>;
};

/**
 * \brief This concept enforces the form of unit dimensions.
 * stated.
 */
template <class T>
concept ExpType = requires {
  { T::L::num } -> std::convertible_to<intmax_t>;
  { T::L::den } -> std::convertible_to<intmax_t>;
  { T::M::num } -> std::convertible_to<intmax_t>;
  { T::M::den } -> std::convertible_to<intmax_t>;
  { T::T::num } -> std::convertible_to<intmax_t>;
  { T::T::den } -> std::convertible_to<intmax_t>;
  { T::C::num } -> std::convertible_to<intmax_t>;
  { T::C::den } -> std::convertible_to<intmax_t>;
  { T::TP::num } -> std::convertible_to<intmax_t>;
  { T::TP::den } -> std::convertible_to<intmax_t>;
  { T::A::num } -> std::convertible_to<intmax_t>;
  { T::A::den } -> std::convertible_to<intmax_t>;
  { T::LM::num } -> std::convertible_to<intmax_t>;
  { T::LM::den } -> std::convertible_to<intmax_t>;
};

/**
 * \brief This concept enforces the form of unit definitions.
 */
template <class D>
concept Definition = requires {
  ExpType<typename D::dim>;
  Ratio<typename D::conv_len()>;
  Ratio<typename D::conv_mass>;
  Ratio<typename D::conv_time>;
  Ratio<typename D::conv_elec>;
  Ratio<typename D::conv_temper>;
  Ratio<typename D::conv_amount>;
  Ratio<typename D::conv_light>;
};

/**
 * \brief This concept enforces the structure of a unit.
 */
template <class T>
concept Unit = requires(T unit) {
  { unit.data } -> std::convertible_to<double>;
  { unit.Get() } -> std::convertible_to<double>;
  Definition<typename T::def>;
};

/**
 * \brief This concept enforces matching dimensions between two Units
 */
template <class T, class U>
concept SameDimAs = requires(T lhs, U rhs) {
  { std::same_as<typename T::def::dim, typename U::def::dim> };
};

}  // namespace csm_units::concepts