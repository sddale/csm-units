#pragma once

// #include "unitbase.hpp"

namespace csm_units {

template <size_t N>
struct StringLiteral {
  constexpr StringLiteral(const char (&str)[N]) { std::copy_n(str, N, value); }

  char value[N];
};

}  // namespace csm_units