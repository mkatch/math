#ifndef KLETCH_MATH_PREFIX_H
#define KLETCH_MATH_PREFIX_H

#include <tuple>
#include <iostream>
#include "special_functions.h"

namespace kletch {

#ifdef KLETCH_USE_DOUBLES
    typedef double real;
#else
    typedef float real;
#endif

template <typename T>
inline constexpr real rl(T number) { return static_cast<real>(number); }

} // namespace kletch

#endif // KLETCH_MATH_PREFIX_H
