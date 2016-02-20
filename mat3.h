#ifndef KLETCH_MATH_MAT3_H
#define KLETCH_MATH_MAT3_H

#include "prefix.h"

#include "vec2.h"

namespace kletch {

template <typename T>
struct mat3
{
    static const mat3 EYE;

    static mat3 create_scale(T sx, T sy)
    {
        mat3 m = EYE;
        return m.scale(sx, sy);
    }

    T a11; T a21; T a31;
    T a12; T a22; T a32;
    T a13; T a23; T a33;

    mat3() = default;

    mat3(
        T a11, T a12, T a13,
        T a21, T a22, T a23,
        T a31, T a32, T a33
    ) :
        a11(a11), a21(a21), a31(a31),
        a12(a12), a22(a22), a32(a32),
        a13(a13), a23(a23), a33(a33)
    { }

    mat3& scale(T sx, T sy)
    {
        a11 *= sx; a12 *= sx; a13 *= sx;
        a21 *= sy; a22 *= sy; a23 *= sy;
        return *this;
    }

    mat3& scale(const vec2<T>& s) { return scale(s.x, s.y); }

    mat3& translate(T tx, T ty)
    {
        a11 += a31 * tx; a12 += a32 * tx; a13 += a33 * tx;
        a21 += a31 * ty; a22 += a32 * ty; a23 += a33 * ty;
        return *this;
    }

    mat3& translate(const vec2<T>& t) { return translate(t.x, t.y); }

    mat3& rotate(T angle)
    {
        T c = cos(angle); T s = sin(angle);

        T x = a11, y = a21;
        a11 = c * x - s * y;
        a21 = s * x + c * y;

        x = a12; y = a22;
        a12 = c * x - s * y;
        a22 = s * x + c * y;

        x = a13; y = a23;
        a13 = c * x - s * y;
        a23 = s * x + c * y;

        return *this;
    }

    vec2<T> translation() const { return vec2<T>(a13 / a33, a23 / a33); }

    mat3& pre_mul(const mat3<T>& m)
    {
        T x = a11, y = a21, z = a31;
        a11 = m.a11 * x + m.a21 * y + m.a31 * z;
        a21 = m.a21 * x + m.a22 * y + m.a32 * z;
        a31 = m.a31 * x + m.a32 * y + m.a33 * z;

        x = a12; y = a22; z = a32;
        a12 = m.a11 * x + m.a21 * y + m.a31 * z;
        a22 = m.a21 * x + m.a22 * y + m.a32 * z;
        a32 = m.a31 * x + m.a32 * y + m.a33 * z;

        x = a13; y = a23; z = a33;
        a13 = m.a11 * x + m.a21 * y + m.a31 * z;
        a23 = m.a21 * x + m.a22 * y + m.a32 * z;
        a33 = m.a31 * x + m.a32 * y + m.a33 * z;

        return *this;
    }

    vec2<T> transform(T x, T y) const
    {
        return vec2<T>(
            a11 * x + a12 * y + a13,
            a21 * x + a22 * y + a23
        ) / a31 * x + a32 * y + a33;
    }

    vec2<T> transform(const vec2<T>& v) const { return transform(v.x, v.y); }

    vec2<T> transform_vector(T x, T y) const
    {
        return vec2<T>(
            a11 * x + a12 * y,
            a21 * x + a22 * y
        );
    }

    vec2<T> transform_vector(const vec2<T>& v) const { return transform_vector(v.x, v.y); }
};

typedef mat3<float> mat3f;
typedef mat3<double> mat3d;
typedef mat3<real> mat3r;

template <typename T>
const mat3<T> mat3<T>::EYE = mat3<T>(
    1, 0, 0,
    0, 1, 0,
    0, 0, 1
);

template <typename T>
mat3<T> operator * (const mat3<T>& m1, mat3<T> m2)
{
    return m2.pre_mul(m1);
}

template <typename T>
std::ostream& operator << (std::ostream& out, const mat3<T>& m)
{
    out << '(';
    out << m.a11 << ' ' << m.a12 << ' ' << m.a13 << "; ";
    out << m.a21 << ' ' << m.a22 << ' ' << m.a23 << "; ";
    out << m.a31 << ' ' << m.a32 << ' ' << m.a33;
    return out << ')';
}

} // namespace kletch

#endif // KLETCH_MATH_MAT3_H
