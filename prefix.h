#ifndef KLETCH_MATH_PREFIX_H
#define KLETCH_MATH_PREFIX_H

#include <utility>
#include <tuple>
#include <iostream>
#include <limits>
#include <type_traits>

namespace kletch {

#ifdef KLETCH_WITH_DOUBLE
    typedef double real;
#else
    typedef float real;
#endif

template <typename T>
inline constexpr real rl(T number) { return static_cast<real>(number); }

using std::swap;

typedef std::numeric_limits<double> double_limits;
typedef std::numeric_limits<float> float_limits;
typedef std::numeric_limits<real> real_limits;

template <class... Ts>
using common_t = typename std::common_type<Ts...>::type;

} // namespace kletch

#endif // KLETCH_MATH_PREFIX_H
