#ifndef JOGURT_MATH_PREFIX_H
#define JOGURT_MATH_PREFIX_H

#include "prefix.h"
#include <cmath>
#include <limits>
#include <type_traits>

namespace jogurt {

using std::isnan;
using std::isinf;
using std::isnormal;

#ifdef JOGURT_WITH_DOUBLE
    typedef double real;
#else
    typedef float real;
#endif

template <class T> inline constexpr real rl(T x) { return static_cast<real>(x); }
template <class Tf, class Td> inline constexpr real rl(Tf xf, Td xd)
{
#   ifdef JOGURT_WITH_DOUBLE
        return rl(xd);
#   else
        return rl(xf);
#   endif
}

using std::swap;

template <class T> inline bool isbroken(T x) { return !isnormal(x); }

template <class... Ts>
using common_t = typename std::common_type<Ts...>::type;

template <class T> using limits = std::numeric_limits<T>;
template <class T> inline constexpr T nan() { return limits<T>::quiet_NaN(); }
template <class T> inline constexpr T inf() { return limits<T>::infinity(); }
template <class T> inline constexpr
T pi() { return static_cast<T>(3.141592653589793238462643383); }
template <class T> inline constexpr
T half_pi() { return static_cast<T>(1.570796326794896619231321691); }

} // namespace jogurt

#endif // JOGURT_MATH_PREFIX_H
