#ifndef KLETCH_MATH_PREFIX_H
#define KLETCH_MATH_PREFIX_H

#include <tuple>
#include <iostream>
#include <limits>
#include "special_functions.h"

namespace kletch {

#ifdef KLETCH_USE_DOUBLES
    typedef double real;
#else
    typedef float real;
#endif

template <typename T>
inline constexpr real rl(T number) { return static_cast<real>(number); }

typedef std::numeric_limits<double> double_limits;
typedef std::numeric_limits<float> float_limits;
typedef std::numeric_limits<real> real_limits;

} // namespace kletch

#endif // KLETCH_MATH_PREFIX_H
