#ifndef JOGURT_MATH_SPECIAL_FUNCTIONS_H
#define JOGURT_MATH_SPECIAL_FUNCTIONS_H

#include "prefix.h"

namespace jogurt {

using std::abs;
using std::copysign;
using std::signbit;
using std::cos;
using std::sin;
using std::sqrt;
using std::hypot;
using std::log;
using std::floor;

#undef min
#undef max
#ifndef JOGURT_MSVC
    inline int abs(int x) { return x >= 0 ? x : -x; }
#endif

inline float log(float b, float x) { return log(x) / log(b); }
template <class T> inline T sgn(T x) { return copysign(T(1), x); }
template <class T> inline T sq(T x) { return x * x; }
template <class T> inline T lerp(T v0, T v1, T a) { return (1 - a) * v0 + a * v1; }
template <class T> inline T clamp(T v0, T v1, T v) { return v <= v0 ? v0 : (v1 <= v ? v1 : v); }
template <class T, class S> inline common_t<T, S> min(T const& a, S const& b) { return a<b ? a:b; }
template <class T, class S> inline common_t<T, S> max(T const& a, S const& b) { return a>b ? a:b; }

} // namespace jogurt

#endif // JOGURT_MATH_SPECIAL_FUNCTIONS_H
