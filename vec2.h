#ifndef KLETCH_MATH_VEC2_H
#define KLETCH_MATH_VEC2_H

#include "prefix.h"

namespace kletch {

template <typename T>
struct vec2
{
    T x;
    T y;

    vec2(T x, T y) : x(x), y(y) { }

    const vec2& operator -= (const vec2& v)
    {
        x -= v.x; y -= v.y;
        return *this;
    }

    const vec2& operator /= (T s)
    {
        x /= s; y /= s;
        return *this;
    }

    template<typename S>
    explicit operator vec2<S> () const { return vec2<S>(static_cast<S>(x), static_cast<S>(y)); }
};

typedef vec2<float> vec2f;
typedef vec2<real> vec2r;

template <typename T>
inline vec2<T> operator - (vec2<T> u, const vec2<T>& v) { return u -= v; }

template <typename T>
inline vec2<T> operator / (vec2<T> u, T s) { return u /= s; }

} // namespace kletch

#endif // KLETCH_MATH_VEC2_H
