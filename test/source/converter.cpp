#include <doctest/doctest.h>

#include <csm_units/units.hpp>

#ifndef CSMUNITS_VALUE_TYPE
#define CSMUNITS_VALUE_TYPE double
#endif

namespace csm_units {
namespace converter {
namespace detail {

template <int N, int D, Arithmetic Data = CSMUNITS_VALUE_TYPE>
struct Multiply {
  constexpr static int num = N;
  constexpr static int den = D;
  constexpr static auto Convert(Data data) { return data * N / D; }
};

template <int N, int D, Arithmetic Data = CSMUNITS_VALUE_TYPE>
struct Divide {
  constexpr static int num = N;
  constexpr static int den = D;
  constexpr static auto Convert(Data data) { return data * D / N; }
};

template <int N, int D, Arithmetic Data = CSMUNITS_VALUE_TYPE>
struct Add {
  constexpr static int num = N;
  constexpr static int den = D;
  constexpr static auto Convert(Data data) { return data + Data(N) / D; }
};

template <int N, int D, Arithmetic Data = CSMUNITS_VALUE_TYPE>
struct Subtract {
  constexpr static int num = N;
  constexpr static int den = D;
  constexpr static auto Convert(Data data) { return data - Data(N) / D; }
};

}  // namespace detail

template <class BinOp>
struct Operator : public BinOp {
  constexpr friend auto operator|(Arithmetic auto lhs, Operator /*rhs*/) {
    return BinOp::Convert(lhs);
  }
  constexpr friend auto operator|(Operator /*lhs*/, Arithmetic auto rhs) {
    return BinOp::Convert(rhs);
  }
};

template <int N, int D = 1, Arithmetic Data = CSMUNITS_VALUE_TYPE>
using Multiply = Operator<detail::Multiply<N, D, Data>>;

template <int N, int D = 1, Arithmetic Data = CSMUNITS_VALUE_TYPE>
using Divide = Operator<detail::Divide<N, D, Data>>;

template <int N, int D = 1, Arithmetic Data = CSMUNITS_VALUE_TYPE>
using Add = Operator<detail::Add<N, D, Data>>;

template <int N, int D = 1, Arithmetic Data = CSMUNITS_VALUE_TYPE>
using Subtract = Operator<detail::Subtract<N, D, Data>>;

template <class T>
struct Inverse {};

template <int N, int D, Arithmetic Data>
struct Inverse<Multiply<N, D, Data>> {
  using val = Divide<N, D>;
};

template <int N, int D, Arithmetic Data>
struct Inverse<Divide<N, D, Data>> {
  using val = Multiply<N, D>;
};

template <int N, int D, Arithmetic Data>
struct Inverse<Add<N, D, Data>> {
  using val = Subtract<N, D>;
};

template <int N, int D, Arithmetic Data>
struct Inverse<Subtract<N, D, Data>> {
  using val = Add<N, D>;
};

template <class... Ts>
struct Converter {
  constexpr static auto FromSI(Arithmetic auto data) {
    return (data | ... | Ts());
  }
  constexpr static auto ToSI(Arithmetic auto data) {
    return (typename Inverse<Ts>::val() | ... | data);
  }
};

struct None {
  constexpr auto FromSI(Arithmetic auto data) { return data; }
};

template <class ConvL, class ConvR>
struct Selector {
  using val = ConvL;
};

template <class ConvL>
struct Selector<ConvL, None> {
  using val = ConvL;
};

template <class ConvR>
struct Selector<None, ConvR> {
  using val = ConvR;
};

template <>
struct Selector<None, None> {
  using val = None;
};

using Farenheit = Converter<Subtract<5463, 20>, Multiply<9, 5>, Add<32>>;
}  // namespace converter

namespace definition {

template <class Def, Arithmetic Data = CSMUNITS_VALUE_TYPE>
class Unit {
 public:
  constexpr Unit(double input) : data(input){};
  double data;
};

}  // namespace definition

template <ExpType Exp, class ConvL = converter::None,
          class ConvM = converter::None, class ConvT = converter::None,
          class ConvC = converter::None, class ConvTP = converter::None,
          class ConvA = converter::None, class ConvLM = converter::None>
class Definition {
  using E = Exp;
  using L = ConvL;
  using M = ConvM;
  using T = ConvT;
  using C = ConvC;
  using TP = ConvTP;
  using A = ConvA;
  using LM = ConvLM;

