#ifndef KLETCH_MATH_SPECIAL_FUNCTIONS_H
#define KLETCH_MATH_SPECIAL_FUNCTIONS_H

#include <cmath>
#include <type_traits>

namespace kletch {

using std::isnan;
using std::isinf;

using std::abs;
using std::copysign;
using std::cos;
using std::sin;
using std::sqrt;
using std::hypot;

template <typename T>
inline T sq(T x)
{
    return x * x;
}

template <typename T>
inline T lerp(T val0, T val1, T alpha)
{
    return (static_cast<T>(1) - alpha) * val0 + alpha * val1;
}

template <typename T, typename S>
inline typename std::common_type<T, S>::type min(const T& a, const S& b)
{
    return a < b ? a : b;
}

template <typename T, typename S>
inline typename std::common_type<T, S>::type max(const T& a, const S& b)
{
    return a > b ? a : b;
}

} // namespace kletch

#endif // KLETCH_MATH_SPECIAL_FUNCTIONS_H
