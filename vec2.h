#ifndef KLETCH_MATH_VEC2_H
#define KLETCH_MATH_VEC2_H
#define KLETCH_MATH_VEC2_H_INSIDE

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

    T operator [] (int i) const { return *(reinterpret_cast<T const*>(this) + i); }
    template<class S> operator vec2<S> () const { return vec2<S>(x, y); }

    vec2& normalize() { return *this /= len(); }
    vec2 dir() const { return vec2(*this).normalize(); }
    vec2& rotate(float_t angle) { return rotate(sin(angle), cos(angle)); }
    vec2& rotate(float_t s, float_t c) { return *this = { c * x - s * y, s * x + c * y }; }
    vec2& rotate(vec2<float_t> const& rotation) { return rotate(rotation.y, rotation.x); }
    vec2 rotated(float_t angle) const { vec(*this).rotate(angle); }
    vec2 rotated(float_t s, float_t c) const { vec2(*this).rotate(s, c); }
    vec2 rotated(vec2<float_t> const& rot) const{ vec2(*this).rotate(rot); }
    T len_sq() const { return x * x + y * y; }
    float_t len() const { return hypot(x, y); }
    float_t angle() const { return atan2(y, x); }
    vec2 lhp() const { return vec2(-y, x); }
    vec2 rhp() const { return vec2(y, -x); }
    vec2 lhn() const { return lhp().normalize(); }
    vec2 rhn() const { return rhp().normalize(); }

    static vec2 span(vec2 const& u, vec2 const& v) { return vec2(u, v); }
    static vec2<float_t> dir(vec2 const& v) { return vec2<float_t>(v).dir(); }
    static vec2<float_t> dir(vec2 const& u, vec2 const& v) { return vec2<float_t>(u, v).dir(); }
    static vec2 dir(float_t angle) { return vec2(cos(angle), sin(angle)); }
    static vec2<float_t> rotate(vec2 const& v, float_t angle);
    static vec2<float_t> rotate(vec2 const& v, float_t s, float_t c);
    static vec2<float_t> rotate(vec2 const& v, vec2<float_t> const& rot);
    static T dot(vec2 const& u, vec2 const& v) { return u.x * v.x + u.y * v.y; }
    static T per(vec2 const& u, vec2 const& v) { return u.x * v.y - u.y * v.x; }
    static T dist_sq(vec2 const& u, vec2 const& v) { return span(u, v).len_sq(); }
    static float_t dist(vec2 const& u, vec2 const& v) { return span(u, v).len(); }
    static vec2 mid(vec2 const& u, vec2 const& v) { return T(0.5) * (u + v); }

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
template <class T> using vec2_float_t = typename vec2<T>::float_t;
template <class S, class T> using vec2c_float_t = typename vec2c<S, T>::float_t;
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

template <class S, class T> inline
vec2c<S, T> span(vec2<S> const& u, vec2<T> const& v) { return vec2c<S, T>::span(u, v); }

template <class T> inline
vec2<vec2_float_t<T>> dir(vec2<T> const& v) { return vec2<vec2_float_t<T>>::dir(v); }

template <class S, class T> inline
vec2<vec2c_float_t<S, T>> dir(vec2<S> const& u, vec2<T> const& v)
{
    return vec2<vec2c_float_t<S, T>>::dir(u, v);
}

template <class T> inline
vec2<vec2_float_t<T>> dir(T angle) { return vec2<vec2_float_t<T>>::dir(angle); }

template <class T> inline
vec2<vec2_float_t<T>> vec2<T>::rotate(vec2<T> const& v, vec2_float_t<T> angle)
{
     return vec2<vec2_float_t<T>>(v).rotate(angle);
}

template <class T> inline
vec2<vec2_float_t<T>> vec2<T>::rotate(vec2<T> const& v, vec2_float_t<T> s, vec2_float_t<T> c)
{
     return vec2<vec2_float_t<T>>(v).rotate(s, c);
}

template <class T> inline
vec2<vec2_float_t<T>> vec2<T>::rotate(vec2<T> const& v, vec2<vec2_float_t<T>> const& rot)
{
     return vec2<vec2_float_t<T>>(v).rotate(rot);
}

template <class S, class T> inline
vec2<vec2c_float_t<S, T>> rotate(vec2<S> const& u, T angle)
{
    return vec2<vec2c_float_t<S, T>>::rotate(u, angle);
}

template <class S, class T> inline
vec2<vec2c_float_t<S, T>> rotate(vec2<S> const& u, T s, T c)
{
    return vec2<vec2c_float_t<S, T>>::rotate(u, s, c);
}

template <class S, class T> inline
vec2<vec2c_float_t<S, T>> rotate(vec2<S> const& u, vec2<T> const& rot)
{
    return vec2<vec2c_float_t<S, T>>::rotate(u, rot);
}

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

template <class S, class T> inline
vec2c<S, T> mid(vec2<S> const& u, vec2<T> const& v) { return vec2c<S, T>::mid(u, v); }

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

#ifdef KLETCH_MATH_FUZZY_H
#   include "fuzzy_vec2.h"
#endif

#undef KLETCH_MATH_VEC2_H_INSIDE
#endif // KLETCH_MATH_VEC2_H