  using Inverse = Definition<ExponentsFlip<E>, ConvL, ConvM, ConvT, ConvC,
                             ConvTP, ConvA, ConvLM>;
  template <class A, class B>
  using Multiply = Definition<
      ExponentsAdd<typename A::E, typename B::E>,
      typename converter::Selector<typename A::L, typename B::L>::val,
      typename converter::Selector<typename A::M, typename B::M>::val,
      typename converter::Selector<typename A::T, typename B::T>::val,
      typename converter::Selector<typename A::C, typename B::C>::val,
      typename converter::Selector<typename A::TP, typename B::TP>::val,
      typename converter::Selector<typename A::A, typename B::A>::val,
      typename converter::Selector<typename A::LM, typename B::LM>::val>;

  template <class A, class B>
  using Divide = Definition<
      ExponentsSubtract<typename A::E, typename B::E>,
      typename converter::Selector<typename A::L, typename B::L>::val,
      typename converter::Selector<typename A::M, typename B::M>::val,
      typename converter::Selector<typename A::T, typename B::T>::val,
      typename converter::Selector<typename A::C, typename B::C>::val,
      typename converter::Selector<typename A::TP, typename B::TP>::val,
      typename converter::Selector<typename A::A, typename B::A>::val,
      typename converter::Selector<typename A::LM, typename B::LM>::val>;

 public:
  constexpr friend auto operator*(Arithmetic auto lhs, Definition /*rhs*/) {
    return definition::Unit<Definition, decltype(lhs)>(lhs);
  }
  template <class D, Arithmetic Data>
  constexpr friend auto operator*(definition::Unit<D, Data> lhs,
                                  Definition /*rhs*/) {
    return definition::Unit<Multiply<D, Definition>, Data>(lhs.data);
  }
  constexpr friend auto operator/(Arithmetic auto lhs, Definition /*rhs*/) {
    return definition::Unit<Inverse, decltype(lhs)>(lhs);
  }
  template <class D, Arithmetic Data>
  constexpr friend auto operator/(definition::Unit<D, Data> lhs,
                                  Definition /*rhs*/) {
    return definition::Unit<Divide<D, Definition>, Data>(lhs.data);
  }

  // TODO: return nondimnensional type when needed i.e. K / K
};

namespace definition {
using Farenheit =
    Definition<Exponents<0, 0, 0, 0, 1, 0, 0>, converter::None, converter::None,
               converter::None, converter::None, converter::Farenheit>;
using SquareFarenheit =
    Definition<Exponents<0, 0, 0, 0, 2, 0, 0>, converter::None, converter::None,
               converter::None, converter::None, converter::Farenheit>;
}  // namespace definition

// NOLINTBEGIN(readability-identifier-length)
constexpr auto F = definition::Farenheit();
// NOLINTEND(readability-identifier-length)

using Farenheit = definition::Unit<definition::Farenheit, double>;

}  // namespace csm_units

namespace csm_units::test {

// NOLINTBEGIN(modernize-use-trailing-return-type, misc-use-anonymous-namespace)

TEST_SUITE("Conversion Operators") {
  TEST_CASE("Multiply") {
    CHECK(converter::Multiply<3, 1>::Convert(5.5) == 16.5);
    CHECK(converter::Multiply<3, 5>::Convert(5) == 3);
  }

  TEST_CASE("Converter") {
    CHECK(converter::Farenheit::FromSI(300.0) == doctest::Approx(80.33));
    CHECK(converter::Farenheit::ToSI(300.0) == doctest::Approx(422.039));
  }

  TEST_CASE("Definition") {
    static_assert(
        std::is_same_v<definition::Unit<definition::Farenheit, double>,
                       decltype(1.0 * F)>);
    static_assert(
        std::is_same_v<definition::Unit<definition::SquareFarenheit, double>,
                       decltype(1.0 * F * F)>);
    static_assert(
        std::is_same_v<definition::Unit<definition::SquareFarenheit, double>,
                       decltype(Farenheit(1.0) * F)>);
  }
}

// NOLINTEND(modernize-use-trailing-return-type, misc-use-anonymous-namespace)

}  // namespace csm_units::test