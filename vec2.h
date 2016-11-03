#ifndef KLETCH_MATH_VEC2_H
#define KLETCH_MATH_VEC2_H

#include "prefix.h"
#include "special_functions.h"

namespace kletch {

template <class T>
struct vec2
{
    typedef T scalar_t;
    typedef common_t<T, float> float_t;
    static constexpr int COMPONENT_COUNT = 2;

    T x;
    T y;

    vec2() = default;
    constexpr vec2(T x, T y) : x(x), y(y) { }
    constexpr vec2(T value) : x(value), y(value) { }
    constexpr vec2(vec2 const& v) : x(v.x), y(v.y) { }
    constexpr vec2(vec2 const& u, vec2 const& v) : x(v.x - u.x), y(v.y - u.y) { }

    vec2& operator = (vec2 const& v) { x = v.x; y = v.y; return *this; }
    vec2& operator += (vec2 const& v) { x += v.x; y += v.y; return *this; }
    vec2& operator += (T s) { x += s; y += s; return *this; }
    vec2& operator -= (vec2 const& v) { x -= v.x; y -= v.y; return *this; }
    vec2& operator -= (T s) { x -= s; y -= s; return *this; }
    vec2& operator *= (T s) { x *= s; y *= s; return *this; }
    vec2& operator *= (vec2 const& v) { x *= v.x; y *= v.y; return *this; }
    vec2& operator /= (vec2 const& v) { x /= v.x; y /= v.y; return *this; }
    vec2& operator /= (T s) { return *this *= 1.0f / s; }
    
    T operator [] (int component) const { return *(reinterpret_cast<T const*>(this) + component); }
    template<class S> operator vec2<S> () const { return vec2<S>(x, y); }

    vec2& norm() { return *this /= len(); }
    vec2& rot(float_t angle);

    T len_sq() const { return x * x + y * y; }
    float_t len() const { return hypot(x, y); }
    float_t angle() const { return atan2(y, x); }
    vec2 lhp() const { return vec2(-y, x); }
    vec2 rhp() const { return vec2(y, -x); }
    vec2 lhn() const { return lhp().norm(); }
    vec2 rhn() const { return rhp().norm(); }
    vec2<float_t> dir() const { vec2<float_t> v = *this; return v.norm(); }

    static vec2 span(vec2 const& u, vec2 const& v) { return vec2(u, v); }
    static T dot(vec2 const& u, vec2 const& v) { return u.x * v.x + u.y * v.y; }
    static T per(vec2 const& u, vec2 const& v) { return u.x * v.y - u.y * v.x; }
    static T dist_sq(vec2 const& u, vec2 const& v) { return span(u, v).len_sq(); }
    static float_t dist(vec2 const& u, vec2 const& v) { return span(u, v).len(); }

    template <class S> vec2<S> of(vec2<S> const& unx, vec2<S> const& uny) const;
    template <class S> vec2<S> in(vec2<S> const& unx, vec2<S> const& uny) const;

