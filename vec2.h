#ifndef KLETCH_MATH_VEC2_H
#define KLETCH_MATH_VEC2_H

#include "prefix.h"
#include <type_traits>

namespace kletch {

template <typename T>
struct vec2
{
    static const vec2 ZERO;
    static const vec2 UNIT_X;
    static const vec2 UNIT_Y;

    T x;
    T y;

    vec2() { }

    template <typename X, typename Y>
    vec2(X x, Y y) : x(x), y(y) { }

    template <typename S>
    vec2(S value) : vec2(value, value) { }

    template <typename S>
    vec2(const vec2<S>& v) : vec2(v.x, v.y) { }

    T length_sq() const { return x * x + y * y; }

    std::common_type<T, float> length() const
    {
        return sqrt(static_cast<std::common_type<T, float>>(length_sq()));
    }

    template <typename S>
    vec2& operator += (const vec2<S>& v)
    {
        x += v.x; y += v.y;
        return *this;
    }

    template <typename S>
    vec2& operator += (S s)
    {
        x += s; y += s;
        return *this;
    }

    template <typename S>
    vec2& operator -= (const vec2<S>& v)
    {
        x -= v.x; y -= v.y;
        return *this;
    }

    template <typename S>
    vec2& operator -= (S s)
    {
        x -= s; y -= s;
        return *this;
    }

    template <typename S>
    vec2& operator *= (S s)
    {
        x *= s; y *= s;
        return *this;
    }

    template <typename S>
    vec2& operator *= (const vec2<S>& v)
    {
        x *= v.x; y *= v.y;
        return *this;
    }

    template <typename S>
    vec2& operator /= (const vec2<S>& v)
    {
        x /= v.x, y /= v.y;
        return *this;
    }

    vec2& operator /= (T s)
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

template <typename T1, typename T2>
inline vec2<typename std::common_type<T1, T2>::type> operator + (
    const vec2<T1>& u,
    const vec2<T2>& v
)
{
    vec2<typename std::common_type<T1, T2>::type> c = u;
    return c += v;
}

template <typename T1, typename T2>
inline vec2<typename std::common_type<T1, T2>::type> operator + (const vec2<T1>& u, T2 s)
{
    vec2<typename std::common_type<T1, T2>::type> c = u;
    return c += s;
}

template <typename T1, typename T2>
inline vec2<typename std::common_type<T1, T2>::type> operator + (T1 s, const vec2<T2>& u)
{
    vec2<typename std::common_type<T1, T2>::type> c = u;
    return c += s;
}

template <typename T1, typename T2>
inline vec2<typename std::common_type<T1, T2>::type> operator - (
    const vec2<T1>& u,
    const vec2<T2>& v
)
{
    vec2<typename std::common_type<T1, T2>::type> c = u;
    return c -= v;
}

template <typename T1, typename T2>
inline vec2<typename std::common_type<T1, T2>::type> operator - (const vec2<T1>& u, T2 s)
{
    vec2<typename std::common_type<T1, T2>::type> c = u;
    return c -= s;
}

template <typename T1, typename T2>
inline vec2<typename std::common_type<T1, T2>::type> operator - (T1 s, const vec2<T2>& u)
{
    vec2<typename std::common_type<T1, T2>::type> c = s;
    return c -= u;
}

template <typename T1, typename T2>
inline vec2<typename std::common_type<T1, T2>::type> operator * (const vec2<T1>& u, T2 s)
{
    vec2<typename std::common_type<T1, T2>::type> c = u;
    return c *= s;
}

template <typename T1, typename T2>
inline vec2<typename std::common_type<T1, T2>::type> operator * (T1 s, const vec2<T2>& u)
{
    vec2<typename std::common_type<T1, T2>::type> c = u;
    return c *= s;
}

template <typename T1, typename T2>
inline vec2<typename std::common_type<T1, T2>::type> operator * (
    const vec2<T1>& u,
    const vec2<T2>& v
)
{
    vec2<typename std::common_type<T1, T2>::type> c = u;
    return c *= v;
}

template <typename T1, typename T2>
inline vec2<typename std::common_type<T1, T2>::type> operator / (const vec2<T1>& u, T2 s)
{
    vec2<typename std::common_type<T1, T2>::type> c = u;
    return c /= s;
}

template <typename T1, typename T2>
inline vec2<typename std::common_type<T1, T2>::type> operator / (T1 s, const vec2<T2>& u)
{
    vec2<typename std::common_type<T1, T2>::type> c = s;
    return c /= u;
}

template <typename T1, typename T2>
inline vec2<typename std::common_type<T1, T2>::type> operator / (
    const vec2<T1>& u,
    const vec2<T2>& v
)
{
    vec2<typename std::common_type<T1, T2>::type> c = u;
    return c /= v;
}

template <typename T>
inline std::ostream& operator << (std::ostream& out, const vec2<T>& v)
{
    return out << '(' << v.x << ", " << v.y << ')';
}

} // namespace kletch

#endif // KLETCH_MATH_VEC2_H
