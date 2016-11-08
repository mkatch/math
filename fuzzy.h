#ifndef KLETCH_MATH_FUZZY_H
#define KLETCH_MATH_FUZZY_H
#define KLETCH_MATH_FUZZY_H_INSIDE

namespace kletch {

template <class T> inline bool equal_sametype(T a, T b, T eps)
{
    return abs(a - b) <= eps * (T(0.5) * abs(a + b) + T(1));
}

template <class T1, class T2> inline bool equal(T1 a, T2 b, common_t<T1, T2> eps)
{
    return equal_sametype<common_t<T1, T2>>(a, b, eps);
}

} // namespace kletch

#ifdef KLETCH_MATH_VEC2_H
#   include "fuzzy_vec2.h"
#endif

#undef KLETCH_MATH_FUZZY_H_INSIDE
#endif // KLETCH_MATH_FUZZY_H