    bool any_nan() const { return isnan(x) || isnan(y); }
    bool any_inf() const { return isinf(x) || isinf(y); }
    bool any_broken() const { return any_nan() || any_inf(); }
    bool ok() const { return !any_broken(); }
    vec2& fix(vec2 const& fallback = 0) { return ok() ? *this : *this = fallback; }
    vec2& fix(T x, T y) { return fix(vec2(x, y)); }
};

template <class S, class T> using vec2c = vec2<common_t<S, T>>;
template <class T> constexpr vec2<T> zero2() { return vec2<T>(0, 0); }
template <class T> constexpr vec2<T> unx2() { return vec2<T>(1, 0); }
template <class T> constexpr vec2<T> uny2() { return vec2<T>(0, 1); }

template <class S, class T> inline
bool operator == (vec2<S> const& u, vec2<T> const& v) { return u.x == v.x && u.y == v.y; }

template <class S, class T> inline
bool operator != (vec2<S> const& u, vec2<T> const& v) { return u.x != v.x || u.y != v.y; }

template <class S, class T> inline
vec2c<S, T> operator + (vec2<S> const& u, vec2<T> const& v) { vec2c<S, T> c = u; return c += v;}

template <class S, class T> inline
vec2c<S, T> operator + (vec2<S> const& u, T s) { vec2c<S, T> c = u; return c += s; }

template <class S, class T>
inline vec2c<S, T> operator + (S s, vec2<T> const& u) { vec2c<S, T> c = u; return c += s; }

template <class T> inline
vec2<T> operator - (vec2<T> const& u) { return vec2<T>(-u.x, -u.y); }

template <class S, class T> inline
vec2c<S, T> operator - (vec2<S> const& u, vec2<T> const& v) { vec2c<S, T> c = u; return c -= v; }

template <class S, class T> inline
vec2c<S, T> operator - (vec2<S> const& u, T s) { vec2c<S, T> c = u; return c -= s; }

template <class S, class T> inline
vec2c<S, T> operator - (S s, vec2<T> const& u) { vec2c<S, T> c = s; return c -= u; }

template <class S, class T> inline
vec2c<S, T> operator * (vec2<S> const& u, T s) { vec2c<S, T> c = u; return c *= s; }

template <class S, class T> inline
vec2c<S, T> operator * (S s, vec2<T> const& u) { vec2c<S, T> c = u; return c *= s; }

template <class S, class T> inline
vec2c<S, T> operator * (vec2<S> const& u, vec2<T> const& v){ vec2c<S, T> c = u; return c *= v; }

template <class S, class T> inline
vec2c<S, T> operator / (vec2<S> const& u, T s) { vec2c<S, T> c = u; return c /= s; }

template <class S, class T> inline
vec2c<S, T> operator / (S s, vec2<T> const& u) { vec2c<S, T> c = s; return c /= u; }

template <class S, class T> inline
vec2c<S, T> operator / (vec2<S> const& u, vec2<T> const& v) { vec2c<S, T> c = u; return c /= v;}

template <class T> inline T len_sq(vec2<T> const& v) { return v.len_sq(); }
template <class T> inline typename vec2<T>::float_t len(vec2<T> const& v) { return v.len(); }
template <class T> inline typename vec2<T>::float_t angle(vec2<T> const& v) { return v.angle(); }
template <class T> inline vec2<T> lhp(vec2<T> const& v) { return v.lhp(); }
template <class T> inline vec2<T> rhp(vec2<T> const& v) { return v.rhp(); }
template <class T> inline vec2<T> lhn(vec2<T> const& v) { return v.lhn(); }
template <class T> inline vec2<T> rhn(vec2<T> const& v) { return v.rhn(); }
template <class T> inline vec2<T> rot(typename vec2<T>::float_t a, vec2<T> v) { return v.rot(a); }

template <class S, class T> inline
vec2c<S, T> span(vec2<S> const& u, vec2<T> const& v) { return vec2c<S, T>::span(u, v); }

template <class S, class T> inline
common_t<S, T> dot(vec2<S> const& u, vec2<T> const& v) { return vec2c<S, T>::dot(u, v); }

template <class S, class T> inline
common_t<S, T> per(vec2<S> const& u, vec2<T> const& v) { return vec2c<S, T>::per(u, v); }

template <class S, class T> inline
common_t<S, T> dist_sq(vec2<S> const& u, vec2<T> const& v) { return vec2c<S, T>::dist_sq(u, v); }

template <class S, class T> inline
typename vec2c<S, T>::float_t dist(vec2<S> const& u, vec2<T> const& v)
{
    return vec2c<S, T>::dist(u, v);
}

template <class T> inline
vec2c<T, float> dir(vec2<T> const& v) { v.dir(); }

template <class S, class T> inline
vec2c<T, float> dir(vec2<S> const& u, vec2<T> const& v) { return span(u, v).dir(); }

template <class T> inline
vec2<T> dir(T angle) { return vec2<T>(cos(angle), sin(angle)); }

template <class T> template<class S> inline
vec2<S> vec2<T>::of(vec2<S> const& unx, vec2<S> const& uny) const
{
    return (S)x * unx + (S)y * uny;
}

template <class T> template <class S> inline
vec2<S> vec2<T>::in(vec2<S> const& unx, vec2<S> const& uny) const
{
    return { dot(*this, unx), dot(*this, uny) };
}

template <class T> inline
vec2<T>& vec2<T>::rot(common_t<T, float> angle)
{
    auto s = sin(angle), c = cos(angle);
    return *this = { c * x - s * y, s * x + c * y };
}

typedef vec2<int> vec2i;
constexpr vec2i zero2i() { return zero2<int>(); }
constexpr vec2i unx2i() { return unx2<int>(); }
constexpr vec2i uny2i() { return uny2<int>(); }

typedef vec2<float> vec2f;
constexpr vec2f zero2f() { return zero2<float>(); }
constexpr vec2f unx2f() { return unx2<float>(); }
constexpr vec2f uny2f() { return uny2<float>(); }

typedef vec2<real> vec2r;
constexpr vec2r zero2r() { return zero2<real>(); }
constexpr vec2r unx2r() { return unx2<real>(); }
constexpr vec2r uny2r() { return uny2<real>(); }

} // namespace kletch

#endif // KLETCH_MATH_VEC2_H
