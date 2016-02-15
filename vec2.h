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

    typename std::common_type<T, float>::type length() const { return hypot(x, y); }

    template <typename S>
    vec2& operator = (const vec2<S>& v)
    {
        x = v.x; y = v.y;
        return *this;
    }

    void normalize() { operator /= (length()); }

    void normalize_safe()
    {
        normalize();
        if(any_broken())
        {
            x = 1;
            y = 0;
        }
    }

    vec2 normalized()
    {
        vec2 v = *this;
        v.normalize();
        return v;
    }

    vec2 normalized_safe()
    {
        vec2 v = *this;
        v.normalize_safe();
        return v;
    }

    void rotate(T angle)
    {
        auto s = sin(angle);
        auto c = sin(angle);
        T x_bak = x;
        x = c * x_bak - s * y;
        y = s * x_bak + c * y;
    }

    vec2 rotated(T angle) const
    {
        vec2 v = *this;
        v.rotate(angle);
        return v;
    }

    typename std::common_type<T, float>::type angle() const { return atan2(y, x); }

    bool any_nan() { return isnan(x) || isnan(y); }

    bool any_inf() { return isinf(x) || isinf(y); }

    bool any_broken() { return any_nan() || any_inf(); }

    template <typename S>
    bool operator == (const vec2<S>& v) const
    {
        return x == v.x && y == v.y;
    }

    template <typename S>
    bool operator != (const vec2<S>& v) const
    {
        return x != v.x || y != v.y;
    }

    template <typename S>
    vec2& operator += (const vec2<S>& v)
    {
        x += v.x; y += v.y;
        return *this;
    }

    vec2& operator += (T s)
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

    vec2& operator -= (T s)
    {
        x -= s; y -= s;
        return *this;
    }

    vec2& operator *= (T s)
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

template <typename T1, typename T2>
inline typename std::common_type<T1, T2>::type dot(const vec2<T1>& u, const vec2<T2>& v)
{
    return u.x * v.x + u.y * v.y;
}

template <typename T1, typename T2>
inline typename std::common_type<T1, T2>::type per(const vec2<T1>& u, const vec2<T2>& v)
{
    return u.x * v.y - u.y * v.x;
}

} // namespace kletch

#endif // KLETCH_MATH_VEC2_H
