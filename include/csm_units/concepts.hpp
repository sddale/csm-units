#pragma once

#include <concepts>
#include <type_traits>

namespace csm_units {

template <class T>
concept Arithmetic = std::is_arithmetic_v<T>;

}