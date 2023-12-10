/**  \file concepts.hpp
 *   \brief This file provides the requirements for each type so that we are
 * able to enforce specific classes in templates and function parameters.
 */

#pragma once
#include <concepts>  // IWYU pragma: keep (incorrect warning)
#include <type_traits>

namespace csm_units {

/**
 * \brief This concept enforces arithmetics.
 */
template <class T>
concept IsArithmetic = std::is_arithmetic_v<T>;

/**
 * \brief This concept enforces that a class is a ratio.
 */
template <class T>
concept IsRatio = requires {
  { T::num } -> std::convertible_to<intmax_t>;
  { T::den } -> std::convertible_to<intmax_t>;
};

/**
 * \brief This concept enforces the form of unit dimensions.
 * stated.
 */
template <class T>
concept IsDimension = requires {
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
concept IsDefinition = requires {
  IsDimension<typename D::dim>;
  IsRatio<typename D::conv_len>;
  IsRatio<typename D::conv_mass>;
  IsRatio<typename D::conv_time>;
  IsRatio<typename D::conv_elec>;
  IsRatio<typename D::conv_temper>;
  IsRatio<typename D::conv_amount>;
  IsRatio<typename D::conv_light>;
};

/**
 * \brief This concept enforces the structure of a unit.
 */
template <class T>
concept IsUnit = requires(T unit) {
  { unit.data } -> std::convertible_to<double>;
  { unit.Get() } -> std::convertible_to<double>;
  IsDefinition<typename T::def>;
  IsRatio<typename T::zero_point>;
  IsArithmetic<typename T::type>;
};

/**
 * \brief This concept enforces matching dimensions between two Units
 */
template <class T, class U>
concept SameDimensionAs = requires(T lhs, U rhs) {
  { std::same_as<typename T::def::dim, typename U::def::dim> };
  IsUnit<T>;
  IsUnit<U>;
};

}  // namespace csm_units