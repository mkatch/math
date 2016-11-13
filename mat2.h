#ifndef KLETCH_MATH_MAT2_H
#define KLETCH_MATH_MAT2_H

#include "prefix.h"
#include "vec2.h"

namespace kletch {

template <typename T>
struct mat2
{
    T a11; T a21;
    T a12; T a22;

    static constexpr mat2 eye()
    {
        return mat2(
            1, 0,
            0, 1);
    }

    mat2() = default;

    constexpr mat2(
        T a11, T a12,
        T a21, T a22
    ) :
        a11(a11), a21(a21),
        a12(a12), a22(a22)
    { }

    T det()
    {
        return a11 * a22 - a12 * a21;
    }

    mat2& invert()
    {
        swap(a11, a22);
        a12 = -a12;
        a21 = -a21;
        return operator /= (det());
    }

    mat2& pre_mul(const mat2& m)
    {
        T x = a11, y = a21;
        a11 = m.a11 * x + m.a12 * y;
        a21 = m.a21 * x + m.a22 * y;

        x = a12, y = a22;
        a12 = m.a11 * x + m.a12 * y;
        a22 = m.a21 * x + m.a22 * y;

        return *this;
    }

    mat2& rotate(T s, T c)
    {
        T x = a11, y = a21;
        a11 = c * x - s * y;
        a21 = s * x + c * y;

        x = a12; y = a22;
        a12 = c * x - s * y;
        a22 = s * x + c * y;

        return *this;
    }

    mat2& rotate(T angle) { return rotate(sin(angle), cos(angle)); }

    mat2& rotate(vec2<T> const& r) { return rotate(r.x, r.y); }

    vec2<T> transform(const vec2<T>& v) const { return transform(v.x, v.y); }

    vec2<T> transform(T x, T y) const
    {
        return vec2<T>(
            a11 * x + a12 * y,
            a21 * x + a22 * y
        );
    }

    mat2& operator /= (T s)
    {
        a11 /= s;
        a21 /= s;
        a12 /= s;
        a22 /= s;
        return *this;
    }
};

typedef mat2<float> mat2f;
constexpr mat2f eye2f() { return mat2f::eye(); }

typedef mat2<double> mat2d;
constexpr mat2d eye2d() { return mat2d::eye(); }

typedef mat2<real> mat2r;
constexpr mat2r eye2r() { return mat2r::eye(); }

template <typename T>
inline mat2<T> operator * (const mat2<T>& m1, mat2<T> m2)
{
    return m2.pre_mul(m1);
}

} // namespace kletch

#endif // KLETCH_MATH_MAT2_H
