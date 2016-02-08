#ifndef KLETCH_MATH_VEC2_H
#define KLETCH_MATH_VEC2_H

#include "prefix.h"

namespace kletch {

template <typename T>
struct vec2
{
    static const vec2 ZERO;
    static const vec2 UNIT_X;
    static const vec2 UNIT_Y;

    T x;
    T y;

    vec2(T x, T y) : x(x), y(y) { }

    vec2(T v) : vec2(v, v) { }

    const vec2& operator += (const vec2& v)
    {
        x += v.x; y += v.y;
        return *this;
    }

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

typedef vec2<int> vec2i;
typedef vec2<float> vec2f;
typedef vec2<real> vec2r;

template <typename T>
const vec2<T> vec2<T>::ZERO = vec2<T>(0, 0);

template <typename T>
const vec2<T> vec2<T>::UNIT_X = vec2<T>(1, 0);

template <typename T>
const vec2<T> vec2<T>::UNIT_Y = vec2<T>(0, 1);

template <typename T>
inline vec2<T> operator + (vec2<T> u, const vec2<T>& v) { return u += v; }

template <typename T>
inline vec2<T> operator - (vec2<T> u, const vec2<T>& v) { return u -= v; }

template <typename T>
inline vec2<T> operator / (vec2<T> u, T s) { return u /= s; }

template <typename T>
inline std::ostream& operator << (std::ostream& out, const vec2<T>& v)
{
    return out << '(' << v.x << ", " << v.y << ')';
}

} // namespace kletch

#endif // KLETCH_MATH_VEC2_H
