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
  { T::num } -> std::convertible_to<int>;
  { T::den } -> std::convertible_to<int>;
};

/**
 * \brief This concept enforces that a class is a scientific number.
 */
template <class T>
concept IsSciNo = requires(T input) {
  { typename std::remove_reference_t<T>::MagType() } -> IsRatio;
  { input.ord } -> std::convertible_to<int>;
};

/**
 * \brief This concept enforces that a class is a conversion factor type, that
 * is a SciNo or std::ratio.
 */
template <class T>
concept IsConversion = IsRatio<T> or IsSciNo<T>;

/**
 * \brief This concept enforces the form of unit dimensions.
 * stated.
 */
template <class T>
concept IsDimension = requires {
  { T::L::num } -> std::convertible_to<int>;
  { T::L::den } -> std::convertible_to<int>;
  { T::M::num } -> std::convertible_to<int>;
  { T::M::den } -> std::convertible_to<int>;
  { T::T::num } -> std::convertible_to<int>;
  { T::T::den } -> std::convertible_to<int>;
  { T::C::num } -> std::convertible_to<int>;
  { T::C::den } -> std::convertible_to<int>;
  { T::TP::num } -> std::convertible_to<int>;
  { T::TP::den } -> std::convertible_to<int>;
  { T::A::num } -> std::convertible_to<int>;
  { T::A::den } -> std::convertible_to<int>;
  { T::LM::num } -> std::convertible_to<int>;
  { T::LM::den } -> std::convertible_to<int>;
};

/**
 * \brief This concept enforces the form of unit definitions.
 */
template <class D>
concept IsDefinition = requires {
  { typename std::remove_reference_t<D>::DimenType() } -> IsDimension;
  { typename std::remove_reference_t<D>::ConvType() } -> IsConversion;
  { typename std::remove_reference_t<D>::OriginType() } -> IsConversion;
};

/**
 * \brief This concept enforces the structure of a unit.
 */
template <class T>
concept IsUnit = requires(T unit) {
  { unit.data } -> std::convertible_to<double>;
  { unit.Get() } -> std::convertible_to<double>;
  { typename std::remove_reference_t<T>::ValueType() } -> IsArithmetic;
  { typename std::remove_reference_t<T>::DefType() } -> IsDefinition;
};

/**
 * \brief This concept enforces matching dimensions between two Units
 */
template <class T, class U>
concept SameDimensionAs = requires(T lhs, U rhs) {
  { lhs } -> IsUnit;
  { rhs } -> IsUnit;
  {
    typename std::remove_reference_t<T>::DimenType()
  } -> std::same_as<typename std::remove_reference_t<U>::DimenType>;
};

}  // namespace csm_units