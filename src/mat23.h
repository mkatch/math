#ifndef JOGURT_MATH_MAT23_H
#define JOGURT_MATH_MAT23_H

#include "prefix.h"

namespace jogurt {

template <typename T>
struct mat23
{
    T a11; T a21;
    T a12; T a22;
    T a13; T a23;

    constexpr mat23() = default;

    constexpr mat23(
        T a11, T a12, T a13,
        T a21, T a22, T a23
    ) :
        a11(a11), a21(a21),
        a12(a12), a22(a22),
        a13(a13), a23(a23)
    { }

    static constexpr mat23 eye()
    {
        return mat23(
            1, 0, 0,
            0, 1, 0
        );
    }

    mat23& rotate(T s, T c)
    {
        T x = a11, y = a21;
        a11 = c * x - s * y;
        a21 = s * x + c * y;

        x = a12; y = a22;
        a12 = c * x - s * y;
        a22 = s * x + c * y;

        return *this;
    }

    mat23& rotate(T angle) { return rotate(sin(angle), cos(angle)); }

    mat23& rotate(vec2<T> const& r) { return rotate(r.y, r.x); }

    mat23& translate(T dx, T dy)
    {
        a13 += dx;
        a23 += dy;
        return *this;
    }

    mat23& translate(vec2<T> const& t) { return translate(t.x, t.y); }

    vec2<T> transform(T x, T y) const
    {
        return vec2<T>(a11 * x + a12 * y + a13, a21 * x + a22 * y + a23);
    }

    vec2<T> transform(vec2<T> const& v) const { return transform(v.x, v.y); }
};

template <class T> inline constexpr mat23<T> eye23() { return mat23<T>::eye(); }

typedef mat23<float> mat23f;
inline constexpr mat23f eye23f() { return eye23<float>(); }

typedef mat23<double> mat23d;
inline constexpr mat23d eye23d() { return eye23<double>(); }

typedef mat23<real> mat23r;
inline constexpr mat23f eye23r() { return eye23<real>(); }

} // namespace jogurt

#endif // JOGURT_MATH_MAT23_H
