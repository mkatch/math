#ifndef KLETCH_MATH_SPECIAL_FUNCTIONS_H
#define KLETCH_MATH_SPECIAL_FUNCTIONS_H

#include <cmath>

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

} // namespace kletch

#endif // KLETCH_MATH_SPECIAL_FUNCTIONS_H
